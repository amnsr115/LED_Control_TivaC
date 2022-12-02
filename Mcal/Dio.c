/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital Input Output Driver
 *
 *      \details  Source File: Allows User to Use GPIO periferals as Digital IOs
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define DIO_BIT_MASKING(DATA_R, PINS)							(*((volatile unsigned long *)(DATA_R + (PINS))))
	
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

static Callback_Ptr ptr_To_GPIOA_Callback = NULL_PTR;
static Callback_Ptr ptr_To_GPIOB_Callback = NULL_PTR;
static Callback_Ptr ptr_To_GPIOC_Callback = NULL_PTR;
static Callback_Ptr ptr_To_GPIOD_Callback = NULL_PTR;
static Callback_Ptr ptr_To_GPIOE_Callback = NULL_PTR;
static Callback_Ptr ptr_To_GPIOF_Callback = NULL_PTR;


/******************************************************************************
* \Syntax          : Dio_Level_Type Dio_ReadChannel(Dio_Port_Type PortId, Dio_Channel_Type ChannelId)                                      
* \Description     : Reads the Value of a specific Channel of a Port 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_Port_Type, Dio_Channel_Type                      
* \Parameters (out): Dio_Level_Type                                                      
* \Return value:   : Dio_Level_Type
*******************************************************************************/
Dio_Level_Type Dio_ReadChannel(Dio_Port_Type PortId, Dio_Channel_Type ChannelId)
{
		switch (PortId)
	{
		case PORTA:return (Dio_Level_Type)((GPIO_PORTA_MOD_DATA_R>>ChannelId) & 0x1);
		case PORTB:return (Dio_Level_Type)((GPIO_PORTB_MOD_DATA_R>>ChannelId) & 0x1);
		case PORTC:return (Dio_Level_Type)((GPIO_PORTC_MOD_DATA_R>>ChannelId) & 0x1);
		case PORTD:return (Dio_Level_Type)((GPIO_PORTD_MOD_DATA_R>>ChannelId) & 0x1);
		case PORTE:return (Dio_Level_Type)((GPIO_PORTE_MOD_DATA_R>>ChannelId) & 0x1);
		case PORTF:return (Dio_Level_Type)((GPIO_PORTF_MOD_DATA_R>>ChannelId) & 0x1);
	}
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_Port_Type PortId, Dio_Channel_Type ChannelId, Dio_Level_Type Level)                                      
* \Description     : Writes the Value in a specific Channel of a Port 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_Port_Type, Dio_Channel_Type, Dio_Level_Type                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_Port_Type PortId, Dio_Channel_Type ChannelId, Dio_Level_Type Level)
{
switch (PortId)
	{
		case PORTA:DIO_BIT_MASKING(GPIO_PORTA_DATA_R,1U<<ChannelId) = (1U<<Level);break;
		case PORTB:DIO_BIT_MASKING(GPIO_PORTB_DATA_R,1U<<ChannelId) = (1U<<Level);break;
		case PORTC:DIO_BIT_MASKING(GPIO_PORTC_DATA_R,1U<<ChannelId) = (1U<<Level);break;
		case PORTD:DIO_BIT_MASKING(GPIO_PORTD_DATA_R,1U<<ChannelId) = (1U<<Level);break;
		case PORTE:DIO_BIT_MASKING(GPIO_PORTE_DATA_R,1U<<ChannelId) = (1U<<Level);break;
		case PORTF:DIO_BIT_MASKING(GPIO_PORTF_DATA_R,1U<<ChannelId) = (1U<<Level);break;
	}
}

/******************************************************************************
* \Syntax          : Dio_PortLevel_Type Dio_ReadPort(Dio_Port_Type PortId)                                      
* \Description     : Reads the value of the entire port. 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_Port_Type,                      
* \Parameters (out): Dio_PortLevel_Type                                                      
* \Return value:   : Dio_PortLevel_Type
*******************************************************************************/

Dio_PortLevel_Type Dio_ReadPort(Dio_Port_Type PortId)
{
	switch (PortId)
	{
		case PORTA:return (Dio_PortLevel_Type)(DIO_BIT_MASKING(GPIO_PORTA_DATA_R,0x3FC) & 0xFF);
		case PORTB:return (Dio_PortLevel_Type)(DIO_BIT_MASKING(GPIO_PORTB_DATA_R,0x3FC) & 0xFF);
		case PORTC:return (Dio_PortLevel_Type)(DIO_BIT_MASKING(GPIO_PORTC_DATA_R,0x3FC) & 0xFF);
		case PORTD:return (Dio_PortLevel_Type)(DIO_BIT_MASKING(GPIO_PORTD_DATA_R,0x3FC) & 0xFF);
		case PORTE:return (Dio_PortLevel_Type)(DIO_BIT_MASKING(GPIO_PORTE_DATA_R,0x3FC) & 0x3F);
		case PORTF:return (Dio_PortLevel_Type)(DIO_BIT_MASKING(GPIO_PORTF_DATA_R,0x3FC) & 0x1F);
	}
	
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_Port_Type PortId, Dio_PortLevel_Type Level)                                      
* \Description     : Writes the value of the entire port. 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_Port_Type, Dio_PortLevel_Type                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WritePort(Dio_Port_Type PortId, Dio_PortLevel_Type Level)
{
		switch (PortId)
	{
		case PORTA:DIO_BIT_MASKING(GPIO_PORTA_DATA_R,Level) = Level;break;
		case PORTB:DIO_BIT_MASKING(GPIO_PORTB_DATA_R,Level) = Level;break;
		case PORTC:DIO_BIT_MASKING(GPIO_PORTC_DATA_R,Level) = Level;break;
		case PORTD:DIO_BIT_MASKING(GPIO_PORTD_DATA_R,Level) = Level;break;
		case PORTE:DIO_BIT_MASKING(GPIO_PORTE_DATA_R,Level) = Level;break;
		case PORTF:DIO_BIT_MASKING(GPIO_PORTF_DATA_R,Level) = Level;break;
	}
}
/******************************************************************************
* \Syntax          : void Dio_FlipChannel(Dio_Port_Type PortId, Dio_Channel_Type Channelid)                                      
* \Description     : Flips the value of a channel in a port port. 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Dio_Port_Type, Dio_Channel_Type                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_FlipChannel(Dio_Port_Type PortId, Dio_Channel_Type Channelid)
{
			switch (PortId)
	{
		case PORTA:GPIO_PORTA_MOD_DATA_R ^= (1U<<Channelid);break;
		case PORTB:GPIO_PORTB_MOD_DATA_R ^= (1U<<Channelid);break;
		case PORTC:GPIO_PORTC_MOD_DATA_R ^= (1U<<Channelid);break;
		case PORTD:GPIO_PORTD_MOD_DATA_R ^= (1U<<Channelid);break;
		case PORTE:GPIO_PORTE_MOD_DATA_R ^= (1U<<Channelid);break;
		case PORTF:GPIO_PORTF_MOD_DATA_R ^= (1U<<Channelid);break;
	}
}


void Dio_Add_Callback(Dio_Port_Type PortID, Callback_Ptr FunctionPtr)
{
				switch (PortID)
	{
		case PORTA:ptr_To_GPIOA_Callback = FunctionPtr;break;
		case PORTB:ptr_To_GPIOB_Callback = FunctionPtr;break;
		case PORTC:ptr_To_GPIOC_Callback = FunctionPtr;break;
		case PORTD:ptr_To_GPIOD_Callback = FunctionPtr;break;
		case PORTE:ptr_To_GPIOE_Callback = FunctionPtr;break;
		case PORTF:ptr_To_GPIOF_Callback = FunctionPtr;break;
	}
}

/******************************************************************************
* \Syntax          : void GPIOF_Handler(void)                                     
* \Description     : Handler to GPIO PORTF Interupt. 
*                                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPIOF_Handler(void)
{
	if(ptr_To_GPIOF_Callback !=NULL_PTR)
	{
	ptr_To_GPIOF_Callback();
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
