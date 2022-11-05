/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  the configuration struct for all the PORTs
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
const Port_ConfigType Port_Config[43]=
{
	// 	Port Name		Pin Number			Mode(A\D)			initial output		input/output mode 	attachment type		output current
	{		PORTA			,	0						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTA			,	1						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTA			,	2						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTA			,	3						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTA			,	4						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTA			,	5						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTA			,	6						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTA			,	7						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTB			,	0						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTB			,	1						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTB			,	2						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTB			,	3						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTB			,	4						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTB			,	5						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTB			,	6						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTB			,	7						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTC			,	0						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTC			,	1						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTC			,	2						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTC			,	3						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTC			,	4						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTC			,	5						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTC			,	6						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTC			,	7						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTD			,	0						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTD			,	1						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTD			,	2						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTD			,	3						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTD			,	4						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTD			,	5						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTD			,	6						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTD			,	7						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTE			,	0						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTE			,	1						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTE			,	2						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTE			,	3						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTE			,	4						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTE			,	5						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTF			,	0						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTF			,	1						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTF			,	2						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTF			,	3						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},
	{		PORTF			,	4						,		Dig				,		LOW							,	output						,	ODR							,	O_4ma					},

};
/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/