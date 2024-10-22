#include "DIO_interface.h"

u8 DIO_u8SetPinDirection(u8 u8_CopyPort,u8 u8_CopyPin,u8 u8_Direction)
{
	if(u8_Direction ==OUTPUT )
	{
		switch (u8_CopyPort)
		{
		case PORT_A :
			SET_BIT(DDRA,u8_CopyPin);
			break;
		case PORT_B :
			SET_BIT(DDRB,u8_CopyPin);
			break;
		case PORT_C :
			SET_BIT(DDRC,u8_CopyPin);
			break;
		case PORT_D :
			SET_BIT(DDRD,u8_CopyPin);
			break;
		default :
			break;
		}
	}
	if(u8_Direction ==INPUT )
	{
		switch (u8_CopyPort)
		{
		case PORT_A :
			CLR_BIT(DDRA,u8_CopyPin);
			break;
		case PORT_B :
			CLR_BIT(DDRB,u8_CopyPin);
			break;
		case PORT_C :
			CLR_BIT(DDRC,u8_CopyPin);
			break;
		case PORT_D :
			CLR_BIT(DDRD,u8_CopyPin);
			break;
		default :
			break;
		}
	}
}

u8 DIO_u8SetPortDirection(u8 u8_CopyPort,u8 u8_Direction)
{
	switch (u8_CopyPort)
	{
	case PORT_A :
		DDRA=u8_Direction;
		break;
	case PORT_B :
	    DDRB=u8_Direction;
		break;
	case PORT_C :
		DDRC=u8_Direction;
		break;
	case PORT_D :
		DDRD=u8_Direction;
		break;
	default:
		break;
	}
}

u8 DIO_u8SetPinValue(u8 u8_CopyPort,u8 u8_CopyPin,u8 u8_Value)
{
	if(u8_Value ==HIGH )
	{
		switch (u8_CopyPort)
		{
		case PORT_A :
			SET_BIT(PORTA,u8_CopyPin);
			break;
		case PORT_B :
			SET_BIT(PORTB,u8_CopyPin);
			break;
		case PORT_C :
			SET_BIT(PORTC,u8_CopyPin);
			break;
		case PORT_D :
			SET_BIT(PORTD,u8_CopyPin);
			break;
		default :
			break;
		}
	}
	if(u8_Value == LOW )
	{
		switch (u8_CopyPort)
		{
		case PORT_A :
			CLR_BIT(PORTA,u8_CopyPin);
			break;
		case PORT_B :
			CLR_BIT(PORTB,u8_CopyPin);
			break;
		case PORT_C :
			CLR_BIT(PORTC,u8_CopyPin);
			break;
		case PORT_D :
			CLR_BIT(PORTD,u8_CopyPin);
			break;
		default :
			break;
		}
	}

}


u8 DIO_u8SetPortValue(u8 u8_CopyPort,u8 u8_Value)
{
	switch (u8_CopyPort)
	{
	case PORT_A :
		PORTA=u8_Value;
		break;
	case PORT_B :
		PORTB=u8_Value;
		break;
	case PORT_C :
		PORTC=u8_Value;
		break;
	case PORT_D :
		PORTD=u8_Value;
		break;
	default:
		break;
	}
}


u8 DIO_u8GetPinValue(u8 u8_CopyPort,u8 u8_CopyPin,u8* u8_Value)
{
	switch (u8_CopyPort)
	{
	case PORT_A :
		*u8_Value=GET_BIT(PINA,u8_CopyPin);
		break;
	case PORT_B :
		*u8_Value=GET_BIT(PINB,u8_CopyPin);
		break;
	case PORT_C :
		*u8_Value=GET_BIT(PINC,u8_CopyPin);
		break;
	case PORT_D :
		*u8_Value=GET_BIT(PIND,u8_CopyPin);
		break;
	}
}


u8 DIO_u8GetPortValue(u8 u8_CopyPort,u8* u8_Value)
{
	switch(u8_CopyPort)
	{
	case PORT_A :
		*u8_Value=PINA ;
		break;
	case PORT_B :
		*u8_Value=PINB ;
		break;
	case PORT_C :
		*u8_Value=PINC ;
		break;
	case PORT_D :
		*u8_Value=PIND ;
		break;
	default:
		break;
	}
}
