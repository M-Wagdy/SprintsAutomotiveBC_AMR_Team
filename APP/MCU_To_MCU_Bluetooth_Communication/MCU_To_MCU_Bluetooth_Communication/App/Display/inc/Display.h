/*
 * Display.h
 *
 * Created: 9/7/2021 3:10:00 PM
 * Author: Mohamed Wagdy
 */ 


#ifndef __DISPLAY_H__
#define __DISPLAY_H__

/*- INCLUDES -----------------------------------------------*/
#include "STD_types.h"

/*- ENUMS --------------------------------------------------*/
/* Enum for Display State Machine */
typedef enum
{
   Display_FirstNumber = 0,
   Display_SecondNumber = 1,
} Enu_DisplayStateMachine;

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Display Main Function. */
extern void Display_MainFunction(void);

#endif /* __DISPLAY_H__ */