#include "COTS/1-MCAL/7-USART/USART_interface.h"
#include "COTS/1-MCAL/6-PORT/PORT_interface.h"
void main (void)
{
	u8 data=0;
	PORT_voidInit();
	USART_voidInit();
	while(1)
	{
		data = USART_u8ReadData();
		if(data=='1')
		{
			DIO_u8SetPinValue(PORT_A, PIN0, HIGH);
		}
		else if(data=='2')
		{
			DIO_u8SetPinValue(PORT_A, PIN0, LOW);
		}
		USART_voidSendData('D');
	}
}
