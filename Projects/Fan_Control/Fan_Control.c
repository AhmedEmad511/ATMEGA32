#include"adc.h"
#include"std_types.h"
#include"motor.h"
#include"lm35_sensor.h"
#include <stdlib.h>
int main (void)
{
	uint8 temp=0;
	ADC_ConfigType ADC_Configurations = {F_CPU_8,INTERNAL};
	ADC_init(&ADC_Configurations);
	Motor_Inti();
	LCD_init();
	LCD_moveCursor(0,3);
	LCD_displayString("FAN iS ");
	while(1)
	{
		temp=abs(LM35_getTemperature());
		if(temp<20)
		{
			Motor_Diriction(STOP,0);
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			if(temp<10)
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp);
			}
		}
		else if(temp>=20 && temp<60)
		{
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			Motor_Diriction(CLOCKWISE,75);
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			LCD_intgerToString(temp);

		}
		else if(temp>=60 && temp<90)
		{
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			Motor_Diriction(CLOCKWISE,75);
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			LCD_intgerToString(temp);

		}
		else if(temp>=90)
		{
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			Motor_Diriction(CLOCKWISE,100);
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
		}

	}
}

