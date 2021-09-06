/*
 * MCU_To_MCU_Bluetooth_Communication.c
 *
 * Created: 9/5/2021 2:53:30 PM
 * Author : vetmo
 */ 

//#include <avr/io.h>
#include "DIO.h"
#include "FreeRTOS.h"
#include "task.h"
TaskHandle_t myTaskHandle = NULL;
void Task1(void* p)
{
	while(1)
	{
		DIO_TogglePin(PORT_A,PIN0);
		vTaskDelay(1000);
	}
}

int main(void)
{
	DIO_SetPinDirection(PORT_A,PIN0,PIN_OUTPUT);
    xTaskCreate(Task1,"task1",43,(void*)0,1,&myTaskHandle);//Toggle Led Task: minimum stack 43
	vTaskStartScheduler();
	/* Replace with your application code */
    while (1) 
    {
    }
}

