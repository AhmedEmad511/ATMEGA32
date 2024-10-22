/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : HAL                 ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : KeyPad              ***********************/
/*********************************************************************************/
/*********************************************************************************/
#include "KP_interface.h"

u8 KP_u8GetPressedKey(void)
{
	DIO_u8SetPortDirection(KP_PORT, 0b00001111);
	DIO_u8SetPortValue(KP_PORT, 0xff);
	 u8 PressedKey = NoPressedKey;
	 u8 PinState;
	 u8 Column,Row;
	static u8 KP_arr[4][4]= KPD_arr_val;
	static u8 KP_ColArr[4] ={KP_Col1,KP_Col2,KP_Col3,KP_Col4};
	static u8 KP_RowArr[4] ={KP_Row1,KP_Row2,KP_Row3,KP_Row4};

	for(Column=0;Column<4;Column++)
	{
		/*activate current Column*/
		DIO_u8SetPinValue(KP_PORT,KP_ColArr[Column],LOW);

		for(Row=0;Row<4;Row++)
		{
			/*Check Row Pins*/
			DIO_u8GetPinValue(KP_PORT, KP_RowArr[Row],&PinState);
			/*Check pin state*/
			if(PinState==0)
			{
				PressedKey=KP_arr[Row][Column];
				while(PinState==0)
				{
					DIO_u8GetPinValue(KP_PORT, KP_RowArr[Row],&PinState);
				}
				DIO_u8SetPinValue(KP_PORT,KP_ColArr[Column],HIGH);
				return PressedKey;
			}
		}
		/*Deactivate Column*/
		DIO_u8SetPinValue(KP_PORT,KP_ColArr[Column],HIGH);
	}


	return PressedKey;
}

