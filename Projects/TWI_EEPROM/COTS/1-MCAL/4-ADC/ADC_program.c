/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : ADC                 ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include"ADC_interface.h"

static u8* ADC_pu8Reading= NULL;
static void(*ADC_pvCallBack)(void)=NULL;
u16 Local_ADCReading;
u8 Local_u8BusyState = IDLE;
static u8* ADC_pu8ChainCannelArr = NULL;
static u16*ADC_pu16ChainResultArr=NULL;
static u8 ADC_u8ChainSize;
static u8 ADC_u8CahinIndex;
static u8 ADC_u8ISRSource;
static u8 SingleChannelAsync=0;
static u8 ChainChannel=1;
void ADC_voidInit(void)
{
	/*AVCC as reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#if ADC_ADJUST == ENABLE
	/*ACTIVATE left adjust to 1*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

#elif ADC_ADJUST == DISABLE
	CLR_BIT(ADMUX,ADMUX_ADLAR);

#endif

	/*Set Prescaler Bits*/
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_PRESC ;

	/*Enable ADC */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartConversionSync(u8 Copy_u8Channel,u8* Copy_pu8Reading)
{
	u8 Local_ErrorState=OK;
	if(Local_u8BusyState==IDLE)
	{
		Local_u8BusyState = BUSY;
		u32 Local_u32Counter=0;
		/*Clear MUX bits*/
		ADMUX &= 0b11100000;

		/*Set Channel on MUX*/
		ADMUX |= Copy_u8Channel;

		/*Start Conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*Polling (busy waiting) until the conversion complete flag is set*/
		while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0) && (Local_u32Counter != ADC_u32TIMEOUT))
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter==ADC_u32TIMEOUT)
		{
			//TIMEOUT
			Local_ErrorState=NOK;
		}

		else
		{
			/*Clear conversion Flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);
#if ADC_ADJUST==ENABLE
			/*Return The value*/
			*Copy_pu8Reading = ADCH;
#elif ADC_ADJUST==DISABLE

			Local_ADCReading = (ADCL|(ADCH<<8));
			*Copy_pu8Reading=Local_ADCReading;

#endif
			Local_u8BusyState = IDLE;
		}
	}
	else
	{
		Local_ErrorState= BUSY_ERROR;
	}
	return Local_ErrorState;
}

u8 ADC_u8StartConversionAsync(u8 Copy_u8Channel,u8* Copy_pu8Reading ,void(*Copy_pvNot)(void))
{
	u8 Local_ErrorState =OK;
	if(Local_u8BusyState==IDLE)
	{
		if((Copy_pvNot==NULL) || (Copy_pu8Reading ==NULL))
		{
			Local_ErrorState=NOK;
		}
		else
		{

			Local_u8BusyState = BUSY;

			ADC_u8ISRSource=SingleChannelAsync;

			ADC_pvCallBack=Copy_pvNot;

			ADC_pu8Reading=Copy_pu8Reading;

			/*Clear MUX bits*/
			ADMUX &= 0b11100000;

			/*Set Channel on MUX*/
			ADMUX |= Copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable ADC INT*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
	}
	else
	{
		Local_ErrorState =BUSY_ERROR;
	}
	return Local_ErrorState;
}


u8 ADC_u8StartChainConversion(Chain_t* Copy_Chain)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_Chain==NULL)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		if(Local_u8BusyState==IDLE)
		{


			Local_u8BusyState=BUSY;

			ADC_u8ISRSource=ChainChannel;

			ADC_pu8ChainCannelArr=Copy_Chain->Channel;
			ADC_pu16ChainResultArr=Copy_Chain->Result;
			ADC_u8ChainSize=Copy_Chain->Size;
			ADC_pvCallBack=Copy_Chain->NotficationFunc;
			ADC_u8CahinIndex=0;

			/*Set Required Channel*/
			ADMUX &=0b11100000;
			ADMUX |=ADC_pu8ChainCannelArr[ADC_u8CahinIndex];

			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable INT*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState=BUSY_ERROR;
		}
	}
	return Local_u8ErrorState;
}


void __vector_16 (void) 	__attribute__((signal));
void __vector_16 (void)
{
	if(ADC_u8ISRSource==SingleChannelAsync)
	{
		/*Read ADC result*/
#if ADC_ADJUST == ENABLE
		*ADC_pu8Reading =ADCH;
#elif ADC_ADJUST==DISABLE

		Local_ADCReading = (ADCL|(ADCH<<8));
		*ADC_pu8Reading=Local_ADCReading;

#endif

		Local_u8BusyState=IDLE;

		/*Call Back Notification FUNC*/
		ADC_pvCallBack();

		/*Disable ADC INT*/
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8ISRSource==ChainChannel)
	{
#if ADC_ADJUST == ENABLE
		/*Read The current conversion*/
		ADC_pu16ChainResultArr[ADC_u8CahinIndex]= ADCH;

		/*Increment Index*/
		ADC_u8CahinIndex++;

		/*Check Size*/
		if(ADC_u8CahinIndex==ADC_u8ChainSize)
		{
			/*Chain is Done*/
			/*Raise IDLE Flag*/
			Local_u8BusyState=IDLE;

			/*Excute NotificationFunc*/
			ADC_pvCallBack();

			/*Disable INT*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			/*Chain is not Finished*/
			ADMUX &=0b11100000;
			ADMUX |=ADC_pu8ChainCannelArr[ADC_u8CahinIndex];

			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
#elif ADC_ADJUST==DISABLE
		/*Read The current conversion*/
		Local_ADCReading = (ADCL|(ADCH<<8));
		ADC_pu16ChainResultArr[ADC_u8CahinIndex]= Local_ADCReading;

		/*Increment Index*/
		ADC_u8CahinIndex++;

		/*Check Size*/
		if(ADC_u8CahinIndex==ADC_u8ChainSize)
		{
			/*Chain is Done*/
			/*Raise IDLE Flag*/
			Local_u8BusyState=IDLE;

			/*Excute NotificationFunc*/
			ADC_pvCallBack();

			/*Disable INT*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			/*Chain is not Finished*/
			ADMUX &=0b11100000;
			ADMUX |=ADC_pu8ChainCannelArr[ADC_u8CahinIndex];

			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
#endif
	}
}
