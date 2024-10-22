/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : USART               ***********************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_


#define UDR     			*((volatile u8*)0x2C)     //USART Data register for read or Write.


#define UCSRA      			*((volatile u8*)0x2B)
#define UCSRA_RXC			7
#define UCSRA_TXC			6
#define UCSRA_UDRE			5



#define UCSRB       		*((volatile u8*)0x2A)
#define UCSRB_TXEN			4
#define UCSRB_RXEN			3
#define UCSRB_UCSZ2			2



#define UCSRC       		*((volatile u8*)0x40)			//To use this Register look at program.c
#define URSEL				7
#define UCSRC_UMSEL			6
#define UCSRC_UMP0			5
#define UCSRC_UMP1			4
#define UCSRC_USBS			3
#define UCSRC_UCSZ1			2
#define UCSRC_UCSZ0			1
#define UCSRC_UCPOL			0

#define UBRRL       		*((volatile u8*)0x29)


#endif
