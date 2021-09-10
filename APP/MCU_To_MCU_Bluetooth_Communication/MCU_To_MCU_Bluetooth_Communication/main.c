/*
 * MCU_To_MCU_Bluetooth_Communication.c
 *
 * Created: 9/5/2021 2:53:30 PM
 * Author : Ahmed Adel
 */ 
#include "FreeRTOS.h"
#include "task.h"
#include "DISPLAY.h"
#include "STORAGE.h"
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

uint8_t Load[255] = "ALI";
//Load={'A','L','I','\0'};
//uint8_t *MAC = (uint8_t*)"ALI";
uint8_t MAC[6] = {0x41,0x4C,0x49,0x00,0x27,0xEB};
uint16_t low;
int main(void)
{
	//DIO_SetPinDirection(PORT_D,PIN0,PIN_OUTPUT);
	//EEPROM_Write('A',5);
	//uint8_t iterator = 0;
	//while(LCD_Init()!= OperationSuccess);
	//DISPLAY_SetState(SystemLoading);
	//STORAGE_MAC_Save(MAC);
	//STORAGE_MAC_Load(Load);
	CRC_16_Calc(Load,&low);
	//xTaskCreate(myTask1,"Task1",200,NULL_PTR,1,&myTaskHandle);/*creates a task*/
	//while(LCD_SendData('A')!=OperationSuccess);
	//while(LCD_SendString("AHMED")!=OperationSuccess);
	//vTaskStartScheduler();/*Start Scheduler*/
	//uint8_t x =0;EEPROM_Read(&x,5);
    //LCD_ReadDispLoc(1,&x);
	//EEPROM_write(5, 'A');
	//x=EEPROM_read(5);
	while (1) 
    {
		//DISPLAY_ShiftAndDisplay(5,(uint8_t*)"AHMED");
		//DISPLAY_MainFunction();
		//iterator ++;
		//if(x=='A')
		//DIO_WritePin(PORT_D,PIN0,PIN_HIGH);
		//LCD_SendCommand(0x1C);
		for(volatile uint32_t i = 0; i<25000;i++);
		
		//if(iterator == 20)
			//State = PassEntering;
		//DISPLAY_ShiftAndDisplay(5,(uint8_t*)"ADEL");
		//for(volatile uint32_t i = 0; i<100000;i++);
		//LCD_ReadDispLoc(LCD_CURS_Position0,&x);
		
    }
}

