/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic.c
 *        \brief  it is the file that contains the Nvic initialization
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include <Nvic.h>
#include "Nvic_Cfg.h"
#include <Bit_Math.h>
#include <Platform_Types.h>

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void NVIC_int()       
* \Description     : this function initialize any interrupt                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : 	none    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/

void NVIC_int()
	{
	uint32_t i;
	int index;
	uint32_t offset;
	int n;
		
	*(volatile uint32_t *)( (uint32_t)PRIGROUP) =0x05FA0000 | (NVIC_Cfg[139].Priority * 256);   //for Priority group
																																															//how much primary / secondry
	
	//to put is Enable or Disabled
	for(i=0;i<=139;i++)
		{
				if (i<=31){
				if (NVIC_Cfg[i].state==Enable) SetBit(*(volatile uint32_t *)(( (uint32_t)int_base1)),i);
				else if (NVIC_Cfg[i].state==Disable) ClrBit(*(volatile uint32_t *)(( (uint32_t)int_base1)),i);
				}
				if (i>31 & i<=63){
				if (NVIC_Cfg[i].state==Enable) SetBit(*(volatile uint32_t *)(( (uint32_t)int_base2)), (i-32));
				else if (NVIC_Cfg[i].state==Disable) ClrBit(*(volatile uint32_t *)(( (uint32_t)int_base2)), (i-32));
				}
				if (i>63 & i<=95){
				if (NVIC_Cfg[i].state==Enable) SetBit(*(volatile uint32_t *)(( (uint32_t)int_base3)),(i-64));
				else if (NVIC_Cfg[i].state==Disable) ClrBit(*(volatile uint32_t *)(( (uint32_t)int_base3)),(i-64));
				}
				if (i>95 & i<=127){
				if (NVIC_Cfg[i].state==Enable) SetBit(*(volatile uint32_t *)(( (uint32_t)int_base4)),(i-96));
				else if (NVIC_Cfg[i].state==Disable) ClrBit(*(volatile uint32_t *)(( (uint32_t)int_base4)),(i-96));
				}
				if (i>127 & i<=139){
				if (NVIC_Cfg[i].state==Enable) SetBit(*(volatile uint32_t *)(( (uint32_t)int_base5)),(i-128));
				else if (NVIC_Cfg[i].state==Disable) ClrBit(*(volatile uint32_t *)(( (uint32_t)int_base5)),(i-128));
			}
				
			
				index=i/4;
				offset=index*4;
				n=i%4;
				switch(n)
					{
								case 0:
								*(volatile uint32_t *)((uint32_t)PRI0+offset)|= NVIC_Cfg[i].Priority *  32 ;
								break;
								case 1:
								*(volatile uint32_t *)((uint32_t)PRI0+offset)|= NVIC_Cfg[i].Priority *  32 * 256;
								break;
								case 2:
								*(volatile uint32_t *)((uint32_t)PRI0+offset)|=	NVIC_Cfg[i].Priority *  32 * 65536;
								break;	
								case 3:
								*(volatile uint32_t *)((uint32_t)PRI0+offset)|= NVIC_Cfg[i].Priority *  32 * 16777216;
								break;
					}//switch case
		}//for loop
	
	}//nvic_init
	
/**********************************************************************************************************************
 *  END OF FILE: Nvic.c
 *********************************************************************************************************************/
