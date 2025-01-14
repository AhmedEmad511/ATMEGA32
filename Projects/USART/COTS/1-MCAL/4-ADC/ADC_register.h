/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : ADC                 ***********************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX         *((volatile u8*)0x27)  //ADC MULTIPLEXER Selection register
#define ADMUX_REFS1	  7                      //Reference selection bit1
#define ADMUX_REFS0   6                      //Reference selection bit0
#define ADMUX_ADLAR   5                      //ADC Left Adjust Result


#define ADCSRA        *((volatile u8*)0x26)  //ADC Control and Status Register A
#define ADCSRA_ADEN   7                      //ADC Enable
#define ADCSRA_ADSC   6                      //ADC Start Conversion
#define ADCSRA_ADATE  5                      //Auto Trigger Enable
#define ADCSRA_ADIF   4                      //Interrupt Flag
#define ADCSRA_ADIE   3                      //Interrupt Enable
#define ADCSRA_ADPS2  2                      //Prescaler Bit2
#define ADCSRA_ADPS1  1                      //Prescaler Bit1
#define ADCSRA_ADPS0  0                      //Prescaler Bit0


#define ADCH          *((volatile u8*)0x25)  //ADC High Register
#define ADCL          *((volatile u8*)0x24)  //ADC Low Register

#endif
