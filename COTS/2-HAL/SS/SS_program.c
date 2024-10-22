#include "SS_interface.h"
u8 SSD_setNumber(u8 Number , SSD_t* SSD)
{
	DIO_u8SetPortDirection(SSD->PORT,0xff);
	DIO_u8SetPortValue(SSD->PORT,SSD->COM_type ? segmentA[Number] : ~segmentA[Number]);
	DIO_u8SetPinDirection(SSD->EnablePort,SSD->EnablePin,OUTPUT);
}

u8 SSD_Enable(SSD_t*SSD)
{
	switch(SSD -> COM_type)
	{
	case ANODE : DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,1) ;break;
	case CATHODE :DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,0); break;
	default:break;
	}
}
u8 SSD_Disable(SSD_t*SSD)
{
	switch(SSD -> COM_type)
	{
	case ANODE : DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,0);break;
	case CATHODE :DIO_u8SetPinValue(SSD->EnablePort,SSD->EnablePin,1);break;
	default:break;
	}
}

