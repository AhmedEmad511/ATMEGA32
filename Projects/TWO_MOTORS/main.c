#include<util/delay.h>
#include"COTS/2-HAL/LCD/LCD_interface.h"
#include "COTS/1-MCAL/2-EXTI/EXTI_interface.h"
#include "COTS/1-MCAL/3-GIE/GIE_interface.h"
u8 counter =0;
u8 x,y,z;
void main (void)
{
	DIO_u8SetPinDirection(PORT_D, PIN2, INPUT);
	DIO_u8SetPinDirection(PORT_D, PIN3, INPUT);
	DIO_u8SetPinDirection(PORT_D, PIN4, INPUT);
	DIO_u8SetPinValue(PORT_D, PIN2, HIGH);
	DIO_u8SetPinValue(PORT_D, PIN3, HIGH);
	DIO_u8SetPinValue(PORT_D, PIN4, HIGH);
	DIO_u8SetPortDirection(PORT_A, 0xff);
	DIO_u8SetPinDirection(PORT_B, PIN0, OUTPUT);
	DIO_u8SetPinDirection(PORT_B, PIN1, OUTPUT);
	DIO_u8SetPinDirection(PORT_B, PIN2, OUTPUT);
	DIO_u8SetPinDirection(PORT_B, PIN3, OUTPUT);
	DIO_u8SetPinDirection(PORT_B, PIN4, OUTPUT);
	LCD_voidInit();

	u8 Hamoksha[8]={0b01110,0b00100,0b11111,0b10101,0b10101,0b00100,0b01010,0b10001};
	u8 Side1[8]={0b01110,0b01110,0b00100,0b00100,0b00100,0b00100,0b00100,0b00100};
	u8 Side2[8]={0b01110,0b01110,0b00100,0b01100,0b10110,0b00100,0b01010,0b10001};

	DIO_u8SetPinDirection(PORT_C, PIN0, OUTPUT);
	DIO_u8SetPinDirection(PORT_C, PIN1, OUTPUT);
	DIO_u8SetPinDirection(PORT_C, PIN2, OUTPUT);
	DIO_u8SetPinDirection(PORT_C, PIN3, OUTPUT);
	DIO_u8SetPinValue(PORT_C, PIN0, HIGH);
	DIO_u8SetPinValue(PORT_C, PIN1, HIGH);
	DIO_u8SetPinValue(PORT_C, PIN2, HIGH);
	DIO_u8SetPinValue(PORT_C, PIN3, HIGH);
	/*LCD_voidSendCommand(0b00000001);
	_delay_ms(1000);
	LCD_voidSpecialChar(Hamoksha,0,0,0);
	_delay_ms(1000);
	LCD_voidGoToXY(0,3);
	LCD_voidSendString("Hello");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("My friend");
	_delay_ms(1000);
	LCD_voidSendCommand(0b00000001);
	for(u8 i=0 ;i<16;i++)
	{
		if(i%2==0)
		{
			LCD_voidSpecialChar(Side1,0,0,i);
			_delay_ms(300);
			LCD_voidSendCommand(0b00000001);
		}
		else
		{
			LCD_voidSpecialChar(Side2,0,0,i);
			_delay_ms(300);
			LCD_voidSendCommand(0b00000001);
		}
	}
	LCD_voidSendCommand(0b00000001);
	LCD_voidSpecialChar(Hamoksha,0,0,15);
	_delay_ms(500);
	LCD_voidGoToXY(0,0);
	LCD_voidSendString("Welcome to MOTOR");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("LCD Project");
	_delay_ms(1000);
	LCD_voidSendCommand(0b00000001);*/
	while(1)
	{
		LCD_voidGoToXY(0,0);
		LCD_voidSendString("Press : 1 for DC");
		LCD_voidGoToXY(1,0);
		LCD_voidSendString("   2 for Stepper");
		DIO_u8GetPinValue(PORT_D, PIN2, &x);
		DIO_u8GetPinValue(PORT_D, PIN3, &y);
		if(x == 0)
		{
			LCD_voidSendCommand(0b00000001);
			LCD_voidGoToXY(0,0);
			LCD_voidSendString("1:C.W / 2:C.C.W");
			LCD_voidGoToXY(1,0);
			LCD_voidSendString("3:BACK");
			_delay_ms(500);
			while(1)
			{
				DIO_u8GetPinValue(PORT_D, PIN2, &x);
				DIO_u8GetPinValue(PORT_D, PIN3, &y);
				DIO_u8GetPinValue(PORT_D, PIN4, &z);
				if(x == 0)
				{
					DIO_u8SetPinValue(PORT_B, PIN3, HIGH);
					DIO_u8SetPinValue(PORT_B, PIN4, LOW);
				}
				if(y == 0)
				{
					DIO_u8SetPinValue(PORT_B, PIN3, LOW);
					DIO_u8SetPinValue(PORT_B, PIN4, HIGH);
				}
				if(z == 0)
				{
					DIO_u8SetPinValue(PORT_B, PIN3, LOW);
					DIO_u8SetPinValue(PORT_B, PIN4, LOW);
					break;
				}
			}
		}
		else if(y==0)
		{
			_delay_ms(500);
			LCD_voidSendCommand(1);
			while(1)
			{
				LCD_voidGoToXY(0,0);
				LCD_voidSendString("1:C.W / 2:C.C.W");
				LCD_voidGoToXY(1,0);
				LCD_voidSendString("3:BACK");
				DIO_u8GetPinValue(PORT_D, PIN2, &x);
				DIO_u8GetPinValue(PORT_D, PIN3, &y);
				DIO_u8GetPinValue(PORT_D, PIN4, &z);
				if (x == 0)
				{
					while(1)
					{
						DIO_u8SetPinValue(PORT_C ,PIN0, LOW);
						DIO_u8SetPinValue(PORT_C ,PIN1, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN2, HIGH);
						DIO_u8SetPinValue(PORT_C ,PIN3, HIGH);
						_delay_ms(2);
						DIO_u8SetPinValue(PORT_C, PIN0, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN1, LOW);
						DIO_u8SetPinValue(PORT_C, PIN2, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN3, HIGH);
						_delay_ms(2);
						DIO_u8SetPinValue(PORT_C, PIN0, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN1, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN2, LOW);
						DIO_u8SetPinValue(PORT_C, PIN3, HIGH);
						_delay_ms(2);
						DIO_u8SetPinValue(PORT_C, PIN0, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN1, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN2, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN3, LOW);
						_delay_ms(2);
						DIO_u8GetPinValue(PORT_D, PIN4, &z);
						if(z==0)
						break;
					}
				}
				else if(y==0)
				{
					while(1)
					{
						GIE_voidDisable();
						DIO_u8SetPinValue(PORT_C, PIN0, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN1, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN2, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN3, LOW);
						_delay_ms(2);
						DIO_u8SetPinValue(PORT_C, PIN0, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN1, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN2, LOW);
						DIO_u8SetPinValue(PORT_C, PIN3, HIGH);
						_delay_ms(2);
						DIO_u8SetPinValue(PORT_C, PIN0, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN1, LOW);
						DIO_u8SetPinValue(PORT_C, PIN2, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN3, HIGH);
						_delay_ms(2);
						DIO_u8SetPinValue(PORT_C ,PIN0, LOW);
						DIO_u8SetPinValue(PORT_C ,PIN1, HIGH);
						DIO_u8SetPinValue(PORT_C, PIN2, HIGH);
						DIO_u8SetPinValue(PORT_C ,PIN3, HIGH);
						_delay_ms(2);
						DIO_u8GetPinValue(PORT_D, PIN4, &z);
						if(z==0)
						break;
					}
				}
				if(z==0)
				{
					DIO_u8SetPinValue(PORT_C ,PIN0, HIGH);
					DIO_u8SetPinValue(PORT_C ,PIN1, HIGH);
					DIO_u8SetPinValue(PORT_C, PIN2, HIGH);
					DIO_u8SetPinValue(PORT_C ,PIN3, HIGH);
					break;
				}
			}
		}
	}
}

/*void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{}*/

