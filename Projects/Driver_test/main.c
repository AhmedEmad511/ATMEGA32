#include<util/delay.h>
#include "COTS/1-MCAL/6-PORT/PORT_interface.h"
#include "COTS/2-HAL/LCD/LCD_interface.h"
#include "COTS/2-HAL/SS/SS_interface.h"
#include "COTS/2-HAL/KeyPad/KP_interface.h"
#include "COTS/1-MCAL/5-TIMER/TIMER_interface.h"

void LED (void);
void main (void)
{
	PORT_voidInit();
	LCD_voidInit();
	//LCD_voidSendString("Welcome");
	//_delay_ms(3000);
	LCD_voidSendCommand(1);
	u8 x ;
	while(1)
	{
		do
		{
			x=KP_u8GetPressedKey();
		}while(KP_u8GetPressedKey()==0xff);

		LCD_voidWriteNumber(x);
	}

}
