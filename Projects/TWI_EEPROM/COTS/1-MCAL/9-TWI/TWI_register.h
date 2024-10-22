/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TWI                 ***********************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWCR		       		*((volatile u8*)0x56)			//TWI Control Register
#define TWCR_TWINT				7	//TWI Interrupt Flag
#define TWCR_TWEA				6	//TWI Enable ACK bit
#define TWCR_TWSTA				5	//TWI Start Condition Bit
#define TWCR_TWSTO				4	//TWI Stop Condition Bit
#define TWCR_TWWC				3	//TWI Write Collision Flag
#define TWCR_TWEN				2	//TWI Enable Bit
#define TWCR_TWIE				0	//TWI Interrupt Enable



#define TWDR		       		*((volatile u8*)0x23)			//TWI Data Register


#define TWAR		       		*((volatile u8*)0x22)			//TWI Address Register (Slave Address)
#define TWAR_TWGCE				0  //General Call Recognition Enable Bit


#define TWSR		       		*((volatile u8*)0x21)			//TWI Status Register
#define TWSR_TWS7				7	//TWI Status
#define TWSR_TWS6				6   //TWI Status
#define TWSR_TWS5				5   //TWI Status
#define TWSR_TWS4				4   //TWI Status
#define TWSR_TWS3				3   //TWI Status
#define TWSR_TWPS1				1   //TWI Prescaler
#define TWSR_TWPS0				0   //TWI Prescaler



#define TWBR		       		*((volatile u8*)0x20)			//TWI Bit Rate Register




#endif
