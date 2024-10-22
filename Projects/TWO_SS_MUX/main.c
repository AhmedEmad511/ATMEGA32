#include <util/delay.h>
#include "COTS/1-MCAL/3-GIE/GIE_interface.h"
#include "COTS/1-MCAL/5-TIMER/TIMER_interface.h"
#include "COTS/2-HAL/SS/SS_interface.h"
void SSswitch (void);
s8 Num =0;
void main (void)
{
	SSD_t SS1 =
	{
			CATHODE,PORT_A,PORT_B,0
	};
	SSD_t SS2 =
	{
			CATHODE,PORT_A,PORT_B,1
	};
	GIE_voidEnable();
	TIMER0_voidINIT();
	TIMER0_u8SetCallBackFunc(&SSswitch);
	while(1)
	{
		SSD_Enable(&SS1);
		SSD_setNumber(Num,&SS1);
		_delay_ms(1);
		SSD_Disable(&SS1);
		SSD_Enable(&SS2);
		SSD_setNumber(9-Num,&SS2);
		_delay_ms(1);
		SSD_Disable(&SS2);
	}
}
void SSswitch (void)
{
	Num++;
	if(Num==10)
		Num=0;
}
