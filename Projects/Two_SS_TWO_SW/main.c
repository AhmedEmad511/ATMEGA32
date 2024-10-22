#include "COTS/1-MCAL/1-DIO/DIO_interface.h"
#include "COTS/2-HAL/SS/SS_interface.h"
#include "COTS/2-HAL/SW/SW_interface.h"
#include <util/delay.h>

void main(void)
{
	SSD_t SS1 =
	{
			CATHODE,PORT_A,PORT_D,PIN0
	};
	SSD_t SS2 =
	{
			CATHODE,PORT_A,PORT_D,PIN1
	};
	SW_t INC =
	{
			PORT_D,PIN2,PULL_UP
	};
	SW_t DEC =
	{
			PORT_D,PIN3,PULL_UP
	};
	SW_Def(&INC);
	SW_Def(&DEC);
	s8 Num1=0;
	s8 Num2=0;
	while(1)
	{
		for(u8 i=0 ;i<5;i++)
		{
		SSD_Enable(&SS1);
		SSD_setNumber(Num1,&SS1);
		_delay_ms(10);
		SSD_Disable(&SS1);
		SSD_Enable(&SS2);
		SSD_setNumber(Num2,&SS2);
		_delay_ms(10);
		SSD_Disable(&SS2);
		}

		if(SW_GetState(&INC))
		{
			_delay_ms(100);
			Num1++;
			if(Num1==10)
			{
				Num1=0;
				Num2++;
			}
			if(Num2 == 10)
			{
				Num2=0;
			}
		}
		if(SW_GetState(&DEC))
		{
			_delay_ms(100);
			Num1--;
			if(Num1<0)
			{
				Num1=9;
				Num2--;
			}
			if(Num2< 0)
			{
				Num2=9;
			}
		}
	}

}
