#include "COTS/1-MCAL/8-SPI/SPI_interface.h"
#include "COTS/1-MCAL/6-PORT/PORT_interface.h"
#include <util/delay.h>

void main (void)
{
	PORT_voidInit();
	SPI_voidSlaveInit();
	u8 data;
	while(1)
	{
		data = SPI_u8TransCeive(5);
		if(data==10)
		{
			DIO_u8SetPinValue(PORT_A, PIN0, HIGH);
		}
	}
}
