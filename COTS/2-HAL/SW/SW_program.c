/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : HAL                 ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : LED                 ***********************/
/*********************************************************************************/
/*********************************************************************************/
#include "SW_interface.h"

void SW_Def(SW_t *SW)
{
	switch(SW ->PUL_t)
	{
	case PULL_UP :
		DIO_u8SetPinDirection(SW->PORT,SW->PIN,INPUT);
		DIO_u8SetPinValue(SW->PORT,SW->PIN,HIGH);
		break;
	case PULL_DOWN :
		DIO_u8SetPinDirection(SW->PORT,SW->PIN,INPUT);
		break;
	default:
		break;
	}
}
u8 SW_GetState(SW_t* SW)
{
	u8 value;
	switch (SW ->PUL_t)
	{
	case PULL_UP :
		DIO_u8GetPinValue(SW->PORT,SW->PIN,&value);
        return(value);
		break;

	case PULL_DOWN :
		DIO_u8GetPinValue(SW->PORT,SW->PIN,&value);
		return(value);
		break;
	default :
		break;
	}
}
