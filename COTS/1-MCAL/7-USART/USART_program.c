/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : USART               ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "USART_interface.h"

void USART_voidInit(void)
{
	u8 Local_u8UCSRC=0;
	/*Write on UCSRC needs to be as such 0b1xxxxxxx*/
	/*Set Async mode && no parity && 1 Stop bit && 8-bit mode */
	SET_BIT(Local_u8UCSRC,URSEL);
	CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCPOL);
	CLR_BIT(Local_u8UCSRC,UCSRC_USBS);
	CLR_BIT(Local_u8UCSRC,UCSRC_UMP0);
	CLR_BIT(Local_u8UCSRC,UCSRC_UMP1);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	UCSRC=Local_u8UCSRC;
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	/*Set BPS to 9600*/
	UBRRL=51;

	/*Enable TX and RX*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);
}



void USART_voidSendData(u8 Data)
{
	/*Wait until the Flag is Set*/
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);

	UDR=Data;
}



u8 USART_u8ReadData(void)
{
	/*Wait Until the recieve is complete*/
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);

	return UDR;
}

