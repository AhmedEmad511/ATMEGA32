/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TIMER               ***********************/
/*********************************************************************************/
/*********************************************************************************/
#include "TIMER_interface.h"

static void (*TIMER0_COMPCallBack)(void) = NULL;
static void (*TIMER0_OVFCallBack)(void)=NULL;
static void (*ICU_CallBack)(void) = NULL;
static u8 Mode=0;
static u8 Init_F=NOT_INITIALIZED;
static u16 Copy_u8Time=0;
static u8 Period=0;

void DELAY_NonBlockHelper(void)
{
	static u16 counter_ms=0;
	static u8 counter_us=0;
	counter_us++;
	if(Period==PERIODIC)
	{
		if(counter_us==4)
		{
			counter_ms++;
			counter_us=0;
		}
		if(counter_ms==Copy_u8Time)
		{
			TIMER0_COMPCallBack();
			counter_ms=0;
		}
	}
	else if (Period==NON_PERIODIC)
	{
		if(counter_us==4)
		{
			counter_ms++;
			counter_us=0;
		}
		if(counter_ms==Copy_u8Time)
		{
			TIMER0_COMPCallBack();
			counter_ms=0;
			TIMER0_COMPIntE(DISABLE);
		}
	}
}

void TIMER0_voidINIT(u8 Copy_u8Mode,u8 Copy_u8Prescaler)
{
	Mode=Copy_u8Mode;
	/*Select TIMER0 Mode
	 * ->Normal
	 * ->PWM
	 * ->CTC
	 * ->Fast_PWM */
	switch(Copy_u8Mode)
	{
	case NORMAL :
		CLR_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		break;
	case PWM :
		SET_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		break;
	case CTC :
		CLR_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		break;
	case FAST_PWM :
		SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		break;
	default:
		break;
	}
	/*Select Prescaler
	 * ->NO_CLOCK
	 * ->DIV_1
	 * ->DIV_8
	 * ->DIV_64
	 * ->DIV_256
	 * ->DIV_1024
	 * ->EXT_T0_FALLING
	 * ->EXT_T0_RISING*/
	switch(Copy_u8Prescaler)
	{
	case NO_CLOCK :
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;
	case DIV_1 :
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;
	case DIV_8 :
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;
	case DIV_64 :
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;
	case DIV_256 :
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;
	case DIV_1024 :
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;
	case EXT_T0_FALLING :
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;
	case EXT_T0_RISING :
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;
	default:
		break;
	}
}


void TIMER0_SetCOMPValue(u8 Value)
{
	OCR0=Value;
}

void TIMER0_SetOutMode(u8 Copy_u8OutMode)
{
	/*Copy_Mode ranges from 1-->4*/
	switch (Mode)
	{
	case NORMAL :
		/* 1-OC0 disconnected
		 * 2-Toggle OC0 on Compare
		 * 3-Clear OC0 on Compare
		 * 4-Set OC0 on Compare*/
		switch(Copy_u8OutMode)
		{
		case DISC:
			CLR_BIT(TCCR0,TCCR0_COM00);
			CLR_BIT(TCCR0,TCCR0_COM01);
			break;
		case TOGGLE:
			SET_BIT(TCCR0,TCCR0_COM00);
			CLR_BIT(TCCR0,TCCR0_COM01);
			break;
		case CLEAR:
			CLR_BIT(TCCR0,TCCR0_COM00);
			SET_BIT(TCCR0,TCCR0_COM01);
			break;
		case SET:
			SET_BIT(TCCR0,TCCR0_COM00);
			SET_BIT(TCCR0,TCCR0_COM01);
			break;
		default:
			break;
		}
		break;
		case PWM :
			/* 1-OC0 DISCONNECTED
			 * 2-RESERVED
			 * 3-Clear OC0 on compare when UP-Counting && Set OC0 on compare when DOWN-COUNTING
			 * 4-Set OC0 on compare when UP-Counting && Clear OC0 on compare when DOWN-COUNTING*/
			switch(Copy_u8OutMode)
			{
			case PWM_DISC :
				CLR_BIT(TCCR0,TCCR0_COM00);
				CLR_BIT(TCCR0,TCCR0_COM01);
				break;
			case PWM_CLR_UP :
				CLR_BIT(TCCR0,TCCR0_COM00);
				SET_BIT(TCCR0,TCCR0_COM01);
				break;
			case PWM_SET_UP :
				SET_BIT(TCCR0,TCCR0_COM00);
				SET_BIT(TCCR0,TCCR0_COM01);
				break;
			default:
				break;
			}
			break;
			case FAST_PWM :
				/* 1-OC0 DISCONNECTED
				 * 2-RESERVED
				 * 3-Clear on compare && Set on Top
				 * 4-Set on Compare && clear on Top*/
				switch(Copy_u8OutMode)
				{
				case FAST_PWM_DISC :
					CLR_BIT(TCCR0,TCCR0_COM00);
					CLR_BIT(TCCR0,TCCR0_COM01);
					break;
				case FAST_PWM_CLR_COMP :
					CLR_BIT(TCCR0,TCCR0_COM00);
					SET_BIT(TCCR0,TCCR0_COM01);
					break;
				case FAST_PWM_SET_COMP :
					SET_BIT(TCCR0,TCCR0_COM00);
					SET_BIT(TCCR0,TCCR0_COM01);
					break;
				default:
					break;
				}
				break;
				default:
					break;
	}

}

void TIMER0_COMPIntE(u8 Copy_u8Enable)
{
	switch (Copy_u8Enable)
	{
	case ENABLE :
		SET_BIT(TIMSK,TIMSK_OCIE0);
		break;
	case DISABLE :
		CLR_BIT(TIMSK,TIMSK_OCIE0);
		break;
	default:
		break;
	}
}

void TIMER0_OVFIntE(u8 Copy_u8Enable)
{
	switch (Copy_u8Enable)
	{
	case ENABLE :
		SET_BIT(TIMSK,TIMSK_TOIE0);
		break;
	case DISABLE :
		CLR_BIT(TIMSK,TIMSK_TOIE0);
		break;
	default:
		break;
	}
}

u8 TIMER0_u8COMPCallBackFunc(void(*pvNotfication)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(pvNotfication!=NULL)
	{
		TIMER0_COMPCallBack = pvNotfication;
	}
	else
	{
		Local_u8ErrorStatus = P_NULL;
	}
	return Local_u8ErrorStatus;
}

u8 TIMER0_u8OVFCallBackFunc(void(*pvNotfication)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(pvNotfication!=NULL)
	{
		TIMER0_OVFCallBack = pvNotfication;
	}
	else
	{
		Local_u8ErrorStatus = P_NULL;
	}
	return Local_u8ErrorStatus;
}


void DELYA_voidNonBlockDelay(u16 Copy_ms, void(*pvFunc)(void) ,u8 Copy_u8Periodic)
{
	if(Init_F==NOT_INITIALIZED)
	{
		TIMER0_voidINIT(CTC,DIV_8);

		/*Set Comp value to 250 us*/
		TIMER0_SetCOMPValue(250);

		/*Enable COMP INT*/
		TIMER0_COMPIntE(ENABLE);

		Period=Copy_u8Periodic;
		Copy_u8Time=Copy_ms;
		TIMER0_COMPCallBack=pvFunc;

		Init_F=INITIALIZED;
	}
	TIMER0_u8COMPCallBackFunc(&DELAY_NonBlockHelper);
}

void TIMER1_voidInit(void)
{
	/*Set fast PWM mode to clear on COMP set on TOP
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);*/


	/*Select NORMAL mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*Set Prescaler DIV by 8*/
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}


void TIMER1_TopValue(u16 Value)
{
	ICR1=Value;
}

void TIMER1_channelACOMPValue(u16 Value)
{
	OCR1A=Value;
}

void TIMER1_SetChannelReading(u16 Value)
{
	TCNT1=Value;
}

u16 TIMER1_ReadChannelReading(void)
{
	return TCNT1;
}

void ICU_voidInit(void)
{
	/*Set Input Capture Edge Select to Rising Edge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	/*Enable Input Capture Interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}


void ICU_voidSetEdge(u8 Edge)
{
	switch(Edge)
	{
	case FALLING :
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
		break;
	case RISING :
		SET_BIT(TCCR1B,TCCR1B_ICES1);
		break;
	default:
		break;
	}
}

void ICU_voidInterrupt(u8 EN)
{
	switch(EN)
	{
	case ENABLE :
		SET_BIT(TIMSK,TIMSK_TICIE1);
		break;
	case DISABLE:
		CLR_BIT(TIMSK,TIMSK_TICIE1);
	}
}


u16 ICU_ReadChannelReading(void)
{
	return ICR1;
}


u8 ICU_voidSetCallBack(void (*pvCallBack)(void))
{
	u8 Local_u8ICUErrorState=0;
	if(pvCallBack!=NULL)
	{
		ICU_CallBack=pvCallBack;
	}
	else
	{
		Local_u8ICUErrorState = P_NULL;
	}
	return Local_u8ICUErrorState;
}

void WDT_voidSleep(u8 Value)
{
	SET_BIT(WDTCR,WDTCR_WDE);
	/*Select from 0 to 7
	 * 0	 For 16.3 ms
	 * 1	 For 32.5ms
	 * 2	 For 65ms
	 * 3 	 For 0.13sec
	 * 4	 For 0.26sec
	 * 5 	 For 0.52sec
	 * 6 	 For 1sec
	 * 7	 For 2.1sec */
	switch(Value)
	{
	case 0:
		CLR_BIT(WDTCR,WDTCR_WDP0);
		CLR_BIT(WDTCR,WDTCR_WDP1);
		CLR_BIT(WDTCR,WDTCR_WDP2);
		break;
	case 1:
		SET_BIT(WDTCR,WDTCR_WDP0);
		CLR_BIT(WDTCR,WDTCR_WDP1);
		CLR_BIT(WDTCR,WDTCR_WDP2);
		break;
	case 2:
		CLR_BIT(WDTCR,WDTCR_WDP0);
		SET_BIT(WDTCR,WDTCR_WDP1);
		CLR_BIT(WDTCR,WDTCR_WDP2);
		break;
	case 3:
		SET_BIT(WDTCR,WDTCR_WDP0);
		SET_BIT(WDTCR,WDTCR_WDP1);
		CLR_BIT(WDTCR,WDTCR_WDP2);
		break;
	case 4:
		CLR_BIT(WDTCR,WDTCR_WDP0);
		CLR_BIT(WDTCR,WDTCR_WDP1);
		SET_BIT(WDTCR,WDTCR_WDP2);
		break;
	case 5:
		SET_BIT(WDTCR,WDTCR_WDP0);
		CLR_BIT(WDTCR,WDTCR_WDP1);
		SET_BIT(WDTCR,WDTCR_WDP2);
		break;
	case 6:
		CLR_BIT(WDTCR,WDTCR_WDP0);
		SET_BIT(WDTCR,WDTCR_WDP1);
		SET_BIT(WDTCR,WDTCR_WDP2);
		break;
	case 7:
		SET_BIT(WDTCR,WDTCR_WDP0);
		SET_BIT(WDTCR,WDTCR_WDP1);
		SET_BIT(WDTCR,WDTCR_WDP2);
		break;

	}
}

void WDT_voidDisable(void)
{
	WDTCR=0b00011000;
	WDTCR=0;
}



void __vector_10(void)      __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_COMPCallBack!=NULL)
	{
		TIMER0_COMPCallBack();
	}
}

void __vector_11(void)      __attribute__((signal));
void __vector_11(void)
{
	if(TIMER0_OVFCallBack!=NULL)
	{
		TIMER0_OVFCallBack();
	}
}


void __vector_6(void)		__attribute__((signal));
void __vector_6(void)
{
	if(ICU_CallBack != NULL)
	{
		ICU_CallBack();
	}
}
