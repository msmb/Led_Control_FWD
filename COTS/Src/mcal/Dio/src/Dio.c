/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  this is the main c file for the driver used for the GPIO
 *
 *      \details  this c file contains all the functions needed for the GPIO read/write process types 
 *    ,types and cons. are definef in the Dio header file
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
#include "Port_Cfg.h"
#include "Bit_Math.h"

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_port Port , uint8_t PinNumber,Dio_LevelType level)        
* \Description     : this function writes to a single channel                                  
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : Port   Port name, PinNumber the number of the pin, Level the level high or low                     
* \Parameters (out): None                                                      
*******************************************************************************/

void Dio_WriteChannel(Dio_port Port , uint8_t PinNumber,Dio_LevelType level){
		if (level)SET_BIT_BB((*((volatile uint8_t*)(GPIO_BaseAdress[Port]+0x3FC))),PinNumber);
		else RESET_BIT_BB((*((volatile uint8_t*)(GPIO_BaseAdress[Port]+0x3FC))),PinNumber);
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_port Port , uint8_t PinNumber)        
* \Description     : this functions reads from a single channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : port the port name used   Pin number the  number of the pin                     
* \Parameters (out): None                                                      
* \Return value:   : Level high or Low                                 
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_port Port , uint8_t PinNumber){
	Dio_LevelType level= (*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x3FC))>>PinNumber);
	return level;
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_port Port ,uint8_t Level)        
* \Description     : this function writes to the entire port not just a channel                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : Port the Port name, Level an 8bit int with the data                     
* \Parameters (out): None                                                                                       
*******************************************************************************/

void Dio_WritePort(Dio_port Port ,uint8_t Level){
	if (Level&0x01) Dio_WriteChannel(Port ,0,HIGH);else Dio_WriteChannel(Port ,0,LOW);
	if (Level&0x02) Dio_WriteChannel(Port ,1,HIGH);else Dio_WriteChannel(Port ,1,LOW);
	if (Level&0x04) Dio_WriteChannel(Port ,2,HIGH);else Dio_WriteChannel(Port ,2,LOW);
	if (Level&0x08) Dio_WriteChannel(Port ,3,HIGH);else Dio_WriteChannel(Port ,3,LOW);
	if (Level&0x10) Dio_WriteChannel(Port ,4,HIGH);else Dio_WriteChannel(Port ,4,LOW);
	if (Level&0x20) Dio_WriteChannel(Port ,5,HIGH);else Dio_WriteChannel(Port ,5,LOW);
	if (Level&0x40) Dio_WriteChannel(Port ,6,HIGH);else Dio_WriteChannel(Port ,6,LOW);
	if (Level&0x80) Dio_WriteChannel(Port ,7,HIGH);else Dio_WriteChannel(Port ,7,LOW);

	//*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x3FC))|=Level;
}

/******************************************************************************
* \Syntax          : uint8_t Dio_ReadPort(Dio_port Port)        
* \Description     : this function reads the entire port not just one channel                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): Level the state of the pin                                                     
* \Return value:   : Level  an 8 bit number
*******************************************************************************/

uint8_t Dio_ReadPort(Dio_port Port){
	uint8_t level= (*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x3FC)));
return level;
}

/******************************************************************************
* \Syntax          : void Dio_FlipChannel(Dio_port Port , uint8_t PinNumber)        
* \Description     : this function is used to flip just one channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : Port		Port name   Pin number the number of the pin 0>7                     
* \Parameters (out): None                                                      
* \Return value:   : none                               
*******************************************************************************/

void Dio_FlipChannel(Dio_port Port , uint8_t PinNumber){
	
	if (Dio_ReadChannel(Port ,PinNumber)==LOW){
		Dio_WriteChannel(Port ,PinNumber,HIGH);
	}else if(Dio_ReadChannel(Port ,PinNumber)==HIGH){
		Dio_WriteChannel(Port ,PinNumber,LOW);
	}

}

/******************************************************************************
* \Syntax          : void Dio_FlipPORT(Dio_port Port)        
* \Description     : this function is used to flip the entire port not just one channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : Port   the Port name                     
* \Parameters (out): None                                                      
* \Return value:   : none                                 
*******************************************************************************/
void Dio_FlipPORT(Dio_port Port){
	*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x3FC))^=0xff;
}
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
