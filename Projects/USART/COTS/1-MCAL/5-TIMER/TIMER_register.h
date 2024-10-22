/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : TIMER               ***********************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

                                 /*TIMER_0 REGISTERS*/
#define TCCR0			*((volatile u8*)0x53)
#define TCCR0_WGM00 	6
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01     3
#define TCCR0_CS02		2
#define TCCR0_CS01		1
#define TCCR0_CS00		0

#define  OCR0			*((volatile u8*)0x5C)
#define  TIMSK			*((volatile u8*)0x59)
#define  TIMSK_OCIE0	1
#define  TIMSK_TOIE0	0


                                 /*TIMER_1 REGISTERS*/

#define TCCR1A			*((volatile u8*)0x4F)
#define TCCR1A_WGM10	0
#define TCCR1A_WGM11	1
#define TCCR1A_COM1B0	4
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1A1	7




#define TCCR1B			*((volatile u8*)0x4E)
#define TCCR1B_CS10		0
#define TCCR1B_CS11		1
#define TCCR1B_CS12		2
#define TCCR1B_WGM12	3
#define TCCR1B_WGM13	4
#define TCCR1B_ICES1	6
#define TCCR1B_ICNC1	7




#define ICR1			*((volatile u16*)0x46)



#define OCR1A			*((volatile u16*)0x4A)


#define TCNT1			*((volatile u16*)0x4C)

#define TIMSK_TICIE1		5


											/*WatchDog Timer*/

#define WDTCR			*((volatile u8*)0x41)
#define WDTCR_WDP0		0
#define WDTCR_WDP1		1
#define WDTCR_WDP2		2
#define WDTCR_WDE		3
#define WDTCR_WDTOE		4


#endif
