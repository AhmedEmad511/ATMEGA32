/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : HAL                 ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : EEPROM              ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "EEPROM_interface.h"
#include "EEPROM_config.h"


void EEPROM_voidSendData(u8 Data,u16 Address)
{
	TWI_SendStart();
	TWI_SendSlaveAddWithWrite(0b1010|A2<<2|Address>>8);
	TWI_MasterSendDataByte((u8)Address);
	TWI_MasterSendDataByte(Data);
	TWI_SendStop();
}

void EEPROM_voidReadData(u16 Address,u8* pu8Data)
{
	TWI_SendStart();
	TWI_SendSlaveAddWithWrite(0b1010|A2<<2|Address>>8);
	TWI_MasterSendDataByte((u8)Address);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddWithRead(0b1010|A2<<2|Address>>8);
	TWI_MasterReadDataByte(pu8Data);
	TWI_SendStop();
}
