/*
 * MCU_To_MCU_Bluetooth_Communication.c
 *
 * Created: 9/5/2021 2:53:30 PM
 * Author : vetmo
 */ 

#include "HMI.h"
#include "Indicator.h"
#include "FreeRTOS.h"
#include "task.h"

void HMI_Task( void *pvParameters )
{
   portTickType xLastWakeTime;
   xLastWakeTime=xTaskGetTickCount();
   
   for( ;; )
   {
      HMI_MainFunction();
      vTaskDelayUntil(&xLastWakeTime, 50);
   }
}

void Feedback_Task( void *pvParameters )
{  
   for( ;; )
   {
      Indicator_MainFunction();
   }
}

int main(void)
{   
   xTaskCreate( HMI_Task, ( signed char * ) "HMI", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   xTaskCreate( Feedback_Task, ( signed char * ) "Indicator", configMINIMAL_STACK_SIZE, NULL_PTR, 1, NULL_PTR );
   
   vTaskStartScheduler();
   while(1)
   {
      
   }
   return 0;
}