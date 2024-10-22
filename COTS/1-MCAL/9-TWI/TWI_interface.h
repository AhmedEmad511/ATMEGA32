/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TWI                 ***********************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_
#include "../1-DIO/DIO_interface.h"
#include "TWI_register.h"
#include "TWI_private.h"

typedef enum
{
	NoError,
	StartConditionErr,
	RepStartError,
	SendSlaveWithWriteErr,
	SendSlaveWithReadErr,
	MasterSendDataErr,
	MasterReadByteErr,
}TWI_ErrState;

/*Pass 0 if The master won't be Addressed*/
void TWI_voidMasterInit(u8 Copy_u8Address);

void TWI_voidSlaveInit(u8 Copy_u8Adderss);

TWI_ErrState TWI_SendStart(void);

TWI_ErrState TWI_SendRepeatedStart(void);

TWI_ErrState TWI_SendSlaveAddWithWrite(u8 Copy_u8SlaveAdd);

TWI_ErrState TWI_SendSlaveAddWithRead(u8 Copy_u8SlaveAdd);

TWI_ErrState TWI_MasterSendDataByte(u8 Copy_u8Data);

TWI_ErrState TWI_MasterReadDataByte(u8 *Copy_pu8Data);

void TWI_SendStop(void);

#endif
