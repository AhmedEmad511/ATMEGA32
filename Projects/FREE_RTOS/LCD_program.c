/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : HAL                 ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : LCD                 ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>

void LCD_voidSendCommand(u8 Copy_u8Command)
{
#if LCD_MODE ==EIGHT_BIT
	/*set RS pin low for Command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,LOW);
	/*Set RW pin LOW for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	/*Send Command in data PORT*/
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Command);
	/*Send Enable Pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);


#elif LCD_MODE == FOUR_BIT
	/*set RS pin low for Command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,LOW);
	/*Set RW pin LOW for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	/*Send Command in data PORT*/
	DIO_u8SetPortValue(LCD_DATA_PORT,(Copy_u8Command & 0xf0));
	/*Send Enable Pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(5);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	_delay_ms(50);
	/*Send Lower nipple*/
	DIO_u8SetPortValue(LCD_DATA_PORT,(Copy_u8Command << 4));
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(5);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	_delay_ms(50);
#endif
}

void LCD_voidSendData(u8 Copy_u8Data)
{
#if LCD_MODE == EIGHT_BIT
	/*set RS pin HIGH for DATA*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,HIGH );
	/*Set RW pin LOW for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	/*Send Command in data PORT*/
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Data);
	/*Send Enable Pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);


#elif LCD_MODE == FOUR_BIT
	/*set RS pin HIGH for DATA*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,HIGH );
	/*Set RW pin LOW for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	/*Send Command in data PORT*/
	DIO_u8SetPortValue(LCD_DATA_PORT,(Copy_u8Data & 0xf0));
	/*Send Enable Pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);
	/*Send Lower Data*/
	DIO_u8SetPortValue(LCD_DATA_PORT,(Copy_u8Data << 4));
	/*Send Enable Pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,LOW);
#endif
}

void LCD_voidInit(void)
{
#if LCD_MODE == EIGHT_BIT
	/*Wait for 30ms to start*/
	_delay_ms(30);


	/*Put function set command 0011NFXX XX dont care
	 * N for number of line 0-->one line 1-->2 lines
	 * F for font size 0-->5x8 1-->5x11 */

	LCD_voidSendCommand(0b00111000);


	/*Display ON/OFF control 00001DCB
	 * D For display control 0--> Disable 1-->Enable
	 * C For cursor Enable 0-->Disable 1-->Enable
	 * B For Blink cursor enable 0-->Disable 1-->Enable*/

	LCD_voidSendCommand(0b00001100);

	/*Display clear*/

	LCD_voidSendCommand(1);


#elif LCD_MODE == FOUR_BIT

	_delay_ms(30);
	LCD_voidSendCommand(0x02);
	LCD_voidSendCommand(0x28);
	LCD_voidSendCommand(0x0c);
	LCD_voidSendCommand(0x06);

#endif

}

void LCD_voidSendString(const char* String )
{
	u8 Counter =  0 ;
	while(String[Counter])
	{
		LCD_voidSendData(String[Counter]);
		Counter++;
	}
}

void LCD_voidGoToXY(u8 X_position,u8 Y_Position)
{
	u8 Address;
	/*X position is the Row and Y is Col.
	 * Address of first row is from 0 to 0xf
	 * Second row is from 0x40 to 0x4f*/
	if(X_position==0)
	{
		Address =Y_Position;
	}
	else if(X_position==1)
	{
		Address =0x40 + Y_Position ;
	}
	/*The command to set address that you want is 0b10000000
	 * So we add 128 to the address*/
	LCD_voidSendCommand((Address|0b10000000));
}

void LCD_voidSpecialChar(u8* Pattern,u8 Block_no,u8 Xposition,u8 Yposition)
{
	u8 Address = Block_no*8;
	LCD_voidSendCommand(Address+64);
	for(u8 i=0 ;i<8;i++)
	{
		LCD_voidSendData(Pattern[i]);
	}
	LCD_voidGoToXY(Xposition,Yposition);
	LCD_voidSendData(Block_no);
}
void LCD_voidWriteNumber(u32 Number)
{
	u8 str[8];
	u8 i;
	u32 num;
	u8 rem;
	u8 len =0;
	num=Number;
	while(num != 0)
	{
		len++;
		num=num/10;
	}
	if(len==0)
	{
		LCD_voidSendData('0');

	}
	for(i=0;i<len;i++)
	{
		rem=Number%10;
		Number=Number/10;
		str[len-(i+1)]=rem+'0';
	}
	str[len]='\0';
	LCD_voidSendString(str);
}
