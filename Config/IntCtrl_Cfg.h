/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  NVIC
 *
 *  Description:  Header File: Enables Interupts for the Diffrent Perifirals in the Microcontroller     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INTCTRL_INTERUPTS_USED 					1
#define INTCRTL_PRIORITY_SPLIT					NVIC_APINT_PRIGROUP_7_1


#define INT_GPIOA               16          // GPIO Port A
#define INT_GPIOB               17          // GPIO Port B
#define INT_GPIOC               18          // GPIO Port C
#define INT_GPIOD               19          // GPIO Port D
#define INT_GPIOE               20          // GPIO Port E
#define INT_UART0               21          // UART0
#define INT_UART1               22          // UART1
#define INT_SSI0                23          // SSI0
#define INT_I2C0                24          // I2C0
#define INT_PWM0_FAULT          25          // PWM0 Fault
#define INT_PWM0_0              26          // PWM0 Generator 0
#define INT_PWM0_1              27          // PWM0 Generator 1
#define INT_PWM0_2              28          // PWM0 Generator 2
#define INT_QEI0                29          // QEI0
#define INT_ADC0SS0             30          // ADC0 Sequence 0
#define INT_ADC0SS1             31          // ADC0 Sequence 1
#define INT_ADC0SS2             32          // ADC0 Sequence 2
#define INT_ADC0SS3             33          // ADC0 Sequence 3
#define INT_WATCHDOG            34          // Watchdog Timers 0 and 1
#define INT_TIMER0A             35          // 16/32-Bit Timer 0A
#define INT_TIMER0B             36          // 16/32-Bit Timer 0B
#define INT_TIMER1A             37          // 16/32-Bit Timer 1A
#define INT_TIMER1B             38          // 16/32-Bit Timer 1B
#define INT_TIMER2A             39          // 16/32-Bit Timer 2A
#define INT_TIMER2B             40          // 16/32-Bit Timer 2B
#define INT_COMP0               41          // Analog Comparator 0
#define INT_COMP1               42          // Analog Comparator 1
#define INT_SYSCTL              44          // System Control
#define INT_FLASH               45          // Flash Memory Control and EEPROM
                                            // Control
#define INT_GPIOF               46          // GPIO Port F
#define INT_UART2               49          // UART2
#define INT_SSI1                50          // SSI1
#define INT_TIMER3A             51          // Timer 3A
#define INT_TIMER3B             52          // Timer 3B
#define INT_I2C1                53          // I2C1
#define INT_QEI1                54          // QEI1
#define INT_CAN0                55          // CAN0
#define INT_CAN1                56          // CAN1
#define INT_HIBERNATE           59          // Hibernation Module
#define INT_USB0                60          // USB
#define INT_PWM0_3              61          // PWM Generator 3
#define INT_UDMA                62          // uDMA Software
#define INT_UDMAERR             63          // uDMA Error
#define INT_ADC1SS0             64          // ADC1 Sequence 0
#define INT_ADC1SS1             65          // ADC1 Sequence 1
#define INT_ADC1SS2             66          // ADC1 Sequence 2
#define INT_ADC1SS3             67          // ADC1 Sequence 3
#define INT_SSI2                73          // SSI2
#define INT_SSI3                74          // SSI3
#define INT_UART3               75          // UART3
#define INT_UART4               76          // UART4
#define INT_UART5               77          // UART5
#define INT_UART6               78          // UART6
#define INT_UART7               79          // UART7
#define INT_I2C2                84          // I2C2
#define INT_I2C3                85          // I2C3
#define INT_TIMER4A             86          // 16/32-Bit Timer 4A
#define INT_TIMER4B             87          // 16/32-Bit Timer 4B
#define INT_TIMER5A             108         // 16/32-Bit Timer 5A
#define INT_TIMER5B             109         // 16/32-Bit Timer 5B
#define INT_WTIMER0A            110         // 32/64-Bit Timer 0A
#define INT_WTIMER0B            111         // 32/64-Bit Timer 0B
#define INT_WTIMER1A            112         // 32/64-Bit Timer 1A
#define INT_WTIMER1B            113         // 32/64-Bit Timer 1B
#define INT_WTIMER2A            114         // 32/64-Bit Timer 2A
#define INT_WTIMER2B            115         // 32/64-Bit Timer 2B
#define INT_WTIMER3A            116         // 32/64-Bit Timer 3A
#define INT_WTIMER3B            117         // 32/64-Bit Timer 3B
#define INT_WTIMER4A            118         // 32/64-Bit Timer 4A
#define INT_WTIMER4B            119         // 32/64-Bit Timer 4B
#define INT_WTIMER5A            120         // 32/64-Bit Timer 5A
#define INT_WTIMER5B            121         // 32/64-Bit Timer 5B
#define INT_SYSEXC              122         // System Exception (imprecise)
#define INT_PWM1_0              150         // PWM1 Generator 0
#define INT_PWM1_1              151         // PWM1 Generator 1
#define INT_PWM1_2              152         // PWM1 Generator 2
#define INT_PWM1_3              153         // PWM1 Generator 3
#define INT_PWM1_FAULT          154         // PWM1 Fault

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 IntCtrl_Interupt_Numbertype;

typedef enum 
{
	LEVEL_1,
	LEVEL_2,
	LEVEL_3,
	LEVEL_4,
	LEVEL_5,
	LEVEL_6,
	LEVEL_7,
	
}IntCtrl_Priority_Type;

typedef struct
{
	IntCtrl_Interupt_Numbertype IntNumber;
	IntCtrl_Priority_Type IntSubPriority;
	
}IntCtrl_ConfigType;
 

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern IntCtrl_ConfigType IntConfigurations[];


#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
