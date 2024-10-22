/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TWI                 ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "TWI_interface.h"


/*Pass 0 if The master won't be Addressed*/
void TWI_voidMasterInit(u8 Copy_u8Address)
{
	/*Set Clock frequency to 400Kbs*/
	TWBR=2;
	/*Set Prescaler to 1*/
	CLR_BIT(TWSR,TWSR_TWPS1);
	CLR_BIT(TWSR,TWSR_TWPS0);

	/*Initialize Master Address*/
	if(Copy_u8Address!=0)
	{
		TWAR=Copy_u8Address<<1;
	}

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8Adderss)
{
	/*Initialize Slave Address*/
	TWAR=Copy_u8Adderss<<1;

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrState TWI_SendStart(void)
{
	TWI_ErrState  ErrorStatus = NoError;

	/*Send Start Condition*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the Interrupt Flag to 1*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait untill the INT flag is Raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8)!=TW_START)
	{
		ErrorStatus=StartConditionErr;
	}
	return ErrorStatus;
}

TWI_ErrState TWI_SendRepeatedStart(void)
{
	TWI_ErrState  ErrorStatus = NoError;

	/*Send Start Condition*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the Interrupt Flag to 1*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait untill the INT flag is Raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8)!=TW_REP_START)
	{
		ErrorStatus=RepStartError;
	}
	return ErrorStatus;
}

TWI_ErrState TWI_SendSlaveAddWithWrite(u8 Copy_u8SlaveAdd)
{
	TWI_ErrState  ErrorStatus = NoError;
	/*Disable Start Bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set Slave Address then clr the last bit to make Write request */
	TWDR=Copy_u8SlaveAdd<<1;
	CLR_BIT(TWDR,0);


	/*Clear the Interrupt Flag to 1*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait untill the INT flag is Raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8)!=TW_MT_SLA_ACK)
	{
		ErrorStatus=SendSlaveWithWriteErr;
	}
	return ErrorStatus;
}

TWI_ErrState TWI_SendSlaveAddWithRead(u8 Copy_u8SlaveAdd)
{
	TWI_ErrState  ErrorStatus = NoError;
	/*Disable Start Bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set Slave Address then set the last bit to make Read request */
	TWDR=Copy_u8SlaveAdd<<1;
	SET_BIT(TWDR,0);

	/*Clear the Interrupt Flag to 1*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait untill the INT flag is Raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8)!=TW_MR_SLA_ACK)
	{
		ErrorStatus=SendSlaveWithReadErr;
	}
	return ErrorStatus;
}

TWI_ErrState TWI_MasterSendDataByte(u8 Copy_u8Data)
{
	TWI_ErrState  ErrorStatus = NoError;

	/*Set Data into the data register*/
	TWDR=Copy_u8Data;

	/*Clear the Interrupt Flag to 1*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait untill the INT flag is Raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8)!=TW_MT_DATA_ACK)
	{
		ErrorStatus=MasterSendDataErr;
	}
	return ErrorStatus;
}

TWI_ErrState TWI_MasterReadDataByte(u8 *Copy_pu8Data)
{
	TWI_ErrState  ErrorStatus = NoError;

	/*Enable ACK bit*/
	SET_BIT(TWCR,TWCR_TWEA);


	/*Clear the Interrupt Flag to start recieving*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait untill the INT flag is Raised again*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8)!=TW_MR_DATA_ACK)
	{
		ErrorStatus=MasterReadByteErr;
	}
	else
	{
		/*Read The data from Data Register*/
		*Copy_pu8Data=TWDR;
	}
	return ErrorStatus;
}

void TWI_SendStop(void)
{
	SET_BIT(TWCR,TWCR_TWSTO);

	/*Clear the Interrupt Flag to start the Operation*/
	SET_BIT(TWCR,TWCR_TWINT);
}





