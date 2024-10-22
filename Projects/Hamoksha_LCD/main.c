/*
 * main.c
 *
 *  Created on: Jul 24, 2023
 *      Author: ahmed
 */
#include "COTS/2-HAL/LCD/LCD_interface.h"
#include<util/delay.h>
void main (void)
{
	DIO_u8SetPortDirection(PORT_A,0xff);
	DIO_u8SetPinDirection(PORT_B,PIN0,OUTPUT);
	DIO_u8SetPinDirection(PORT_B,PIN1,OUTPUT);
	DIO_u8SetPinDirection(PORT_B,PIN2,OUTPUT);

	LCD_voidInit();
	u8 Hamoksha[8]={0b01110,0b00100,0b11111,0b10101,0b10101,0b00100,0b01010,0b10001};
	u8 Side1[8]={0b01110,0b01110,0b00100,0b00100,0b00100,0b00100,0b00100,0b00100};
	u8 Side2[8]={0b01110,0b01110,0b00100,0b01100,0b10110,0b00100,0b01010,0b10001};
	u8 Football1[8]={0b00111,0b00111,0b00010,0b00010,0b10010,0b11110,0b00010,0b00010};
	u8 Football2[8]={0b00111,0b00111,0b00010,0b10010,0b00010,0b00010,0b00010,0b00010};
	u8 Football3[8]={0b00111,0b00111,0b10010,0b00010,0b00010,0b00010,0b00010,0b00010};
	u8 Football4[8]={0b00111,0b10111,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010};
	u8 Football5[8]={0b10111,0b00111,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010};
	u8 Dance1[8]={0b01110,0b00101,0b00110,0b01100,0b10100,0b00100,0b01010,0b10001};
	u8 Dance2[8]={0b01110,0b10100,0b01100,0b00110,0b00101,0b00100,0b01010,0b10001};
	u8 Gun[8]={0b11111,0b11111,0b10100,0b11100,0b11000,0b11000,0b00000,0b00000};
	u8 Surrender[8]={0b01110,0b00100,0b10101,0b11111,0b00100,0b00100,0b01010,0b10001};
	u8 Dead[8]={0b00000,0b00000,0b00000,0b00011,0b11111,0b00011,0b00000,0b00000};
	u8 Bullet[8]={0b10000};
	LCD_voidSendCommand(0b00000001);
	_delay_ms(1000);
	LCD_voidSpecialChar(Hamoksha,0,0,0);
	_delay_ms(500);
	LCD_voidGoToXY(0,2);
	LCD_voidSendString("Hello I am ");
	LCD_voidGoToXY(1,3);
	LCD_voidSendString("HAMOKSHA");
	_delay_ms(1000);
	LCD_voidSendCommand(0b00000001);
	for(u8 i=0 ;i<16;i++)
	{
		if(i%2==0)
		{LCD_voidSpecialChar(Side1,0,0,i);
		_delay_ms(300);
		LCD_voidSendCommand(0b00000001);}
		else
		{LCD_voidSpecialChar(Side2,0,0,i);
		_delay_ms(300);
		LCD_voidSendCommand(0b00000001);}
	}
	LCD_voidSendCommand(0b00000001);
	LCD_voidSpecialChar(Hamoksha,0,0,15);
	_delay_ms(500);
	LCD_voidGoToXY(0,0);
	LCD_voidSendString("I can play");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("football");
	_delay_ms(1000);
	for(u8 j=0;j<3;j++)
	{
		for(u8 x=0;x<5;x++)
		{
			switch(x)
			{
			case 0:
				LCD_voidSpecialChar(Football1,0,0,15);
				_delay_ms(200);
				break;
			case 1:
				LCD_voidSpecialChar(Football2,0,0,15);
				_delay_ms(200);
				break;
			case 2:
				LCD_voidSpecialChar(Football3,0,0,15);
				_delay_ms(200);
				break;
			case 3:
				LCD_voidSpecialChar(Football4,0,0,15);
				_delay_ms(200);
				break;
			case 4:
				LCD_voidSpecialChar(Football5,0,0,15);
				break;
			}
			if(x==4)
			{
				for(u8 y=5; y>=1; y--)
				{
					switch(y)
					{
					case 5:
						LCD_voidSpecialChar(Football5,0,0,15);
						_delay_ms(200);
						break;
					case 4:
						LCD_voidSpecialChar(Football4,0,0,15);
						_delay_ms(200);
						break;
					case 3:
						LCD_voidSpecialChar(Football3,0,0,15);
						_delay_ms(200);
						break;
					case 2:
						LCD_voidSpecialChar(Football2,0,0,15);
						_delay_ms(200);
						break;
					case 1:
						LCD_voidSpecialChar(Football1,0,0,15);
						break;
					}
				}
			}
		}
	}
	LCD_voidSendCommand(0b00000001);
	LCD_voidSpecialChar(Hamoksha,0,0,15);
	LCD_voidGoToXY(0,0);
	LCD_voidSendString("I can also");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("Dance");
	_delay_ms(500);
	for(u8 count=0;count<10;count++)
	{
		if(count%2==0)
		{
			LCD_voidSpecialChar(Dance1,0,0,15);
			_delay_ms(500);
		}
		else{
			LCD_voidSpecialChar(Dance2,0,0,15);
			_delay_ms(500);
		}
	}
	LCD_voidSendCommand(0b00000001);
	LCD_voidSpecialChar(Hamoksha,0,0,15);
	_delay_ms(1000);
	LCD_voidSpecialChar(Gun,1,0,0);
	_delay_ms(1000);
	LCD_voidSpecialChar(Side1,0,0,15);
	_delay_ms(1000);
	LCD_voidSpecialChar(Hamoksha,0,0,15);
	_delay_ms(1000);
	LCD_voidSpecialChar(Side1,0,0,15);
	_delay_ms(1000);
	LCD_voidSpecialChar(Surrender,0,0,15);
	LCD_voidGoToXY(1,0);
	_delay_ms(1000);
	LCD_voidSendString("Pls Dont Kill me");
	_delay_ms(2000);
	while(1)
	{
		for (u8 bullet=1;bullet<15;bullet++)
		{
			LCD_voidSendCommand(0b00000001);
			LCD_voidSpecialChar(Surrender,0,0,15);
			LCD_voidSpecialChar(Gun,1,0,0);
			LCD_voidSpecialChar(Bullet,2,0,bullet);
			_delay_ms(200);
		}
		    LCD_voidSendCommand(0b00000001);
		    LCD_voidSpecialChar(Gun,1,0,0);
			LCD_voidSpecialChar(Dead,0,0,15);
			_delay_ms(1000);
	}
}

