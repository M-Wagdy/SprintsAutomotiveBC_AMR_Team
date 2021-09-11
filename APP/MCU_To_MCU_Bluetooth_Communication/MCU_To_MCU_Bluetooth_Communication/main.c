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

uint8_t Name[255] = "ALI,§";
uint8_t retValofChk = 1;
int main(void)
{
	/*
	variables:
		password length
		WordLength
	*/
	//while( != OperationSuccess);
	//uint8_t passworLength = 4;
	//uint8_t const wordLength = 9;
	//uint8_t positionaftefirstlineword = 0xc0;
	/*while(LCD_Init() != OperationSuccess);//<===forLCDInitialization*/
	//while(LCD_SendCommand(0X80|7)!= OperationSuccess);
	//while(LCD_SendString((uint8_t*)"AhmedAdel") != OperationSuccess);
	//while(LCD_SendCommand(positionaftefirstlineword)!= OperationSuccess);
	//for(uint8_t i = 0; i< passworLength; i++)
	//{
		//while(LCD_SendData('*')!= OperationSuccess);
	//}
	//uint8_t l = (passworLength+(16-wordLength));
	
	/*DISPLAY_SetNumber_of_Asterisk(6);//<======setsNumberofasteriks*/
	/*DISPLAY_SetState(Waiting);//<====setsthestate of the system*/
	//CRC_16_Calc(Name);
	retValofChk = CRC_16_Chk(Name);
	while (1) 
    {
		//for(uint8_t y = 0; y<(16-wordLength); y++)
		//{
			//while(LCD_SendCommand(LCD_SHIFTDISPLEFT)!= OperationSuccess);
			//while(LCD_SendData('*')!= OperationSuccess);
			//for(uint32_t volatile x = 0; x < 50000; x++);
		//}
		//for(uint8_t y = 0; y<(16-wordLength);y++)
		//{
			//
			//while(LCD_SendCommand(LCD_SHIFTDISPRIGHT)!= OperationSuccess);
			//while(LCD_SendCommand(0xc0|l)!= OperationSuccess);
			//while(LCD_SendData(' ')!= OperationSuccess);
			//while(LCD_SendCommand((0xc0|l)-1)!= OperationSuccess);
			//for(uint32_t volatile x = 0; x < 50000; x++);
			//l--;
		//}
		//l = (passworLength+(16-wordLength));
		/*DISPLAY_MainFunction();//<=====main function of Display module*/
		/*for(uint32_t volatile x = 0; x < 100000; x++);//<=====Dummydelay function*/
    }
}

