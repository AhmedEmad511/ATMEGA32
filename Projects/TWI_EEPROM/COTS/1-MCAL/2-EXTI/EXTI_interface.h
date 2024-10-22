/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : EXTI                ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "../1-DIO/DIO_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_voidINT0Init(void);

void EXTI_voidINT1Init(void);

void EXTI_voidINT2Init(void);

u8 EXTI_u8IntSetSenseControl(u8 Copy_u8INT,u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8INT,u8 Copy_u8E);

u8 EXTI_u8Int0ISR(void (*Int0ISR) (void));
u8 EXTI_u8Int1ISR(void (*Int1ISR) (void));
u8 EXTI_u8Int2ISR(void (*Int2ISR) (void));



#endif
