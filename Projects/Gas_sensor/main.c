#include<avr/io.h>
#include<util/delay.h>


#include "servo.h"


int main()
{
	servo_init();	//Initializing the servo

	while (1)
	{
	//  NOTE: Any angle of rotation(0 to 180) can be given

  	set_degree(0);		//For 90 degree rotation
  	_delay_ms(1000);	//Delay for 1s

	set_degree(180);	//For 180 degree rotation
	_delay_ms(1000);	//Delay for 1s

	}

}
