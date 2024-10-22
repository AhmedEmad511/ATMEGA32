 /******************************************************************************
 * Author: Mohamed Abdelsalam
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum
{
	AREF,AVCC,INTERNAL=3
}ADC_ReferenceVolatge;

typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;


typedef struct
{
	ADC_Prescaler prescaler;
	ADC_ReferenceVolatge  ref_volt;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 channel_num);

#endif
