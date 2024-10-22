
#ifndef MOTOR_H_
#define MOTOR_H_

/*******************************************************************************
 *                     Enum                             *
 *******************************************************************************/
typedef enum{
	STOP=0xFC,ANTI_CLOCKWISE=0xFD,CLOCKWISE=0xFE
}Motor_State;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the DC_motor driver.
 */
void Motor_Init(void);
/*
 * Description :
 * Function responsible for Taking The State And Speed As AN Input And Adjust The Motor According To Them
 */
void DcMotor_Rotate(Motor_State state,uint8 speed);


#endif /* MOTOR_H_ */
