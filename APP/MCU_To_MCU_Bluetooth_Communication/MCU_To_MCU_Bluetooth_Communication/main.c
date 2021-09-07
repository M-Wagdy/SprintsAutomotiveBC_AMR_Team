/*
 * MCU_To_MCU_Bluetooth_Communication.c
 *
 * Created: 9/5/2021 2:53:30 PM
 * Author : vetmo
 */ 
#include "FreeRTOS.h"
#include "task.h"
#include "LCD.h"
#include "EEPROM.h"
#include "DIO.h"
/*TaskHandle_t myTaskHandle = NULL;*/
/*
void myTask1 (void *p)
{
	while(1)
	{
		//LCD_SendData('A');
		LCD_SendCommand(0x1C);
		vTaskDelay(2);
	}
}*/

int main(void)
{
	//DIO_SetPinDirection(PORT_D,PIN0,PIN_OUTPUT);
	//EEPROM_Write('A',5);
	
	while(LCD_Init()!= OperationSuccess);
	//xTaskCreate(myTask1,"Task1",200,NULL_PTR,1,&myTaskHandle);/*creates a task*/
	while(LCD_SendData('A')!=OperationSuccess);
	while(LCD_SendString("AHMED")!=OperationSuccess);
	//vTaskStartScheduler();/*Start Scheduler*/
	//uint8_t x =0;EEPROM_Read(&x,5);
    //LCD_ReadDispLoc(1,&x);
	//EEPROM_write(5, 'A');
	//x=EEPROM_read(5);
	while (1) 
    {
		//if(x=='A')
		//DIO_WritePin(PORT_D,PIN0,PIN_HIGH);
		//LCD_SendCommand(0x1C);
		//for(volatile int i = 0; i<5000;i++);
		//LCD_ReadDispLoc(LCD_CURS_Position0,&x);
		
    }
}

