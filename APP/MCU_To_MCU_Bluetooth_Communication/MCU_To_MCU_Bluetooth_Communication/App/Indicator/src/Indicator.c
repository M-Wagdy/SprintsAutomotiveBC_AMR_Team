/*
 * Indicator.c
 *
 * Created: 9/6/2021 1:54:49 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "LED.h"
#include "Indicator.h"
#include "Indicator_Interface.h"
#include "FreeRTOS.h"
#include "task.h"

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const uint8_t LED_UsedChannel;
extern const STR_INDICATOR_config_t aSTR_IndicatorConfig[INDICATOR_PATTERN_NUMBERS];

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function is the indicator main function.
*
* @return function error state.
*/
extern void Indicator_MainFunction(void)
{
   portTickType xLastWakeTime;
   xLastWakeTime=xTaskGetTickCount();
   
   static uint8_t u8_Init = 0;
   uint8_t u8_Pattern;
   static uint8_t u8_OldPattern = INDICATOR_INVALID_PATTERN;
   static Enu_IndicatorStateMachine State = Indicator_LowTime;
   static uint8_t u8_Duty = 0;
   
   if (u8_Init == 0)
   {
      Indicator_SetPattern(INDICATOR_MALFUNCTION_PATTERN);
      LED_Init(LED_UsedChannel);
      u8_Init = 1;
   }
   
   Indicator_GetPattern(&u8_Pattern);
   
   if( u8_Pattern != u8_OldPattern)
   {
      u8_OldPattern = u8_Pattern;
      State = Indicator_LowTime;
      u8_Duty = 0;
   }
   
   if(INDICATOR_INVALID_PATTERN != u8_Pattern)
   {
      switch(State)
      {
         case Indicator_LowTime:
            LED_Off(LED_UsedChannel);
            State = Indicator_RiseTime;
            vTaskDelayUntil(&xLastWakeTime, aSTR_IndicatorConfig[u8_Pattern].u32_LowTime);
            break;
         case Indicator_RiseTime:
            u8_Duty += aSTR_IndicatorConfig[u8_Pattern].u8_RateOfChange;
            LED_Dim(LED_UsedChannel, u8_Duty);
            if(u8_Duty == 100)
            {
               State = Indicator_HighTime;
            }
            vTaskDelayUntil(&xLastWakeTime, aSTR_IndicatorConfig[u8_Pattern].u8_StepTime);
            break;
         case Indicator_HighTime:
            LED_On(LED_UsedChannel);
            State = Indicator_FallTime;
            vTaskDelayUntil(&xLastWakeTime, aSTR_IndicatorConfig[u8_Pattern].u32_HighTime);
            break;
         case Indicator_FallTime:
            u8_Duty -= aSTR_IndicatorConfig[u8_Pattern].u8_RateOfChange;
            LED_Dim(LED_UsedChannel, u8_Duty);
            if(u8_Duty == 0)
            {
               State = Indicator_LowTime;
            }
            vTaskDelayUntil(&xLastWakeTime, aSTR_IndicatorConfig[u8_Pattern].u8_StepTime);
            break;
      }
   }
}