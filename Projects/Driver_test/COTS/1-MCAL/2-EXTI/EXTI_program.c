/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : EXTI                ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "EXTI_interface.h"

void (*Int0Function)(void)= NULL ;
void (*Int1Function)(void)= NULL ;
void (*Int2Function)(void)= NULL ;

void EXTI_voidINT0Init(void)
{
	/*Set sense control for INT0*/
	/*for falling edge ISC00 =0 , ISC01=1
	 *for low level    ISC00 =0 , ISC01=0
	 *for any change   ISC00 =1 , ISC01=0
	 *for rising edge  ISC00 =1 , ISC01=1*/


#if INT0_SENSE == FALLING_EDGE


	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);


#elif INT0_SENSE == RISING_EDGE


	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);


#elif INT0_SENSE == ON_CHANGE


	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);


#elif INT0_SENSE == LOW_LEVEL


	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#else

#error "Wrong INT0_SENSE configuration option"
#endif

#if INT0_INITIAL == ENABLE
	SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL == DISABLE

	CLR_BIT(GICR,GICR_INT0);

#else

#error "Wrong INT0_INITIAL option"

#endif
}
void EXTI_voidINT1Init(void)
{
	/*Set sense control for INT0*/
	/*for falling edge ISC10=0 , ISC11=1
	 *for low level    ISC10=0 , ISC11=0
	 *for any change   ISC10=1 , ISC11=0
	 *for rising edge  ISC10=1 , ISC11=1*/
#if INT1_SENSE == FALLING_EDGE


	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);


#elif INT1_SENSE == RISING_EDGE


	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);


#elif INT1_SENSE == ON_CHANGE


	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);


#elif INT1_SENSE == LOW_LEVEL


	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#else

#error "Wrong INT1_SENSE configuration option"

#endif

#if INT1_INITIAL == ENABLE
	SET_BIT(GICR,GICR_INT1);

#elif INT1_INITIAL == DISABLE

	CLR_BIT(GICR,GICR_INT1);

#else

#error "Wrong INT1_INITIAL option"

#endif
}
void EXTI_voidINT2Init(void)
{
	/*Set sense control for INT0*/
	/*for falling edge write 0 && for rising edge write 1*/
#if INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_INT2);

#elif INT2_SENSE ==RISING_EDGE

	SET_BIT(MCUCSR,MCUCSR_INT2);
#else
#error "Wrong INT2_SENSE OPTION"
#endif
#if INT2_INITIAL == ENABLE
	SET_BIT(GICR,GICR_INT2);

#elif INT2_INITIAL == DISABLE

	CLR_BIT(GICR,GICR_INT2);

#else

#error "Wrong INT2_INITIAL option"

#endif
}

u8 EXTI_u8IntSetSenseControl(u8 Copy_u8INT,u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = 0 ;
	if(Copy_u8INT==INT0)
	{
		switch(Copy_u8Sense)
		{
		case LOW_LEVEL :
			CLR_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);
			break;

		case ON_CHANGE :
			CLR_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;

		case RISING_EDGE :
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;

		case FALLING_EDGE :
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);
			break;

		default:
			Local_u8ErrorState = 1;
			break;
		}
	}
	else if(Copy_u8INT==INT1)
	{
		switch(Copy_u8Sense)
		{
		case LOW_LEVEL :
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
			break;

		case ON_CHANGE :
			CLR_BIT(MCUCR,MCUCR_ISC11);
			SET_BIT(MCUCR,MCUCR_ISC10);
			break;

		case RISING_EDGE :
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;

		case FALLING_EDGE :
			SET_BIT(MCUCR,MCUCR_ISC11);
			CLR_BIT(MCUCR,MCUCR_ISC10);
			break;

		default:
			Local_u8ErrorState = 1;
			break;
		}


	}
	else if(Copy_u8INT==INT2)
	{
		switch(Copy_u8Sense)
		{
		case RISING_EDGE :
			SET_BIT(MCUCSR,MCUCSR_INT2);
			break;

		case FALLING_EDGE :
			CLR_BIT(MCUCSR,MCUCSR_INT2);
			break;

		default:
			Local_u8ErrorState = 1;
			break;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8INT,u8 Copy_u8E)
{
	u8 Local_u8ErrorState=0;

	if(Copy_u8INT==INT0)
	{
		switch(Copy_u8E)
		{
		case ENABLE : SET_BIT(GICR,GICR_INT0);
		break;
		case DISABLE: CLR_BIT(GICR,GICR_INT0);
		break;
		default :     Local_u8ErrorState=1;
		break;
		}
	}


	else if(Copy_u8INT==INT1)
	{
		switch(Copy_u8E)
		{
		case ENABLE : SET_BIT(GICR,GICR_INT1);
		break;
		case DISABLE: CLR_BIT(GICR,GICR_INT1);
		break;
		default : Local_u8ErrorState=1;
		break;
		}
	}


	else if(Copy_u8INT==INT2)
	{
		switch(Copy_u8E)
		{
		case ENABLE : SET_BIT(GICR,GICR_INT2);
		break;
		case DISABLE: CLR_BIT(GICR,GICR_INT2);
		break;
		default :     Local_u8ErrorState=1;
		break;
		}
	}

	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int0ISR(void (*Int0ISR) (void))
{
	u8 Local_u8ErrorStatus =0;

	if(Int0ISR != NULL)
	{
		Int0Function=Int0ISR;

	}
	else
	{
		Local_u8ErrorStatus = 2;
	}
	return Local_u8ErrorStatus;
}
u8 EXTI_u8Int1ISR(void (*Int1ISR) (void))
{
	{
		u8 Local_u8ErrorStatus =0;

		if(Int1ISR != NULL)
		{
			Int1Function=Int1ISR;

		}
		else
		{
			Local_u8ErrorStatus = 2;
		}
		return Local_u8ErrorStatus;
	}


}
u8 EXTI_u8Int2ISR(void (*Int2ISR) (void))
{
	{
		u8 Local_u8ErrorStatus =0;

		if(Int2ISR != NULL)
		{
			Int2Function=Int2ISR;

		}
		else
		{
			Local_u8ErrorStatus = 2;
		}
		return Local_u8ErrorStatus;
	}


}


void __vector_1(void)     __attribute__((signal));
void __vector_1(void)
{
	if(Int0Function!= NULL)
	{
		Int0Function();
	}
	else
	{
		/*DO NOTHING*/
	}
}

void __vector_2(void)     __attribute__((signal));
void __vector_2(void)
{
	if(Int1Function!=NULL)
	{
		Int1Function();
	}
	else
	{
		/*DO NOTHING*/
	}
}

void __vector_3(void)     __attribute__((signal));
void __vector_3(void)
{
	if(Int2Function!=NULL)
	{
		Int2Function();
	}
	else
	{
		/*DO NOTHING*/
	}
}
