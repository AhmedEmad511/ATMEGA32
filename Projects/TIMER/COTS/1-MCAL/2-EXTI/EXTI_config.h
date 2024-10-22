/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : EXTI                ***********************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
#include "EXTI_private.h"

#define INT0 	1
#define INT1 	2
#define INT2 	3

/*For INT0 and INT1
 *  1-LOW_LEVEL
 * 2-ON_CHANGE
 * 3-FALLING_EDGE
 * 4-RISING_EDGE*/
#define INT0_SENSE	   FALLING_EDGE

/*Options 1-ENABLE
 * 2-DISABLE*/

#define INT0_INITIAL   ENABLE




#define INT1_SENSE	FALLING_EDGE
#define INT1_INITIAL   ENABLE



/*Options 1-FALLING_EDGE
 * 2-RISING_EDGE*/
#define INT2_SENSE	FALLING_EDGE
#define INT2_INITIAL   ENABLE

#endif
