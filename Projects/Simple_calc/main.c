#include<util/delay.h>
#include"COTS/2-HAL/SW/SW_interface.h"
#include"COTS/2-HAL/LCD/LCD_interface.h"
void main (void)
{
	DIO_u8SetPortDirection(PORT_A, 0xff);
	DIO_u8SetPinDirection(PORT_B, PIN0, OUTPUT);
	DIO_u8SetPinDirection(PORT_B, PIN1, OUTPUT);
	DIO_u8SetPinDirection(PORT_B, PIN2, OUTPUT);
	LCD_voidInit();
	u8 op[4] = {'*','/','+','-'};
	s8 Number2=0;
	s8 Number3=0;
	s8 Number1=0;
	u8 y=0;
	SW_t INC =
	{PORT_D,PIN0,PULL_UP
	};
	SW_t DEC =
	{PORT_D,PIN1,PULL_UP
	};
	SW_t ENT =
	{PORT_D,PIN2,PULL_UP
	};
	SW_Def(&INC);
	SW_Def(&DEC);
	SW_Def(&ENT);
	LCD_voidSendString("0 * 0");
	LCD_voidGoToXY(1,y);
	LCD_voidSendString("^");
	LCD_voidGoToXY(0,y);
	while(1)
	{
		if(y==0)
		{
			while(1)
			{
				if(SW_GetState(&INC)==1)
				{
					Number1++;
					if(Number1==10)
					{
						Number1=0;
					}
					LCD_voidWriteNumber(Number1);
					_delay_ms(500);
					LCD_voidGoToXY(0,y);
				}
				if(SW_GetState(&DEC)==1)
				{
					Number1--;
					if(Number1<0)
					{
						Number1=9;
					}
					LCD_voidWriteNumber(Number1);
					_delay_ms(500);
					LCD_voidGoToXY(0,y);
				}
				if(SW_GetState(&ENT)==1)
				{
					LCD_voidGoToXY(1,y);
					LCD_voidSendString(" ");
					y+=2;
					LCD_voidGoToXY(1,y);
					LCD_voidSendString("^");
					_delay_ms(500);
				}
				if(y==2)
					break;
			}
		}
		else if(y==2)
		{
			LCD_voidGoToXY(0,y);
			LCD_voidSendData(op[Number2]);
			while(1)
			{
				if(SW_GetState(&INC)==1)
				{
					LCD_voidGoToXY(0,y);
					Number2++;
					if(Number2==4)
					{
						Number2=0;
					}
					LCD_voidSendData(op[Number2]);
					_delay_ms(500);
				}
				if(SW_GetState(&DEC)==1)
				{
					LCD_voidGoToXY(0,y);
					Number2--;
					if(Number2<0)
					{
						Number2=3;
					}
					LCD_voidSendData(op[Number2]);
					_delay_ms(500);
				}
				if(SW_GetState(&ENT)==1)
				{
					LCD_voidGoToXY(1,y);
					LCD_voidSendString(" ");
					y+=2;
					LCD_voidGoToXY(1,y);
					LCD_voidSendString("^");
					_delay_ms(500);
				}
				if(y==4)
					break;
			}
		}

		else if(y==4)
		{
			while(1)
			{
				if(SW_GetState(&INC)==1)
				{
					Number3++;
					LCD_voidGoToXY(0,y);
					if(Number3==10)
					{
						Number3=0;
					}
					LCD_voidWriteNumber(Number3);
					_delay_ms(500);
				}
				if(SW_GetState(&DEC)==1)
				{
					Number3--;
					LCD_voidGoToXY(0,y);
					if(Number3<0)
					{
						Number3=9;
					}
					LCD_voidWriteNumber(Number3);
					_delay_ms(500);
				}
				if(SW_GetState(&ENT)==1)
				{
					LCD_voidGoToXY(1,y);
					LCD_voidSendString(" ");
					y+=2;
					LCD_voidGoToXY(0,y);
					LCD_voidSendString("=");
					_delay_ms(500);
				}
				if(y==6)
					break;
			}
		}
		else if(y==6) {
			y=8;
			u8 Result;
			LCD_voidGoToXY(0,y);
			switch(Number2)
			{
			case 0:
				Result=Number1 * Number3;
				LCD_voidGoToXY(0,y);
				LCD_voidWriteNumber(Result);
				break;
			case 1:
				if((Number1%Number3) == 0)
				{
					Result=Number1 / Number3;
					LCD_voidGoToXY(0,y);
					LCD_voidWriteNumber(Result);
				}
				else
				{
					Result=Number1 / Number3;
					LCD_voidGoToXY(0,y);
					LCD_voidWriteNumber(Result);
					LCD_voidGoToXY(0,y+1);
					LCD_voidSendData('.');
					u8 mod=(Number1%Number3)*10;
					if((mod%Number3) ==0 )
					{
						LCD_voidGoToXY(0,y+2);
						Result=mod/Number3 ;
						LCD_voidWriteNumber(Result);
					}
					else
					{
						Result=mod / Number3;
						LCD_voidGoToXY(0,y+2);
						LCD_voidWriteNumber(Result);
						u8 mod2 =(mod%Number3)*10;
						LCD_voidGoToXY(0,11);
						Result=mod2/Number3 ;
						LCD_voidWriteNumber(Result);
					}
				}
				break;
			case 2:
				Result=Number1 + Number3;
				LCD_voidGoToXY(0,8);
				LCD_voidWriteNumber(Result);
				break;
			case 3:
				if(Number3>Number1)
				{
					LCD_voidGoToXY(0,8);
					LCD_voidSendData('-');
					LCD_voidGoToXY(0,9);
					Result=Number3 - Number1;
					LCD_voidWriteNumber(Result);
				}
				else
				{
					LCD_voidGoToXY(0,8);
					Result=Number1 - Number3;
					LCD_voidWriteNumber(Result);
				}
				break;
			default:
				break;

			}
		}
	}
}

