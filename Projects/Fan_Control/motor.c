#include"gpio.h"
#include"std_types.h"
#include"motor.h"
#include"pwm.h"

void Motor_Inti(void)
{
	/* make PB0 , PB1 Input pins */
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_writePort(PORTB_ID,0xFC); /*Stop motor by make PB0 , PB1 =0*/

}
void Motor_Diriction( Motor_State state,uint8 speed)
{
	PWM_timer0_inti(speed);

	if(state==STOP){

		GPIO_writePort(PORTB_ID,0xFC);
		/*PB0 , PB1=0 stop motor*/


	}
	else if(state==ANTI_CLOCKWISE){
		GPIO_writePort(PORTB_ID,0xFD);
		/*PB0=1,PB1=0 to Rotate the motor ANTI_CLOCKWISE */

	}
	else
	{
		/* PB0=0,PB1=1 to Rotate the motor CLOCKWISE*/
		GPIO_writePort(PORTB_ID,0xFE);

	}
}
