#include "COTS2/1-MCAL/1-DIO/DIO_interface.h"

void main(void)
{
	DIO_u8SetPortDirection(PORT_C,0xff);

	while(1)
	{
	DIO_u8SetPortValue(PORT_C,0xff);
	}

}

