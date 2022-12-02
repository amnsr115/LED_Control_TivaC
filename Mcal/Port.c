/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  
 *
 *      \details  Source File: Used for the Initalization of Ports
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Port_Cfg.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init(void)        
* \Description     : Initalize the Port as a GPIO or an alternative function from the configuration file                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None  
*                                                                     
*******************************************************************************/
void Port_Init(void)
{
	uint8 pins= 0;
	for(pins = 0; pins < PORT_PINS_USED_NUMBER; pins++)
	{
		
	/*					1. Enable Clock to the desired Port					*/ 
		SETBIT(SYSCTL_GPIO_RCGC_R, PinConfigurations[pins].portNum);						
		while(!(SYSCTL_GPIO_RCGC_R & 1U<<PinConfigurations[pins].portNum)){}		/*Hault until clock reaches the system*/
			
		
			
	/*////////////////////////////////////////////////////////////////////*/		
		switch(PinConfigurations[pins].portNum)																	/*Switch case to find which port the pin belongs to*/
		{
			case PORTA:
	/*    Unlock the Port for Modificaltion and Commit register to modify pin*/
				GPIO_PORTA_LOCK_R	= 0x4C4F434B;
				SETBIT(GPIO_PORTA_CR_R,PinConfigurations[pins].pinNum); 
			
	/*					2. Set Direction as Input or Output												*/
				if(PinConfigurations[pins].pinDir == OUTPUT)												
				{
					SETBIT(GPIO_PORTA_DIR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTA_DIR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/			
	/*					3. Set the Pin Mode if its DIO or Alternative Function		*/			
				if(PinConfigurations[pins].pinMode == PORT_PIN_MODE_DIO && PinConfigurations[pins].pinOutput==DIGITAL)						
				{
					CLEARBIT(GPIO_PORTA_AFSEL_R, PinConfigurations[pins].pinNum);
				}
				else
				{
					SETBIT(GPIO_PORTA_AFSEL_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					4. Set the Output Current 																*/			
				if(PinConfigurations[pins].outCurrent == OUTPUT_2mA)
				{
					CLEARBIT(GPIO_PORTA_DR4R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTA_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTA_DR2R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_4mA)
				{
					CLEARBIT(GPIO_PORTA_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTA_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTA_DR4R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_8mA)
				{
					CLEARBIT(GPIO_PORTA_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTA_DR4R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTA_DR8R_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					5. Set the Internal Attachment for inputs 								*/				
				
				if(PinConfigurations[pins].internalAttach == PDR)
				{
					CLEARBIT(GPIO_PORTA_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTA_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTA_PDR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == PUR)
				{
					CLEARBIT(GPIO_PORTA_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTA_PDR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTA_PUR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == ODR)
				{
					CLEARBIT(GPIO_PORTA_PDR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTA_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTA_ODR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					6. Set the Diginal Enable 								 								*/				
				if(PinConfigurations[pins].pinOutput == DIGITAL)
				{
					SETBIT(GPIO_PORTA_DEN_R,PinConfigurations[pins].pinNum);
				}
			
	/*///////////////////////////////////////////////////////////////////////*/
	/*					7. Setup the interupt for inputs														*/
				if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTA_IS_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTA_IBE_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTA_IEV_R,PinConfigurations[pins].pinNum);
					GPIO_PORTA_ICR_R = 0;
					SETBIT(GPIO_PORTA_IM_R,PinConfigurations[pins].pinNum);
				}
				break;
			case PORTB:
	/*    Unlock the Port for Modificaltion and Commit register to modify pin*/
				GPIO_PORTB_LOCK_R	= 0x4C4F434B;
				SETBIT(GPIO_PORTB_CR_R,PinConfigurations[pins].pinNum); 
			
	/*					2. Set Direction as Input or Output												*/
				if(PinConfigurations[pins].pinDir == OUTPUT)												
				{
					SETBIT(GPIO_PORTB_DIR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTB_DIR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/			
	/*					3. Set the Pin Mode if its DIO or Alternative Function		*/			
				if(PinConfigurations[pins].pinMode == PORT_PIN_MODE_DIO && PinConfigurations[pins].pinOutput==DIGITAL)						
				{
					CLEARBIT(GPIO_PORTB_AFSEL_R, PinConfigurations[pins].pinNum);
				}
				else
				{
					SETBIT(GPIO_PORTB_AFSEL_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					4. Set the Output Current 																*/			
				if(PinConfigurations[pins].outCurrent == OUTPUT_2mA)
				{
					CLEARBIT(GPIO_PORTB_DR4R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTB_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTB_DR2R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_4mA)
				{
					CLEARBIT(GPIO_PORTB_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTB_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTB_DR4R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_8mA)
				{
					CLEARBIT(GPIO_PORTB_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTB_DR4R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTB_DR8R_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					5. Set the Internal Attachment for inputs 								*/				
				
				if(PinConfigurations[pins].internalAttach == PDR)
				{
					CLEARBIT(GPIO_PORTB_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTB_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTB_PDR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == PUR)
				{
					CLEARBIT(GPIO_PORTB_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTB_PDR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTB_PUR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == ODR)
				{
					CLEARBIT(GPIO_PORTB_PDR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTB_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTB_ODR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					6. Set the Diginal Enable 								 								*/				
				if(PinConfigurations[pins].pinMode == DIGITAL)
				{
					SETBIT(GPIO_PORTB_DEN_R,PinConfigurations[pins].pinNum);
				}
	/*///////////////////////////////////////////////////////////////////////*/
	/*					7. Setup the interupt for inputs														*/
				if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTB_IS_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTB_IBE_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTB_IEV_R,PinConfigurations[pins].pinNum);
					GPIO_PORTB_ICR_R = 0;
					SETBIT(GPIO_PORTB_IM_R,PinConfigurations[pins].pinNum);
				}
				break;
			case PORTC:
				
/*    Unlock the Port for Modificaltion and Commit register to modify pin*/
				GPIO_PORTC_LOCK_R	= 0x4C4F434B;
				SETBIT(GPIO_PORTC_CR_R,PinConfigurations[pins].pinNum); 
			
			
	/*					2. Set Direction as Input or Output												*/
				if(PinConfigurations[pins].pinDir == OUTPUT)												
				{
					SETBIT(GPIO_PORTC_DIR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTC_DIR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/			
	/*					3. Set the Pin Mode if its DIO or Alternative Function		*/			
				if(PinConfigurations[pins].pinMode == PORT_PIN_MODE_DIO && PinConfigurations[pins].pinOutput==DIGITAL)						
				{
					CLEARBIT(GPIO_PORTC_AFSEL_R, PinConfigurations[pins].pinNum);
				}
				else
				{
					SETBIT(GPIO_PORTC_AFSEL_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					4. Set the Output Current 																*/			
				if(PinConfigurations[pins].outCurrent == OUTPUT_2mA)
				{
					CLEARBIT(GPIO_PORTC_DR4R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTC_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTC_DR2R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_4mA)
				{
					CLEARBIT(GPIO_PORTC_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTC_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTC_DR4R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_8mA)
				{
					CLEARBIT(GPIO_PORTC_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTC_DR4R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTC_DR8R_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					5. Set the Internal Attachment for inputs 								*/				
				
				if(PinConfigurations[pins].internalAttach == PDR)
				{
					CLEARBIT(GPIO_PORTC_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTC_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTC_PDR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == PUR)
				{
					CLEARBIT(GPIO_PORTC_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTC_PDR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTC_PUR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == ODR)
				{
					CLEARBIT(GPIO_PORTC_PDR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTC_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTC_ODR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					6. Set the Diginal Enable 								 								*/				
				if(PinConfigurations[pins].pinMode == DIGITAL)
				{
					SETBIT(GPIO_PORTC_DEN_R,PinConfigurations[pins].pinNum);
				}				
	/*///////////////////////////////////////////////////////////////////////*/
	/*					7. Setup the interupt for inputs														*/
				if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTC_IS_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTC_IBE_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTC_IEV_R,PinConfigurations[pins].pinNum);
					GPIO_PORTC_ICR_R = 0;
					SETBIT(GPIO_PORTC_IM_R,PinConfigurations[pins].pinNum);
				}
				break;
			case PORTD:
				
	/*    Unlock the Port for Modificaltion and Commit register to modify pin*/
				GPIO_PORTD_LOCK_R	= 0x4C4F434B;
				SETBIT(GPIO_PORTD_CR_R,PinConfigurations[pins].pinNum); 
			
			
	/*					2. Set Direction as Input or Output												*/
				if(PinConfigurations[pins].pinDir == OUTPUT)												
				{
					SETBIT(GPIO_PORTD_DIR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTD_DIR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/			
	/*					3. Set the Pin Mode if its DIO or Alternative Function		*/			
				if(PinConfigurations[pins].pinMode == PORT_PIN_MODE_DIO && PinConfigurations[pins].pinOutput==DIGITAL)						
				{
					CLEARBIT(GPIO_PORTD_AFSEL_R, PinConfigurations[pins].pinNum);
				}
				else
				{
					SETBIT(GPIO_PORTD_AFSEL_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					4. Set the Output Current 																*/			
				if(PinConfigurations[pins].outCurrent == OUTPUT_2mA)
				{
					CLEARBIT(GPIO_PORTD_DR4R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTD_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTD_DR2R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_4mA)
				{
					CLEARBIT(GPIO_PORTD_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTD_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTD_DR4R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_8mA)
				{
					CLEARBIT(GPIO_PORTD_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTD_DR4R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTD_DR8R_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					5. Set the Internal Attachment for inputs 								*/				
				
				if(PinConfigurations[pins].internalAttach == PDR)
				{
					CLEARBIT(GPIO_PORTD_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTD_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTD_PDR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == PUR)
				{
					CLEARBIT(GPIO_PORTD_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTD_PDR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTD_PUR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == ODR)
				{
					CLEARBIT(GPIO_PORTD_PDR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTD_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTD_ODR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					6. Set the Diginal Enable 								 								*/				
				if(PinConfigurations[pins].pinMode == DIGITAL)
				{
					SETBIT(GPIO_PORTD_DEN_R,PinConfigurations[pins].pinNum);
				}
	/*///////////////////////////////////////////////////////////////////////*/
	/*					7. Setup the interupt for inputs														*/
				if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTD_IS_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTD_IBE_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTD_IEV_R,PinConfigurations[pins].pinNum);
					GPIO_PORTD_ICR_R = 0;
					SETBIT(GPIO_PORTD_IM_R,PinConfigurations[pins].pinNum);
				}
				
				break;
			case PORTE:
				
	/*    Unlock the Port for Modificaltion and Commit register to modify pin*/
				GPIO_PORTE_LOCK_R	= 0x4C4F434B;
				SETBIT(GPIO_PORTE_CR_R,PinConfigurations[pins].pinNum); 
			
			
	/*					2. Set Direction as Input or Output												*/
				if(PinConfigurations[pins].pinDir == OUTPUT)												
				{
					SETBIT(GPIO_PORTE_DIR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTE_DIR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/			
	/*					3. Set the Pin Mode if its DIO or Alternative Function		*/			
				if(PinConfigurations[pins].pinMode == PORT_PIN_MODE_DIO && PinConfigurations[pins].pinOutput==DIGITAL)						
				{
					CLEARBIT(GPIO_PORTE_AFSEL_R, PinConfigurations[pins].pinNum);
				}
				else
				{
					SETBIT(GPIO_PORTE_AFSEL_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					4. Set the Output Current 																*/			
				if(PinConfigurations[pins].outCurrent == OUTPUT_2mA)
				{
					CLEARBIT(GPIO_PORTE_DR4R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTE_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTE_DR2R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_4mA)
				{
					CLEARBIT(GPIO_PORTE_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTE_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTE_DR4R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_8mA)
				{
					CLEARBIT(GPIO_PORTE_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTE_DR4R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTE_DR8R_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					5. Set the Internal Attachment for inputs 								*/				
				
				if(PinConfigurations[pins].internalAttach == PDR)
				{
					CLEARBIT(GPIO_PORTE_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTE_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTE_PDR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == PUR)
				{
					CLEARBIT(GPIO_PORTE_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTE_PDR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTE_PUR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == ODR)
				{
					CLEARBIT(GPIO_PORTE_PDR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTE_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTE_ODR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					6. Set the Diginal Enable 								 								*/				
				if(PinConfigurations[pins].pinMode == DIGITAL)
				{
					SETBIT(GPIO_PORTE_DEN_R,PinConfigurations[pins].pinNum);
				}
	/*///////////////////////////////////////////////////////////////////////*/
	/*					7. Setup the interupt for inputs														*/
				if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTE_IS_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTE_IBE_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTE_IEV_R,PinConfigurations[pins].pinNum);
					GPIO_PORTE_ICR_R = 0;
					SETBIT(GPIO_PORTE_IM_R,PinConfigurations[pins].pinNum);
				}
				
				break;
			case PORTF:
				
	/*    Unlock the Port for Modificaltion and Commit register to modify pin*/
				GPIO_PORTF_LOCK_R	= 0x4C4F434B;
				SETBIT(GPIO_PORTF_CR_R,PinConfigurations[pins].pinNum); 
	
	/*					2. Set Direction as Input or Output												*/
				if(PinConfigurations[pins].pinDir == OUTPUT)												
				{
					SETBIT(GPIO_PORTF_DIR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTF_DIR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/			
	/*					3. Set the Pin Mode if its DIO or Alternative Function		*/			
				if(PinConfigurations[pins].pinMode == PORT_PIN_MODE_DIO && PinConfigurations[pins].pinOutput==DIGITAL)						
				{
					CLEARBIT(GPIO_PORTF_AFSEL_R, PinConfigurations[pins].pinNum);
				}
				else
				{
					SETBIT(GPIO_PORTF_AFSEL_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					4. Set the Output Current 																*/			
				if(PinConfigurations[pins].outCurrent == OUTPUT_2mA)
				{
					CLEARBIT(GPIO_PORTF_DR4R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTF_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTF_DR2R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_4mA)
				{
					CLEARBIT(GPIO_PORTF_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTF_DR8R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTF_DR4R_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].outCurrent == OUTPUT_8mA)
				{
					CLEARBIT(GPIO_PORTF_DR2R_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTF_DR4R_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTF_DR8R_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					5. Set the Internal Attachment for inputs 								*/				
				
				if(PinConfigurations[pins].internalAttach == PDR)
				{
					CLEARBIT(GPIO_PORTF_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTF_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTF_PDR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == PUR)
				{
					CLEARBIT(GPIO_PORTF_ODR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTF_PDR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTF_PUR_R, PinConfigurations[pins].pinNum);
				}
				else if(PinConfigurations[pins].internalAttach == ODR)
				{
					CLEARBIT(GPIO_PORTF_PDR_R, PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTF_PUR_R, PinConfigurations[pins].pinNum);
					SETBIT(GPIO_PORTF_ODR_R, PinConfigurations[pins].pinNum);
				}
	/*////////////////////////////////////////////////////////////////////*/
	/*					6. Set the Diginal Enable 								 								*/				
				if(PinConfigurations[pins].pinMode == DIGITAL)
				{
					SETBIT(GPIO_PORTF_DEN_R,PinConfigurations[pins].pinNum);
				}
	/*///////////////////////////////////////////////////////////////////////*/
	/*					7. Setup the interupt for inputs														*/

				if(PinConfigurations[pins].pinDir == INPUT)
				{
					CLEARBIT(GPIO_PORTF_IS_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTF_IBE_R,PinConfigurations[pins].pinNum);
					CLEARBIT(GPIO_PORTF_IEV_R,PinConfigurations[pins].pinNum);
					GPIO_PORTF_ICR_R = 0;
					SETBIT(GPIO_PORTF_IM_R,PinConfigurations[pins].pinNum);
				}
				break;
			
		}
		
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
