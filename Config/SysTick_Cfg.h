/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick_Cfg.h
 *       Module:  System Tick Timer
 *
 *  Description:  Used to Configure the System Tick Timer     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICKCFG_H
#define SYSTICKCFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



typedef enum
{
	INTERNAL_OCCILATOR = 0,
	SYSTEM_CLOCK
	
}Systick_ClockType;


typedef enum
{
	TIME_1_MS = 0,
	TIME_10_MS,
	TIME_100_MS,
	TIME_1000_MS

}Systick_TickTimeType;

typedef enum
{
	FLAG_LOW,
	FLAG_HIGH
	
}Systick_FlagType;


typedef struct
{
	Systick_TickTimeType TickTime;
	Systick_ClockType ClockType;
}Systick_ConfigType;

typedef uint32 Systick_ReloadValueType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern Systick_ConfigType SystickConfig;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/


