/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Systick.c
 *        \brief  Systick Timer
 *
 *      \details  Source file for the Systick Timer Driver
 *                
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "SysTick_Cfg.h"
#include "SysTick.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 SystickCounter = 0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

static Callback_Ptr ptr_To_Systick_Callback = NULL_PTR;


/******************************************************************************
* \Syntax          : void Systick_Init(void)                                      
* \Description     : initialize the System Tick Timer 
*                                                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Init(void)
{ 
	
	
	/*Disable the Systick Timer*/
	CLEARBIT(SYSTICK_CTRL_R, 0);
	
	/*SELECT the System Clock Source*/
	if(SystickConfig.ClockType == INTERNAL_OCCILATOR)
	{
		CLEARBIT(SYSTICK_CTRL_R, 2);
	}
	else if(SystickConfig.ClockType == SYSTEM_CLOCK)
	{
		SETBIT(SYSTICK_CTRL_R, 2);
	}
	
	/*Set the Data in the Reload Register*/
	switch(SystickConfig.TickTime)
	{
		case TIME_1_MS: 	SYSTICK_RELOAD_R = (uint32)((0.001*SYSTEM_CLOCK_FREQUENCY)-1);break;
		case TIME_10_MS:	SYSTICK_RELOAD_R = (uint32)((0.01*SYSTEM_CLOCK_FREQUENCY)-1);break;
		case TIME_100_MS:	SYSTICK_RELOAD_R = (uint32)((0.1*SYSTEM_CLOCK_FREQUENCY)-1);break;
		case TIME_1000_MS:SYSTICK_RELOAD_R = (uint32)((1*SYSTEM_CLOCK_FREQUENCY)-1);break;
	}
	
	/*Enable the Systick Timer Interupt*/
	SETBIT(SYSTICK_CTRL_R, 1);
	
	/*Reset Current Value of the Counter (Write only but will zero once attempted write of any value)*/
	SYSTICK_CURRENT_R = 0;
	
	/*Enable the Systick Timer*/
	SETBIT(SYSTICK_CTRL_R, 0);

}

/******************************************************************************
* \Syntax          : Systick_FlagType Systick_Read_Flag(void)                                      
* \Description     : Read the Systick Flag 
*                                                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): Systick_FlagType                                                      
* \Return value:   : Systick_FlagType
*******************************************************************************/

Systick_FlagType Systick_Read_Flag(void)
{
	return (Systick_FlagType)((SYSTICK_CTRL_R>>16)&0x1);
}

/******************************************************************************
* \Syntax          : Systick_ReloadValueType Systick_Read_Current_Value(void)                                     
* \Description     : Read the Systick tick Count Value 
*                                                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): Systick_ReloadValueType                                                      
* \Return value:   : Systick_ReloadValueType
*******************************************************************************/

Systick_ReloadValueType Systick_Read_Current_Value(void)
{
	return (Systick_ReloadValueType)SYSTICK_CURRENT_R;
}


/******************************************************************************
* \Syntax          : void SysTick_Add_Callback(Callback_Ptr Func)                                     
* \Description     : Setup Callback for Systick Interupt Handler 
*                                                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void SysTick_Add_Callback(Callback_Ptr Func)
{
	ptr_To_Systick_Callback = Func;
}

/******************************************************************************
* \Syntax          : void SysTick_Handler(void)                                     
* \Description     : Systick Interupt Handler 
*                                                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Handler()
{
	if(ptr_To_Systick_Callback != NULL_PTR)
	{
		ptr_To_Systick_Callback();
	}
}



/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
