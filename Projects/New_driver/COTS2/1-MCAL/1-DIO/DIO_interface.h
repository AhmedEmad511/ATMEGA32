#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "DIO_register.h"

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

u8 DIO_u8SetPinDirection(u8 u8_CopyPort,u8 u8_CopyPin,u8 u8_Direction);
u8 DIO_u8SetPortDirection(u8 u8_CopyPort,u8 u8_Direction);

u8 DIO_u8SetPinValue(u8 u8_CopyPort,u8 u8_CopyPin,u8 u8_Value);
u8 DIO_u8SetPortValue(u8 u8_CopyPort,u8 u8_Value);

u8 DIO_u8GetPinValue(u8 u8_CopyPort,u8 u8_CopyPin,u8* u8_Value);
u8 DIO_u8GetPortValue(u8 u8_CopyPort,u8* u8_Value);

#endif
