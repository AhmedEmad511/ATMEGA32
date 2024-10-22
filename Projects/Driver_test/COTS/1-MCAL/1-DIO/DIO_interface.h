/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : DIO                 ***********************/
/*********************************************************************************/
/*********************************************************************************/
#include "STD_TYPES.h"
#include "DIO_register.h"
#include "BIT_MATH.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define INPUT	 0
#define OUTPUT	 1


#define HIGH	 1
#define LOW		 0


#define PORT_A	1
#define PORT_B	2
#define PORT_C 	3
#define PORT_D 	4

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5    5
#define PIN6	6
#define PIN7	7

#define NULL    0

#define OK      0
#define NOK     1

#define P_NULL  3


u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin ,u8 Copy_u8Direction);


u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);


u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin ,u8 Copy_u8Value);


u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);


u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8Value);


u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8* Copy_u8Value);

f32 Map(s32 InputValue,s32 InputMin,s32 InputMax,s32 OutMin,s32 OutMax);

#endif
