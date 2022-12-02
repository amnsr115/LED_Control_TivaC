/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


void IntCrtl_Init(void)
{
	

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
	
    NVIC_APINT_R = NVIC_APINT_VECTKEY|INTCRTL_PRIORITY_SPLIT;
	
    	for(uint8 i=0;i<INTCTRL_INTERUPTS_USED;i++){
		uint8 intNum=IntConfigurations[i].IntNumber-16;
				
		uint16 enableOffset = 0x100 + ((intNum/32)*4U);
		uint16 priorityOffset = 0x400 + ((intNum/4)*4U);
		uint16 priorityByteShift = ((intNum%4));
				
		
		// Set Priorty register in NVIC

		RegisterWrite(NVIC_Base+priorityOffset) = (uint32)(IntConfigurations[i].IntSubPriority)<<(5 + 8U*priorityByteShift);
		//Enable register in NVIC
		RegisterWrite(NVIC_Base+enableOffset) = 1<<intNum;
				
				

		
	}


	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
