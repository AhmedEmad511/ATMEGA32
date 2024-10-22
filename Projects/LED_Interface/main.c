#include <avr/io.h>
#include <util/delay.h>
#include "../BIT_MATH.h"
#include "../STD_TYPES.h"
void main (void){
	DDRB=0;
	PORTB=1;
	u8 segmentA[10] = {
			0b00111111,
			0b00000110,
			0b01011011,
			0b01001111,
			0b01100110,
			0b01101101,
			0b01111100,
			0b00000111,
			0b01111111,
			0b01101111};
	DDRA = 0xff;
	u8 i=0;
	while(1){
	u8 x = GET_BIT(PINB,0);
	if(x==0){
		PORTA = segmentA[i];
		_delay_ms(500);
		PORTA =0;
		i++;
	}
	if(i==10)
		i=0;
	}
}

