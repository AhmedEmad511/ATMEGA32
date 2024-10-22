/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : HAL                 ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : LCD                 ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "LCD_config.h"
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidSendCommand(u8 Copy_u8Command);


void LCD_voidSendData(u8 Copy_u8Data);


void LCD_voidInit(void);


void LCD_voidSendString(const char* String );


void LCD_voidGoToXY(u8 X_position,u8 Y_Position);


void LCD_voidSpecialChar(u8* Pattern,u8 Block_no,u8 Xposition,u8 Yposition);


void LCD_voidWriteNumber(u32 Number);

#endif
