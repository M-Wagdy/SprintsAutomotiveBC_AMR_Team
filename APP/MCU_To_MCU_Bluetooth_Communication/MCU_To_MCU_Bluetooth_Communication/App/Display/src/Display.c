/*
 * Display.c
 *
 * Created: 9/7/2021 3:10:35 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "SevenSeg.h"
#include "Display.h"
#include "Display_Interface.h"

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const STR_DISPLAY_SEGMENT_config_t STR_DisplaySegmentConfig;

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function is the Display main function.
*
* @return function error state.
*/
extern void Display_MainFunction(void)
{
   static uint8_t u8_Init = 0;  
   uint8_t u8_SevenSegmentNumber; 
   static Enu_DisplayStateMachine State = Display_FirstNumber;
   
   if (u8_Init == 0)
   {
      SevenSeg_Init(STR_DisplaySegmentConfig.u8_SegmentCh0);
      SevenSeg_Init(STR_DisplaySegmentConfig.u8_SegmentCh1);
      u8_Init = 1;
   }
   
   Display_GetSevenSegment(&u8_SevenSegmentNumber);
   
   switch(State)
   {
      case Display_FirstNumber:
         SevenSeg_Display(STR_DisplaySegmentConfig.u8_SegmentCh0, u8_SevenSegmentNumber%10);
         State = Display_SecondNumber;
         break;
      case Display_SecondNumber:
         SevenSeg_Display(STR_DisplaySegmentConfig.u8_SegmentCh1, u8_SevenSegmentNumber/10);
         State = Display_FirstNumber;
         break;
   }      
}