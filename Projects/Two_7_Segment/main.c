#include <avr/io.h>
#include <util/delay.h>
#include "../BIT_MATH.h"
#include "../STD_TYPES.h"
void main (void){
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
	u8 segmentB[10] = {
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
	DDRB=0xff;
	while (1){
	for(u8 j=0; j<10;j++){
		PORTB= segmentB[j];
		for(u8 i=0; i<10;i++){
			PORTA =segmentA[i];
			_delay_ms(200);
			PORTA=0;
			_delay_ms(200);
		}
	}
	}
}

