/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TIMER               ***********************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#include "TIMER_register.h"
#include "TIMER_config.h"
#include "../1-DIO/DIO_interface.h"

void TIMER0_voidINIT(u8 Copy_u8Mode,u8 Copy_u8Prescaler);

u8 TIMER0_u8COMPCallBackFunc(void(*pvNotfication)(void));

u8 TIMER0_u8OVFCallBackFunc(void(*pvNotfication)(void));

void TIMER0_SetCOMPValue(u8 Value);

void TIMER0_COMPIntE(u8 Copy_u8Enable);

void TIMER0_OVFIntE(u8 Copy_u8Enable);

void TIMER0_SetOutMode(u8 Copy_u8OutMode);


void DELYA_voidNonBlockDelay(u16 Copy_ms, void(*pvFunc)(void) ,u8 Copy_u8Periodic);


void TIMER1_voidInit(void);

void TIMER1_TopValue(u16 Value);

void TIMER1_channelACOMPValue(u16 Value);

void TIMER1_SetChannelReading(u16 Value);

u16 TIMER1_ReadChannelReading(void);



void ICU_voidInit(void);

u16 ICU_ReadChannelReading(void);

void ICU_voidSetEdge(u8 Edge);

void ICU_voidInterrupt(u8 EN);

u8 ICU_voidSetCallBack(void (*pvCallBack)(void));


										/*WatchDog*/
void WDT_voidSleep(u8 Value);

void WDT_voidDisable(void);

#endif
