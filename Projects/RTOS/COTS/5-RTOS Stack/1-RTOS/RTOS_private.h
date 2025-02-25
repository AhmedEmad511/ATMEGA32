/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : RTOS                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : RTOS                ***********************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	u16 periodicity ;
	void (*TaskFunc)(void);
	u8 State;
	u16 First_Delay;
}Task_t;


static void voidScheduler(void);

#endif
