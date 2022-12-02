/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  GPIO
 *
 *  Description:  Header File: APIs used for reading and writing in the GPIO ports     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
			CHANNEL0 = 0,
			CHANNEL1,
			CHANNEL2,
			CHANNEL3,
			CHANNEL4,
			CHANNEL5,
			CHANNEL6,
			CHANNEL7
	
}Dio_Channel_Type;

typedef enum {
			PORTA = 0,
			PORTB,
			PORTC,
			PORTD,
			PORTE,
			PORTF
	
}Dio_Port_Type;

typedef enum {
			LOW = 0,
			HIGH =1
	
}Dio_Level_Type;

typedef  uint8 Dio_PortLevel_Type;



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

Dio_Level_Type Dio_ReadChannel(Dio_Port_Type PortId, Dio_Channel_Type ChannelId);
void Dio_WriteChannel(Dio_Port_Type PortId, Dio_Channel_Type ChannelId, Dio_Level_Type Level);
Dio_PortLevel_Type Dio_ReadPort(Dio_Port_Type PortId);
void Dio_WritePort(Dio_Port_Type PortId, Dio_PortLevel_Type Level);
void Dio_FlipChannel(Dio_Port_Type PortId, Dio_Channel_Type Channelid);
void Dio_Add_Callback(Dio_Port_Type PortID, Callback_Ptr FunctionPtr);

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
