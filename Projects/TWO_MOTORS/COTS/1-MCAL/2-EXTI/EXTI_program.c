/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : EXTI                ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "EXTI_interface.h"

void EXTI_voidINT0Init(void)
{
	/*Set sense control for INT0*/
	/*for falling edge ISC00 =0 , ISC01=1
	 *for low level    ISC00 =0 , ISC01=0
	 *for any change   ISC00 =1 , ISC01=0
	 *for rising edge  ISC00 =1 , ISC01=1*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);
}
void EXTI_voidINT1Init(void)
{
	/*Set sense control for INT0*/
	/*for falling edge ISC10=0 , ISC11=1
	 *for low level    ISC10=0 , ISC11=0
	 *for any change   ISC10=1 , ISC11=0
	 *for rising edge  ISC10=1 , ISC11=1*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
	/*Peripheral interrupt enable for INT1*/
	SET_BIT(GICR,GICR_INT1);

}

void EXTI_voidINT2Init(void)
{
	/*Set sense control for INT0*/
	/*for falling edge write 0 && for rising edge write 1*/
	CLR_BIT(MCUCSR,MCUCSR_INT2);
	/*Peripheral interrupt enable for INT2*/
	SET_BIT(GICR,GICR_INT2);

}
