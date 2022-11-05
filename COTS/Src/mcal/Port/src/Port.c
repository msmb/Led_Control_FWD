/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  it is the file that contains the GPIO initialization functions 
 *
 *      \details  it contains the function used in the process of initializing the GPIO port
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include <Port.h>
#include "Port_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init_manual(Dio_port Port, uint8_t PinNumber,GPIO_PinMode Mode,Dio_LevelType level,GPIO_PinDirection Direction,GPIO_InternalAttach Attach,GPIO_OutputCurrent Output)        
* \Description     : this function initialize any Port                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : 	Port  the port name all caps ex: PORTA , PORTB etc
			     	PinNumber the pin you want to configure 0->7
				PinMode   Digital or analouge  ex: Dig or Anal
				Level	    the initial value for the Pin chosen	 
				Direction  input/output     
				Attach    the internal attach type Pull up ressitor, Pull down resistor or ODR using ODR, PUR or PDR
				Output	for the output current  2ma,4ma,8ma		using O_2ma		O_4ma		O_8ma             
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/

void Port_Init_Manual(Dio_port Port, uint8_t PinNumber,GPIO_PinMode Mode,Dio_LevelType level,GPIO_PinDirection Direction,GPIO_InternalAttach Attach,GPIO_OutputCurrent Output){
	
	if (Mode==0)
		{
				RCGC2 |= (1<<Port);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x51C))|=(1<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x528))|=(0<<PinNumber);

		}
		else if (Mode==1)
		{
				*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x51C))|=(0<<PinNumber);
				*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x528))|=(1<<PinNumber);
		}
		
		if (Direction==0)
		{
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x400))|=(0<<PinNumber);
		}
		else if (Direction==1)
		{
				*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x400))|=(1<<PinNumber);			
		}
		
		if (Attach==0)
		{
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x50C))|=(1<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x510))|=(0<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x514))|=(0<<PinNumber);
		}
		else if (Attach==1)
		{
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x50C))|=(0<<PinNumber);			
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x510))|=(1<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x514))|=(0<<PinNumber);
		}
		else if (Attach==2)
		{
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x50C))|=(0<<PinNumber);			
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x510))|=(0<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x514))|=(1<<PinNumber);
		}
		
		if (Output==0)
		{
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x500))|=(1<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x504))|=(0<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x508))|=(0<<PinNumber);
		}
		else if (Output==1)
		{
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x500))|=(0<<PinNumber);			
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x504))|=(1<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x508))|=(0<<PinNumber);
		}
		else if (Output==2)
		{
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x500))|=(0<<PinNumber);			
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x504))|=(0<<PinNumber);
			*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x508))|=(1<<PinNumber);
		}
		
		*((volatile uint8_t*)(GPIO_BaseAdress[Port] +  0x3FC))|=(level<<PinNumber);
		
}
/******************************************************************************
* \Syntax          :	void Port_Init()
* \Description     : 	this function initialize all Ports from cfg and Lcfg                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : None      
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/

void Port_Init()
{
		for (int i=0;i<=43;i++)
		{
			Port_Init_Manual(Port_Config[i].Port,Port_Config[i].PinNumber,Port_Config[i].Mode,Port_Config[i].level,Port_Config[i].Direction,Port_Config[i].Attach,Port_Config[i].Output);
		}
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
