#ifndef SS_INTERFACE_H_
#define SS_INTERFACE_H_
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "SS_regisret.h"


#define ANODE	0
#define CATHODE 1


typedef struct
{
	u8 COM_type; //CATODE or ANODE
	u8 PORT;
	u8 EnablePort;
	u8 EnablePin;
} SSD_t ;

u8 SSD_setNumber(u8 Number , SSD_t* SSD);

u8 SSD_Enable(SSD_t* SSD);
u8 SSD_Disable(SSD_t* SSD);

#endif
