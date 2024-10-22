/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TIMER               ***********************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#include "TIMER_register.h"
#include "../1-DIO/DIO_interface.h"

void TIMER0_voidINIT(void);

u8 TIMER0_u8SetCallBackFunc(void(*pvNotfication)(void));

#endif
