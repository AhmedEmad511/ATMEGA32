/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : ADC                 ***********************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_ADJUST 	ENABLE

#define ADC_PRESC DIV_BY128

#define DIV_BY2 	1
#define DIV_BY4		2
#define DIV_BY8 	3
#define DIV_BY16	4
#define DIV_BY32	5
#define DIV_BY64	6
#define DIV_BY128	7

#define ADC_u32TIMEOUT 50000

#define OK  	   0
#define NOK 	   1
#define BUSY_ERROR 2

#define IDLE 0
#define BUSY 1

#endif
