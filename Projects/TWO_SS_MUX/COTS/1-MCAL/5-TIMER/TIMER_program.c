/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TIMER               ***********************/
/*********************************************************************************/
/*********************************************************************************/
#include "TIMER_interface.h"

static void (*TIMER0_CallBack)(void) = NULL;


void TIMER0_voidINIT(void)
{
	/*Select CTC mode*/
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

	/*Enable INT*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*SET compare match value*/

	OCR0=250;

	/*Prescaler DIV by 8*/
	CLR_BIT(TCCR0,TCCR0_CS02);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS00);

}

u8 TIMER0_u8SetCallBackFunc(void(*pvNotfication)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(pvNotfication!=NULL)
	{
	 TIMER0_CallBack = pvNotfication;
	}
	else
	{
		Local_u8ErrorStatus = P_NULL;
	}
    return Local_u8ErrorStatus;
}

void __vector_10(void)      __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_CallBack!=NULL)
	{
		static u16 counter =0;
		counter++;
		if(counter==4000)
		{
			TIMER0_CallBack();
			counter=0;
		}
	}

}
