/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer.c
 *        \brief  it is the file that contains the Timer and delay functions(systick)
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include <Timer.h>
#include <Bit_Math.h>

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
	volatile int SysTick_intFlag;
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : 	void (*Handler_PTR)()       
* \Description     : this  is a call back function used in the delay function
 to use the handler
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
**	*****************************************************************************/
	void (*Handler_PTR)();
	
	
	void SysTick_Handler_Delay()
	{
		ClrBit((*(volatile uint32_t *)(((uint32_t)	STCTRL))),0);
		(*(volatile uint32_t *)(((uint32_t)	STReload)))= 0x00000000;
		SysTick_intFlag=1;
		return;
	}

		
	/******************************************************************************
* \Syntax          : 	void SysTick_Handler ()()       
* \Description     : this Handler is a used when the systick interrupt activates                                       
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : None    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
**	*****************************************************************************/	
	
	void SysTick_Handler ()
	{ 
			(*Handler_PTR)();
	}


/******************************************************************************
* \Syntax          : void system_delay(int time_ms)       
* \Description     : this function creates a delay of tthe time mentioned above in ms                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : time_ms "the user inserts a time in ms)    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
	
void system_delay(int time_ms)
{	
	Handler_PTR=&SysTick_Handler_Delay;
	
	while(time_ms>(1000))
		{
		time_ms=time_ms-1000;
		int time_ms2=1000;
		SysTick_intFlag=0;	
		uint32_t time_in_ticks=time_ms2*System_Clock*1000;
		(*(volatile uint32_t *)(((uint32_t)	STCTRL))) |= 0x00000003;
		(*(volatile uint32_t *)(((uint32_t)	STReload)))= time_in_ticks;			
			
		while(1)
			{
			if (SysTick_intFlag==1){
			SysTick_intFlag=0;
			break;
			}
		}
	}
		
	SysTick_intFlag=0;	
	uint32_t time_in_ticks=time_ms*System_Clock*1000;
	
	(*(volatile uint32_t *)(((uint32_t)	STCTRL)))|= 0x00000003;
	(*(volatile uint32_t *)(((uint32_t)	STReload)))= time_in_ticks;
	
		while(1)
		{
			if (SysTick_intFlag==1){
			SysTick_intFlag=0;
			break;
			}
		}
		
	Handler_PTR =0;
}

/******************************************************************************
* \Syntax          : void systick_init()       
* \Description     : this function initiates systick timer for use in the start process                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : none    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
		void systick_init()
		{
			if (Timer_Config==InActive){  (*(volatile uint32_t *)(((uint32_t)	STCTRL)))=0x06;}  
			if (Timer_Config==Active){  (*(volatile uint32_t *)(((uint32_t)	STCTRL)))=0x02;}
		}			
		
		
/******************************************************************************
* \Syntax          : void systick_Start()       
* \Description     : this function starts systick timer it will start counting and when it hits zero it will restart counting                                 
*                    no interrupt is genertated                                                         
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : none  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/		
		void systick_Start(int time)
		{
		uint32_t time_in_ticks=time*System_Clock*1000;		
		(*(volatile uint32_t *)(((uint32_t)	STCTRL)))|= 0x00000003;   //enable interupt and strart timer
		(*(volatile uint32_t *)(((uint32_t)	STReload)))= time_in_ticks;
		}			
/******************************************************************************
* \Syntax          : void systick_Stop()       
* \Description     : it will stop the counter                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : none  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/		
void systick_Stop()
{
	ClrBit((*(volatile uint32_t *)(((uint32_t)	STCTRL))),0);   //to stop systick
}			


	
/**********************************************************************************************************************
 *  END OF FILE: Timer.c
 *********************************************************************************************************************/
