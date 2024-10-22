/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : RTOS                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TIMER0              ***********************/
/*********************************************************************************/
/*********************************************************************************/
#include "TIMER_interface.h"

static void (*TIMER0_COMPCallBack)(void) = NULL;

void TIMER0_voidINIT(void)
{

	//CTC Mode
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	//DIV_64
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

	//Set COMP value
	OCR0= 125;

	//Enable INT
	SET_BIT(TIMSK,TIMSK_OCIE0);
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




void __vector_10(void)      __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_COMPCallBack!=NULL)
	{
		TIMER0_COMPCallBack();
	}
}


