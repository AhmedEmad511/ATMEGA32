#include <util/delay.h>
#include "COTS/1-MCAL/9-TWI/TWI_interface.h"
#include "COTS/2-HAL/EEPROM/EEPROM_interface.h"
#include "COTS/1-MCAL/6-PORT/PORT_interface.h"

void main (void)
{
	u8 Value;
	TWI_voidMasterInit(0);
	EEPROM_voidSendData(0b10101010,0);
	_delay_ms(10);
	EEPROM_voidReadData(0,&Value);
	_delay_ms(10);
	DIO_u8SetPortValue(PORT_A,Value);
	while(1);
}
