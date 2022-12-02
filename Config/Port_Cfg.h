/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.h
 *       Module:  GPIO
 *
 *  Description:  Source file: Configures the pins used     
 *  
 *********************************************************************************************************************/
#ifndef PORTCFG_H
#define PORTCFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*#define PORT_PINS_USED_NUMBER ((uint8)(sizeof(PinConfigurations)/sizeof(PinConfigurations[0])))*/
#define PORT_PINS_USED_NUMBER 		5

/* All GPIO Pins are DIO when set to Zero */
#define PORT_PIN_MODE_DIO 				0

/* PIN F0 Pin Modes*/
# define PORT_F0_PINMODE_U1RTS 		1
# define PORT_F0_PINMODE_SSI1Rx		2
# define PORT_F0_PINMODE_CAN0Rx		3 
# define PORT_F0_PINMODE_M1PWM4		5 
# define PORT_F0_PINMODE_PhA0			6
# define PORT_F0_PINMODE_T0CCP0		7
# define PORT_F0_PINMODE_NMI			8
# define PORT_F0_PINMODE_C0o 			9

/*PIN F1 Pin Modes*/
# define PORT_F1_PINMODE_U1CTS		1
# define PORT_F1_PINMODE_SSI1Tx		2
# define PORT_F1_PINMODE_M1PWM5		5
# define PORT_F1_PINMODE_PhB0			6
# define PORT_F1_PINMODE_T0CCP1		7
# define PORT_F1_PINMODE_C1o			9
# define PORT_F1_PINMODE_TRD1			14

/*PIN F2 Pin Modes*/
# define PORT_F2_PINMODE_SSI1Clk	2
# define PORT_F2_PINMODE_M0FAULT0	4
# define PORT_F2_PINMODE_M1PWM6		5
# define PORT_F2_PINMODE_T1CCP0		7
# define PORT_F2_PINMODE_TRD0			14

/*PIN F3 Pin Modes*/
# define PORT_F3_PINMODE_SSI1Fss	2
# define PORT_F3_PINMODE_CAN0Tx		3
# define PORT_F3_PINMODE_M1PWM7		5
# define PORT_F3_PINMODE_T1CCP1		7
# define PORT_F3_PINMODE_TRCLK		14

/*PIN F4 Pin Modes*/
# define PORT_F4_PINMODE_M1FAULT0	5
# define PORT_F4_PINMODE_IDX0			6
# define PORT_F4_PINMODE_T2CCP0		7
# define PORT_F4_PINMODE_USB0EPEN	8


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
		PIN0 = 0,
		PIN1,
		PIN2,
		PIN3,
		PIN4,
		PIN5,
		PIN6,
		PIN7
}Port_PinType;


typedef enum
{
		PORTA = 0,
		PORTB,
		PORTC,
		PORTD,
		PORTE,
		PORTF
}Port_PortType;

typedef enum
{
	INPUT = 0,
	OUTPUT
}Port_PinDirectionType;

typedef uint8 Port_PinModeType;


typedef enum{
	PDR,
	PUR,
	ODR
}Port_PinInternalAttachType;

typedef enum{
	OUTPUT_2mA,
	OUTPUT_4mA,
	OUTPUT_8mA
	
}Port_PinOutputCurrentType; 

typedef enum{
	DIGITAL,
	ANALOG
	
}Port_OutputType;


typedef struct
{
	Port_PortType portNum;
	Port_PinType pinNum;
	Port_PinModeType pinMode;
	Port_OutputType pinOutput;
	Port_PinDirectionType pinDir;
	Port_PinInternalAttachType internalAttach;
	Port_PinOutputCurrentType outCurrent;
	
}Port_ConfigType;

typedef uint8 Port_PinsUsedType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern Port_ConfigType PinConfigurations[];


 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/


