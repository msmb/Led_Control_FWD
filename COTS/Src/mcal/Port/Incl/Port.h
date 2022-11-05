/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port module
 *
 *  Description:  the header file for the Port.c file     
 *  
 *********************************************************************************************************************/
 
	#ifndef Port_h
	#define Port_h

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
	#include <Platform_Types.h>
	#include <Dio.h>
	#include "Port_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
	#define BASE_VALUE  	0x400FE000
	#define RCGC2						*((volatile uint32_t*)(BASE_VALUE +  0x108))
			
	typedef uint8_t  GPIO_PinMode;
		#define	Dig				0
		#define	Anal			1
		
	typedef uint8_t  GPIO_PinDirection;
		#define input			0
		#define output		1
		
	typedef uint8_t  GPIO_InternalAttach;
		#define ODR				0
		#define PUR				1
		#define PDR				2
		
	typedef uint8_t  GPIO_OutputCurrent;
		#define O_2ma			0
		#define	O_4ma			1
		#define O_8ma			2
		
	typedef struct{
		Dio_port									Port;
		uint8_t 									PinNumber;
		GPIO_PinMode 							Mode;
		Dio_LevelType 						level;
		GPIO_PinDirection 				Direction;
		GPIO_InternalAttach 			Attach;
		GPIO_OutputCurrent 				Output;
		
	}Port_ConfigType;
	
extern const Port_ConfigType Port_Config[43];
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_Init_manual(Dio_port Port, uint8_t PinNumber,GPIO_PinMode Mode,Dio_LevelType level,GPIO_PinDirection Direction,GPIO_InternalAttach Attach,GPIO_OutputCurrent Output);
void Port_Init();
	#endif  /* Port.h */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/