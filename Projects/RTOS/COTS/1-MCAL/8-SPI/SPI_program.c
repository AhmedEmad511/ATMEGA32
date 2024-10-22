/*********************************************************************************/
/*********************************************************************************/
 /********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : SPI                 ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include"SPI_interface.h"

void SPI_voidMasterInit(void)
{
	/*Set as Master*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*Set Prescaler to Fosc/16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);


	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}



void SPI_voidSlaveInit(void)
{
	/*Set as Slave*/
	CLR_BIT(SPCR,SPCR_MSTR);


	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}



u8 SPI_u8TransCeive(u8 Copy_u8Data)
{

	/*Send Data*/
	SPDR=Copy_u8Data;

	/*Wait untill Transfere is complete*/
	while (GET_BIT(SPSR,SPSR_SPIF)==0);

	/*Return The data*/
	return SPDR;
}
