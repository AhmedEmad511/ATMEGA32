/*********************************************************************************/
/*********************************************************************************/
/********************         Author : Ahmed Emad          ***********************/
/********************         Layer  : RTOS                ***********************/
/********************         Virsion: 1.00                ***********************/
/********************         SWC    : RTOS                ***********************/
/*********************************************************************************/
/*********************************************************************************/

#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "../2-Timer0/TIMER_interface.h"
#include "../3-GIE/GIE_interface.h"

Task_t SystemTasks[TASK_NUM] ={{NULL}};

void RTOS_voidStart(void)
{
	TIMER0_u8COMPCallBackFunc(&voidScheduler);
	GIE_voidEnable();
	TIMER0_voidINIT();
}

u8 RTOS_u8CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay)
{
	u8 LocalErrorState = OK;
	/*Check if the Task is reserved*/

	if((SystemTasks[Copy_u8Priority].TaskFunc)==NULL)
	{
		SystemTasks[Copy_u8Priority].periodicity = Copy_u16Periodicity;

		SystemTasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;

		SystemTasks[Copy_u8Priority].State = RESUME;

		SystemTasks[Copy_u8Priority].First_Delay =Copy_u16FirstDelay;
	}
	/*If reserved dont create Task*/
	else
	{
		LocalErrorState=NOK;
	}
	return LocalErrorState;
}

static void voidScheduler(void)
{
	u8 loop_counter;

	for (loop_counter=0;loop_counter<TASK_NUM;loop_counter++)
	{
		if((SystemTasks[loop_counter].State)==RESUME)
		{
			if((SystemTasks[loop_counter].First_Delay)==0)
			{
				if(SystemTasks[loop_counter].TaskFunc != NULL)
				{
					SystemTasks[loop_counter].TaskFunc;
					SystemTasks[loop_counter].First_Delay= SystemTasks[loop_counter].periodicity-1;
				}
				else
				{
					//Do nothing
				}
			}
			else
			{
				SystemTasks[loop_counter].First_Delay--;
			}
		}
		else
		{
			//Do Nothing
		}
	}
}


void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = SUSPEND;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = RESUME;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc = NULL;
}

