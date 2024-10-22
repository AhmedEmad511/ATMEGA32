/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TIMER               ***********************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define NOT_INITIALIZED		1
#define INITIALIZED			2

#define PERIODIC			1
#define NON_PERIODIC		2


#define FALLING 			1
#define RISING				2


#define ENABLE				1
#define DISABLE				2

#define NORMAL				1
#define PWM					2
#define CTC					3
#define FAST_PWM			4


#define   NO_CLOCK			1
#define	  DIV_1				2
#define	  DIV_8				3
#define	  DIV_64			4
#define	  DIV_256			5
#define	  DIV_1024			6
#define	  EXT_T0_FALLING	7
#define	  EXT_T0_RISING		8


#define	DISC				1
#define TOGGLE				2
#define CLEAR				3
#define SET					4

#define PWM_DISC			1
#define PWM_CLR_UP			3
#define PWM_SET_UP			4


#define FAST_PWM_DISC		1
#define FAST_PWM_CLR_COMP	3
#define FAST_PWM_SET_COMP	4

#endif
