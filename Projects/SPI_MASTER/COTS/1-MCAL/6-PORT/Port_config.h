/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : MCAL                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : PORT                ***********************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*Choose 1 --> Output || 0 --> Input*/

#define PORTA_PIN0_DIR  0
#define PORTA_PIN1_DIR  0
#define PORTA_PIN2_DIR  0
#define PORTA_PIN3_DIR  0
#define PORTA_PIN4_DIR  0
#define PORTA_PIN5_DIR  0
#define PORTA_PIN6_DIR  0
#define PORTA_PIN7_DIR  0

#define PORTB_PIN0_DIR  0
#define PORTB_PIN1_DIR  0
#define PORTB_PIN2_DIR  0
#define PORTB_PIN3_DIR  0
#define PORTB_PIN4_DIR  0			/*SS Input PULL up*/
#define PORTB_PIN5_DIR  1			/*MOSI*/
#define PORTB_PIN6_DIR  0			/*MISO*/
#define PORTB_PIN7_DIR  1			/*SCK*/

#define PORTC_PIN0_DIR  0
#define PORTC_PIN1_DIR  0
#define PORTC_PIN2_DIR  0
#define PORTC_PIN3_DIR  0
#define PORTC_PIN4_DIR  0
#define PORTC_PIN5_DIR  0
#define PORTC_PIN6_DIR  0
#define PORTC_PIN7_DIR  0

#define PORTD_PIN0_DIR  0
#define PORTD_PIN1_DIR  0
#define PORTD_PIN2_DIR  0
#define PORTD_PIN3_DIR  0
#define PORTD_PIN4_DIR  0
#define PORTD_PIN5_DIR  0
#define PORTD_PIN6_DIR  0
#define PORTD_PIN7_DIR  0


/*Select 0 for initially LOW as OUTPUT and FLOATING as INPUT */
/*Select 1 for initially HIGH as OUTPUT and PULL-UP as INPUT */


#define PORTA_PIN0_INT  0
#define PORTA_PIN1_INT  0
#define PORTA_PIN2_INT  0
#define PORTA_PIN3_INT  0
#define PORTA_PIN4_INT  0
#define PORTA_PIN5_INT  0
#define PORTA_PIN6_INT  0
#define PORTA_PIN7_INT  0

#define PORTB_PIN0_INT  0
#define PORTB_PIN1_INT  0
#define PORTB_PIN2_INT  0
#define PORTB_PIN3_INT  0
#define PORTB_PIN4_INT  1
#define PORTB_PIN5_INT  0
#define PORTB_PIN6_INT  0
#define PORTB_PIN7_INT  0

#define PORTC_PIN0_INT  0
#define PORTC_PIN1_INT  0
#define PORTC_PIN2_INT  0
#define PORTC_PIN3_INT  0
#define PORTC_PIN4_INT  0
#define PORTC_PIN5_INT  0
#define PORTC_PIN6_INT  0
#define PORTC_PIN7_INT  0

#define PORTD_PIN0_INT  0
#define PORTD_PIN1_INT  0
#define PORTD_PIN2_INT  0
#define PORTD_PIN3_INT  0
#define PORTD_PIN4_INT  0
#define PORTD_PIN5_INT  0
#define PORTD_PIN6_INT  0
#define PORTD_PIN7_INT  0

#endif
