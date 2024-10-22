/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : SPI                 ***********************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR       	 	*((volatile u8*)0x2D)				//SPI Control Register
#define SPCR_SPR0		0									//SCK frequency
#define SPCR_SPR1		1									//SCK frequency
#define SPCR_CPHA		2									//Clock phase
#define SPCR_CPOL		3									//Clock Polarity
#define SPCR_MSTR		4									//Master Selection
#define SPCR_DORD		5									//Data Order
#define SPCR_SPE		6									//SPI enable
#define SPCR_SPIE		7									//SPI Interrupt Enable


#define SPSR      	 	*((volatile u8*)0x2E)				//SPI Status Register
#define SPSR_SPI2X		0									//Double Speed
#define SPSR_SPIF		7									//Interrupt Flag


#define SPDR       	 	*((volatile u8*)0x2F)				//SPI Data Register

#endif
