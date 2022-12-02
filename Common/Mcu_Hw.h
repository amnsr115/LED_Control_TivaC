/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef void(*Callback_Ptr)(void);



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SYSTEM_CLOCK_FREQUENCY									16000000U




#define CORTEXM4_PERI_BASE_ADDRESS             	0xE000E000
#define NVIC_APINT_R                            *((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                	*((volatile unsigned long*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))



#define NVIC_APINT_VECTKEY      								0x05FA0000  // Vector key
#define NVIC_PRI_R                            	CORTEXM4_PERI_BASE_ADDRESS+0x400
#define NVIC_ACCESS_PRIORITY_REGERSTER(A)       *((volatile unsigned long*)(NVIC_PRI_R+(A*4)))



/*Priority Configurations*/
#define NVIC_APINT_PRIGROUP_7_1 0x00000000 
#define NVIC_APINT_PRIGROUP_6_2 0x00000100  
#define NVIC_APINT_PRIGROUP_5_3 0x00000200  
#define NVIC_APINT_PRIGROUP_4_4 0x00000300  
#define NVIC_APINT_PRIGROUP_3_5 0x00000400  
#define NVIC_APINT_PRIGROUP_2_6 0x00000500  
#define NVIC_APINT_PRIGROUP_1_7 0x00000600  
#define NVIC_APINT_PRIGROUP_0_8 0x00000700  





/*System Clock Module Registers*/
#define SYSCTL_BASE_ADDRESS 										0x400FE000
#define SYSCTL_GPIO_RCGC_R											(*((volatile unsigned long *)(SYSCTL_BASE_ADDRESS + 0x608)))





/*System Tick Timer Registers*/
#define SYSTICK_BASE_R													0xE000E000
#define SYSTICK_CTRL_R													(*((volatile unsigned long *)(SYSTICK_BASE_R + 0x010)))
#define SYSTICK_RELOAD_R												(*((volatile unsigned long *)(SYSTICK_BASE_R + 0x014)))
#define SYSTICK_CURRENT_R												(*((volatile unsigned long *)(SYSTICK_BASE_R + 0x018)))




/*GPIO Offset for all the Ports*/
#define GPIO_DATA_OFFSET    						0x000 
#define GPIO_DATA_MOD_OFFSET    				0x3FC 		/*Data*/
#define GPIO_DIR_OFFSET       					0x400 		/*Direction*/
#define GPIO_IS_OFFSET									0x404
#define GPIO_IBE_OFFSET									0x408
#define GPIO_IEV_OFFSET									0x40C
#define GPIO_IM_OFFSET									0x410
#define GPIO_MIS_OFFSET									0x418
#define GPIO_ICR_OFFSET									0x41C
#define GPIO_AFSEL_OFFSET      					0x420			/*Alternative Function Select*/
#define GPIO_DR2R_OFFSET        				0x500 		/*2mA Drive Select Register*/
#define GPIO_DR4R_OFFSET        				0x504 		/*4mA Drive Select Register*/
#define GPIO_DR8R_OFFSET        				0x508 		/*8mA Drive Select Register*/
#define GPIO_ODR_OFFSET         				0x50C 
#define GPIO_PUR_OFFSET         				0x510 
#define GPIO_PDR_OFFSET         				0x514 
#define GPIO_SLR_OFFSET         				0x518 
#define GPIO_DEN_OFFSET         				0x51C 
#define GPIO_LOCK_OFFSET        				0x520 
#define GPIO_CR_OFFSET          				0x524 
#define GPIO_AMSEL_OFFSET 							0x528
#define GPIO_PCTL_OFFSET        				0x52C 


/*GPIO REGISTERS for PORT A*/
#define GPIO_PORTA_BASE_ADDRESS					0x40004000
#define GPIO_PORTA_MOD_DATA_R						(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_DATA_MOD_OFFSET)))
#define GPIO_PORTA_DATA_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_DATA_OFFSET)))
#define GPIO_PORTA_DIR_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_DIR_OFFSET)))
	
#define GPIO_PORTA_IS_R									(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_IS_OFFSET)))
#define GPIO_PORTA_IBE_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_IBE_OFFSET)))
#define GPIO_PORTA_IEV_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_IEV_OFFSET)))
#define GPIO_PORTA_IM_R									(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_IM_OFFSET)))
#define GPIO_PORTA_ICR_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_ICR_OFFSET)))

#define GPIO_PORTA_AFSEL_R							(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_AFSEL_OFFSET)))
#define GPIO_PORTA_DR2R_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_DR2R_OFFSET)))
#define GPIO_PORTA_DR4R_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_DR4R_OFFSET)))
#define GPIO_PORTA_DR8R_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_DR8R_OFFSET)))
#define GPIO_PORTA_ODR_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_ODR_OFFSET)))
#define GPIO_PORTA_PUR_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_PUR_OFFSET)))
#define GPIO_PORTA_PDR_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_PDR_OFFSET)))
#define GPIO_PORTA_SLR_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_SLR_OFFSET)))
#define GPIO_PORTA_DEN_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_DEN_OFFSET)))
#define GPIO_PORTA_LOCK_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_LOCK_OFFSET)))
#define GPIO_PORTA_CR_R									(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_CR_OFFSET)))
#define GPIO_PORTA_ASMEL_R							(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_AMSEL_OFFSET)))
#define GPIO_PORTA_PCTL_R								(*((volatile unsigned long *)(GPIO_PORTA_BASE_ADDRESS + GPIO_PCTL_OFFSET)))



/*GPIO REGISTERS for PORT B*/
#define GPIO_PORTB_BASE_ADDRESS					0x40005000
#define GPIO_PORTB_MOD_DATA_R						(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_DATA_MOD_OFFSET)))
#define GPIO_PORTB_DATA_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_DATA_OFFSET)))
#define GPIO_PORTB_DIR_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_DIR_OFFSET)))

#define GPIO_PORTB_IS_R									(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_IS_OFFSET)))
#define GPIO_PORTB_IBE_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_IBE_OFFSET)))
#define GPIO_PORTB_IEV_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_IEV_OFFSET)))
#define GPIO_PORTB_IM_R									(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_IM_OFFSET)))
#define GPIO_PORTB_ICR_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_ICR_OFFSET)))
	
#define GPIO_PORTB_AFSEL_R							(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_AFSEL_OFFSET)))
#define GPIO_PORTB_DR2R_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_DR2R_OFFSET)))
#define GPIO_PORTB_DR4R_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_DR4R_OFFSET)))
#define GPIO_PORTB_DR8R_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_DR8R_OFFSET)))
#define GPIO_PORTB_ODR_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_ODR_OFFSET)))
#define GPIO_PORTB_PUR_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_PUR_OFFSET)))
#define GPIO_PORTB_PDR_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_PDR_OFFSET)))
#define GPIO_PORTB_SLR_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_SLR_OFFSET)))
#define GPIO_PORTB_DEN_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_DEN_OFFSET)))
#define GPIO_PORTB_LOCK_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_LOCK_OFFSET)))
#define GPIO_PORTB_CR_R									(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_CR_OFFSET)))
#define GPIO_PORTB_ASMEL_R							(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_AMSEL_OFFSET)))
#define GPIO_PORTB_PCTL_R								(*((volatile unsigned long *)(GPIO_PORTB_BASE_ADDRESS + GPIO_PCTL_OFFSET)))



/*GPIO REGISTERS for PORT C*/
#define GPIO_PORTC_BASE_ADDRESS					0x40006000
#define GPIO_PORTC_MOD_DATA_R						(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_DATA_MOD_OFFSET)))
#define GPIO_PORTC_DATA_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_DATA_OFFSET)))
#define GPIO_PORTC_DIR_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_DIR_OFFSET)))
	
#define GPIO_PORTC_IS_R									(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_IS_OFFSET)))
#define GPIO_PORTC_IBE_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_IBE_OFFSET)))
#define GPIO_PORTC_IEV_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_IEV_OFFSET)))
#define GPIO_PORTC_IM_R									(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_IM_OFFSET)))
#define GPIO_PORTC_ICR_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_ICR_OFFSET)))

#define GPIO_PORTC_AFSEL_R							(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_AFSEL_OFFSET)))
#define GPIO_PORTC_DR2R_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_DR2R_OFFSET)))
#define GPIO_PORTC_DR4R_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_DR4R_OFFSET)))
#define GPIO_PORTC_DR8R_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_DR8R_OFFSET)))
#define GPIO_PORTC_ODR_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_ODR_OFFSET)))
#define GPIO_PORTC_PUR_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_PUR_OFFSET)))
#define GPIO_PORTC_PDR_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_PDR_OFFSET)))
#define GPIO_PORTC_SLR_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_SLR_OFFSET)))
#define GPIO_PORTC_DEN_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_DEN_OFFSET)))
#define GPIO_PORTC_LOCK_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_LOCK_OFFSET)))
#define GPIO_PORTC_CR_R									(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_CR_OFFSET)))
#define GPIO_PORTC_ASMEL_R							(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_AMSEL_OFFSET)))
#define GPIO_PORTC_PCTL_R								(*((volatile unsigned long *)(GPIO_PORTC_BASE_ADDRESS + GPIO_PCTL_OFFSET)))


/*GPIO REGISTERS for PORT D*/
#define GPIO_PORTD_BASE_ADDRESS					0x40007000
#define GPIO_PORTD_MOD_DATA_R						(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_DATA_MOD_OFFSET)))
#define GPIO_PORTD_DATA_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_DATA_OFFSET)))
#define GPIO_PORTD_DIR_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_DIR_OFFSET)))
	
#define GPIO_PORTD_IS_R									(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_IS_OFFSET)))
#define GPIO_PORTD_IBE_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_IBE_OFFSET)))
#define GPIO_PORTD_IEV_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_IEV_OFFSET)))
#define GPIO_PORTD_IM_R									(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_IM_OFFSET)))
#define GPIO_PORTD_ICR_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_ICR_OFFSET)))
	
#define GPIO_PORTD_AFSEL_R							(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_AFSEL_OFFSET)))
#define GPIO_PORTD_DR2R_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_DR2R_OFFSET)))
#define GPIO_PORTD_DR4R_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_DR4R_OFFSET)))
#define GPIO_PORTD_DR8R_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_DR8R_OFFSET)))
#define GPIO_PORTD_ODR_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_ODR_OFFSET)))
#define GPIO_PORTD_PUR_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_PUR_OFFSET)))
#define GPIO_PORTD_PDR_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_PDR_OFFSET)))
#define GPIO_PORTD_SLR_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_SLR_OFFSET)))
#define GPIO_PORTD_DEN_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_DEN_OFFSET)))
#define GPIO_PORTD_LOCK_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_LOCK_OFFSET)))
#define GPIO_PORTD_CR_R									(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_CR_OFFSET)))
#define GPIO_PORTD_ASMEL_R							(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_AMSEL_OFFSET)))
#define GPIO_PORTD_PCTL_R								(*((volatile unsigned long *)(GPIO_PORTD_BASE_ADDRESS + GPIO_PCTL_OFFSET)))



/*GPIO REGISTERS for PORT E*/
#define GPIO_PORTE_BASE_ADDRESS					0x40024000
#define GPIO_PORTE_MOD_DATA_R						(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_DATA_MOD_OFFSET)))
#define GPIO_PORTE_DATA_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_DATA_OFFSET)))
#define GPIO_PORTE_DIR_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_DIR_OFFSET)))
	
#define GPIO_PORTE_IS_R									(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_IS_OFFSET)))
#define GPIO_PORTE_IBE_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_IBE_OFFSET)))
#define GPIO_PORTE_IEV_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_IEV_OFFSET)))
#define GPIO_PORTE_IM_R									(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_IM_OFFSET)))
#define GPIO_PORTE_ICR_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_ICR_OFFSET)))
	
#define GPIO_PORTE_AFSEL_R							(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_AFSEL_OFFSET)))
#define GPIO_PORTE_DR2R_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_DR2R_OFFSET)))
#define GPIO_PORTE_DR4R_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_DR4R_OFFSET)))
#define GPIO_PORTE_DR8R_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_DR8R_OFFSET)))
#define GPIO_PORTE_ODR_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_ODR_OFFSET)))
#define GPIO_PORTE_PUR_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_PUR_OFFSET)))
#define GPIO_PORTE_PDR_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_PDR_OFFSET)))
#define GPIO_PORTE_SLR_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_SLR_OFFSET)))
#define GPIO_PORTE_DEN_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_DEN_OFFSET)))
#define GPIO_PORTE_LOCK_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_LOCK_OFFSET)))
#define GPIO_PORTE_CR_R									(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_CR_OFFSET)))
#define GPIO_PORTE_ASMEL_R							(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_AMSEL_OFFSET)))
#define GPIO_PORTE_PCTL_R								(*((volatile unsigned long *)(GPIO_PORTE_BASE_ADDRESS + GPIO_PCTL_OFFSET)))



/*GPIO REGISTERS for PORT F*/
#define GPIO_PORTF_BASE_ADDRESS					0x40025000
#define GPIO_PORTF_MOD_DATA_R						(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_DATA_MOD_OFFSET)))
#define GPIO_PORTF_DATA_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_DATA_OFFSET)))
#define GPIO_PORTF_DIR_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_DIR_OFFSET)))
	
#define GPIO_PORTF_IS_R									(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_IS_OFFSET)))
#define GPIO_PORTF_IBE_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_IBE_OFFSET)))
#define GPIO_PORTF_IEV_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_IEV_OFFSET)))
#define GPIO_PORTF_IM_R									(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_IM_OFFSET)))
#define GPIO_PORTF_MIS_R                (*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_MIS_OFFSET)))
#define GPIO_PORTF_ICR_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_ICR_OFFSET)))

#define GPIO_PORTF_AFSEL_R							(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_AFSEL_OFFSET)))
#define GPIO_PORTF_DR2R_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_DR2R_OFFSET)))
#define GPIO_PORTF_DR4R_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_DR4R_OFFSET)))
#define GPIO_PORTF_DR8R_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_DR8R_OFFSET)))
#define GPIO_PORTF_ODR_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_ODR_OFFSET)))
#define GPIO_PORTF_PUR_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_PUR_OFFSET)))
#define GPIO_PORTF_PDR_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_PDR_OFFSET)))
#define GPIO_PORTF_SLR_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_SLR_OFFSET)))
#define GPIO_PORTF_DEN_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_DEN_OFFSET)))
#define GPIO_PORTF_LOCK_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_LOCK_OFFSET)))
#define GPIO_PORTF_CR_R									(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_CR_OFFSET)))
#define GPIO_PORTF_ASMEL_R							(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_AMSEL_OFFSET)))
#define GPIO_PORTF_PCTL_R								(*((volatile unsigned long *)(GPIO_PORTF_BASE_ADDRESS + GPIO_PCTL_OFFSET)))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
void SysTick_Handler(void);
void GPIOF_Handler(void);

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
