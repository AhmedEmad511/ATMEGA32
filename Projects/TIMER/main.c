#include <util/delay.h>
#include "COTS/1-MCAL/6-PORT/PORT_interface.h"
#include "COTS/1-MCAL/5-TIMER/TIMER_interface.h"
#include "COTS/2-HAL/LCD/LCD_interface.h"
#include "COTS/1-MCAL/3-GIE/GIE_interface.h"
#include "COTS/1-MCAL/2-EXTI/EXTI_interface.h"
void LED (void);
void main(void)
{
	GIE_voidEnable();
	DIO_u8SetPinDirection(PORT_A, PIN0, OUTPUT);
	DELYA_voidNonBlockDelay(500,&LED,PERIODIC);
	while(1)
	{
		DIO_u8SetPinValue(PORT_A, PIN0,HIGH);
	}
}

void LED (void)
{
	DIO_u8SetPinValue(PORT_A, PIN0,LOW);
	_delay_ms(500);
}
