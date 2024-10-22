
#include"gpio.h"
#include<avr/io.h>
#include"pwm.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void PWM_timer0_inti(uint8 duty_cycle){
	uint8 value=0;
	/*initialize The Timer*/
	TCNT0=0;
	/*
	 WGM00,WGM01 To Setup FastPwm Mode
	 COM01 For non-inverting mode
	 CS01 For cpu_clk/8
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

	value=(uint8)(((float32)duty_cycle/100)*255);


	/*to make output Waveform  on OCR0*/
	OCR0  = value;
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);/*To Generate The Waveform On PB3*/
}
