/*
 * MCU_To_MCU_Bluetooth_Communication.c
 *
 * Created: 9/5/2021 2:53:30 PM
 * Author : vetmo
 */ 
#include "LCD.h"

int main(void)
{
	while(LCD_Init()!= OperationSuccess);
	while(LCD_SendData('A')!=OperationSuccess);
	uint8_t x =0;
    //LCD_ReadDispLoc(1,&x);
	while (1) 
    {
		//LCD_SendCommand(0x1C);
		//for(volatile int i = 0; i<5000;i++);
		LCD_ReadDispLoc(LCD_CURS_Position0,&x);
		
    }
}

