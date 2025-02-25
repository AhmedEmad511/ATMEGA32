/******************************************************************************
 * Author: Mohamed Yasser
 *******************************************************************************/

#include "avr/io.h"
#include "adc.h"
#include "common_macros.h"



void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);
	ADCSRA = (1<<ADEN);
	ADCSRA=(ADCSRA&0xF8)|((Config_Ptr->prescaler)&0x07);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX&0xE0) | (channel_num&0x07) ;
		SET_BIT(ADCSRA,ADSC);
		while(BIT_IS_CLEAR(ADCSRA,ADIF));
		SET_BIT(ADCSRA,ADIF);
		return ADC;
}


