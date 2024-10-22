/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : DIO                 ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "DIO_interface.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin ,u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = 0;
	if (Copy_u8Pin > 7)
		Local_u8ErrorState = 1;
	if(Copy_u8Direction == INPUT)
	{
		switch (Copy_u8Port)
		{
		case PORT_A :
			CLR_BIT(DDRA,Copy_u8Pin);
			break;
		case PORT_B :
			CLR_BIT(DDRB,Copy_u8Pin);
			break;
		case PORT_C :
			CLR_BIT(DDRC,Copy_u8Pin);
			break;
		case PORT_D :
			CLR_BIT(DDRD,Copy_u8Pin);
			break;
		default:
			Local_u8ErrorState =1;
			break;
		}
	}
	else if(Copy_u8Direction == OUTPUT)
	{
		switch (Copy_u8Port)
		{
		case PORT_A :
			SET_BIT(DDRA,Copy_u8Pin);
			break;
		case PORT_B :
			SET_BIT(DDRB,Copy_u8Pin);
			break;
		case PORT_C :
			SET_BIT(DDRC,Copy_u8Pin);
			break;
		case PORT_D :
			SET_BIT(DDRD,Copy_u8Pin);
			break;
		default:
			Local_u8ErrorState =1;
			break;
		}
	}
	else
	{
		Local_u8ErrorState =1;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState =0;
	switch (Copy_u8Port)
	{
	case PORT_A :
		DDRA = Copy_u8Direction;
		break;
	case PORT_B :
		DDRB = Copy_u8Direction;
		break;
	case PORT_C :
		DDRC = Copy_u8Direction;
		break;
	case PORT_D :
		DDRD = Copy_u8Direction;
		break;
	default :
		Local_u8ErrorState =1;
		break;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin ,u8 Copy_u8Value)
{
	u8 Local_u8ErrorState =0;
	if(Copy_u8Pin>7)
		Local_u8ErrorState =1;
	if(Copy_u8Value == LOW)
	{
		switch (Copy_u8Port)
		{
		case PORT_A :
			CLR_BIT(PORTA,Copy_u8Pin);
			break;
		case PORT_B :
			CLR_BIT(PORTB,Copy_u8Pin);
			break;
		case PORT_C :
			CLR_BIT(PORTC,Copy_u8Pin);
			break;
		case PORT_D :
			CLR_BIT(PORTD,Copy_u8Pin);
			break;
		default:
			Local_u8ErrorState =1;
			break;
		}
	}
	else if(Copy_u8Value == HIGH)
	{
		switch (Copy_u8Port)
		{
		case PORT_A :
			SET_BIT(PORTA,Copy_u8Pin);
			break;
		case PORT_B :
			SET_BIT(PORTB,Copy_u8Pin);
			break;
		case PORT_C :
			SET_BIT(PORTC,Copy_u8Pin);
			break;
		case PORT_D :
			SET_BIT(PORTD,Copy_u8Pin);
			break;
		default:
			Local_u8ErrorState =1;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState =0;
	switch (Copy_u8Port)
	{
	case PORT_A :
		PORTA = Copy_u8Value;
		break;

	case PORT_B :
		PORTB = Copy_u8Value ;
		break;

	case PORT_C :
		PORTC = Copy_u8Value ;
		break;

	case PORT_D :
		PORTD = Copy_u8Value ;
		break;

	default :

		Local_u8ErrorState =1;
		break;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8Value)
{
	u8 Local_u8ErrorState =0;
	if((Copy_u8Value == NULL) || (Copy_u8Pin > 7))
		Local_u8ErrorState =1;
	switch (Copy_u8Port)
	{
	case PORT_A :
		*Copy_u8Value = GET_BIT(PINA,Copy_u8Pin);
		break;
	case PORT_B :
		*Copy_u8Value = GET_BIT(PINB,Copy_u8Pin);
		break;
	case PORT_C :
		*Copy_u8Value = GET_BIT(PINC,Copy_u8Pin);
		break;
	case PORT_D :
		*Copy_u8Value = GET_BIT(PIND,Copy_u8Pin);
		break;
	default:
		Local_u8ErrorState =1;
		break;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8* Copy_u8Value)
{
	u8 Local_u8ErrorState =0;
	switch(Copy_u8Port)
	{
	case PORT_A :
		*Copy_u8Value = PINA ;
		break;
	case PORT_B :
		*Copy_u8Value = PINB ;
		break;
	case PORT_C :
		*Copy_u8Value = PINC ;
		break;
	case PORT_D :
		*Copy_u8Value = PIND ;
		break;
	default :
		Local_u8ErrorState =1;
		break;
	}
	return Local_u8ErrorState ;
}

f32 Map(s32 InputValue,s32 InputMin,s32 InputMax,s32 OutMin,s32 OutMax)
{
	f32 Result =(((OutMax-OutMin)*(InputValue-InputMin))/(InputMax-InputMin));
	f32 OutValue =Result+OutMin;
	return OutValue ;
}


