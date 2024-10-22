/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : ADC                 ***********************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include"../1-DIO/DIO_interface.h"
#include "ADC_register.h"
#include "ADC_config.h"

void ADC_voidInit(void);

typedef struct {
	u8* Channel ;
	u16* Result;
	u8 Size;
	void (*NotficationFunc)(void);
}Chain_t;

u8 ADC_u8StartConversionSync(u8 Copy_u8Channel,u8* Copy_pu8Reading);
u8 ADC_u8StartConversionAsync(u8 Copy_u8Channel,u8* Copy_pu8Reading ,void(*Copy_pvNot)(void)) ;
u8 ADC_u8StartChainConversion(Chain_t* Copy_Chain);
#endif
