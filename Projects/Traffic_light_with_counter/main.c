#include <avr/io.h>
#include <util/delay.h>
#include "../BIT_MATH.h"
#include "../STD_TYPES.h"
void main(void) {
	DDRB = 0;
	PORTB = 0b11111111;
	DDRC = 0xff;
	u8 segmentA[10] = { 0b00111111, 0b00000110, 0b01011011, 0b01001111,
			0b01100110, 0b01101101, 0b01111100, 0b00000111, 0b01111111,
			0b01101111 };
	DDRA = 0xff;
	s8 i;
	while (1) {
		//u8 x =PINB ;
		if (PINB == 0b11111110) {
			for (i = 9; i > 0; i--) {
				PORTC = 1;
				PORTA = segmentA[i];
				_delay_ms(800);
				PORTA = 0;
				/*if(i==0)
				 break;*/
			}
			PORTC = 0;
			//_delay_ms(1000);
			for (i = 5; i > 0; i--) {
				PORTC = 2;
				PORTA = segmentA[i];
				_delay_ms(800);
				PORTA = 0;
				if (i == 0)
					break;
			}
			PORTC = 0;
			//_delay_ms(1000);
			for (i = 9; i > 0; i--) {
				PORTC = 4;
				PORTA = segmentA[i];
				_delay_ms(800);
				PORTA = 0;
				if (i == 0)
					break;
			}
			PORTC = 0;
			_delay_ms(1000);

		}
	}

}

