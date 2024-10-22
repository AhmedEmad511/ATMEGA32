#include "COTS/1-MCAL/8-SPI/SPI_interface.h"
#include "COTS/1-MCAL/6-PORT/PORT_interface.h"
#include <util/delay.h>

void main (void)
{
	PORT_voidInit();
	SPI_voidMasterInit();
	while(1)
	{
		SPI_u8TransCeive(10);
		_delay_ms(10);
	}
}
