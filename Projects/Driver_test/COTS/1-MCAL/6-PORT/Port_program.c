/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : PORT                ***********************/
/*********************************************************************************/
/*********************************************************************************/
#include "Port_interface.h"

void PORT_voidInit(void)
{
	DDRA = PORTA_DIR ;
	DDRB = PORTB_DIR ;
	DDRC = PORTC_DIR ;
	DDRD = PORTD_DIR ;

	PORTA = PORTA_INT;
	PORTB = PORTB_INT;
	PORTC = PORTC_INT;
	PORTD = PORTD_INT;
}
