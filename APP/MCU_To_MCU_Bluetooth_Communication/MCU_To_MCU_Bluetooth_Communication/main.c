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

uint8_t Name[255] = "ALI";
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
	while(LCD_Init() != OperationSuccess);//<===forLCDInitialization
	/*uint8_t shifting_State;
	uint8_t Position;
	uint8_t LastShiftingState;
	uint8_t Countt = 100;
	while(LCD_SendCommand(0X80|7)!= OperationSuccess);
	Position = 7;
	while(LCD_SendString((uint8_t*)"AhmedAdel") != OperationSuccess);
	shifting_State = ShiftingLeft;
	LastShiftingState = shifting_State;
	while(LCD_SendCommand(LCD_CURS_LINE2)!= OperationSuccess);*/
	//LCD_SendNumber(Countt);
	//for(uint8_t i = 0; i< passworLength; i++)
	//{
		//while(LCD_SendData('*')!= OperationSuccess);
	//}
	//uint8_t l = (passworLength+(16-wordLength));
	
	DISPLAY_SetNumber_of_Asterisk(6);//<======setsNumberofasteriks
	DISPLAY_SetState(Waiting);//<====setsthestate of the system
	//CRC_16_Calc(Name);
	retValofChk = CRC_16_Chk(Name);
	while (1) 
    {
		//LCD_SendNumber(0);
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
		DISPLAY_MainFunction();//<=====main function of Display module
		/******
		******/
/*
		LCD_SendNumber(Countt);
		if(shifting_State == ShiftingLeft)
		{
			if(Countt>=100)
			{
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendData(8)!=OperationSuccess);
			}
			else if (Countt>=10)
			{
				//while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else
			{

			}
    }*/
		/******
		******/
		/*switch (shifting_State)
		{
			case ShiftingLeft:
			while(LCD_SendCommand(LCD_SHIFTDISPLEFT)!= OperationSuccess);
			Position--;
			if (Position == 0)
			{
				shifting_State = ShiftingRight;
			}
			break;
			case ShiftingRight:
			while(LCD_SendCommand(LCD_SHIFTDISPRIGHT)!= OperationSuccess);
			Position++;
			if (Position >= 7)
			{
				shifting_State = ShiftingLeft;
			}
			break;
		}
		Countt--;
		if(Countt == 0)
		Countt = 100;*/
	/******
	******/
		/*if((shifting_State == ShiftingLeft) && (LastShiftingState == ShiftingLeft))
		{
			while(LCD_SendCommand(LCD_SHIFTCURSRIGHT)!=OperationSuccess);	
			LCD_SendNumber(Countt);
			if(Countt/100)
			{
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else if(Countt/10)
			{
				while(LCD_SendData(' ')!=OperationSuccess);/ ** /
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else
			{
				while(LCD_SendData(' ')!=OperationSuccess);/ ** /
				while(LCD_SendData(' ')!=OperationSuccess);/ ** /
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
		}
		else if ((shifting_State == ShiftingRight) && (LastShiftingState == ShiftingRight))
		{
			while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			LCD_SendNumber(Countt);
			if(Countt/100)
			{
				//while(LCD_SendData(' ')!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else if(Countt/10)
			{
				while(LCD_SendData(' ')!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else
			{
				while(LCD_SendData(' ')!=OperationSuccess);
				while(LCD_SendData(' ')!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
		}
		else if ((shifting_State == ShiftingRight) && (LastShiftingState == ShiftingLeft))
		{
			while(LCD_SendCommand(LCD_SHIFTCURSRIGHT)!=OperationSuccess);
			LCD_SendNumber(Countt);
			if(Countt/100)
			{
				//while(LCD_SendData(' ')!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else if(Countt/10)
			{
				while(LCD_SendData(' ')!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else
			{
				while(LCD_SendData(' ')!=OperationSuccess);
				while(LCD_SendData(' ')!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
		}
		else if ((shifting_State == ShiftingLeft) && (LastShiftingState == ShiftingRight))
		{
			while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			LCD_SendNumber(Countt);
			if(Countt/100)
			{
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else if(Countt/10)
			{
				while(LCD_SendData(' ')!=OperationSuccess);/ ** /
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
			else
			{
				while(LCD_SendData(' ')!=OperationSuccess);/ ** /
				while(LCD_SendData(' ')!=OperationSuccess);/ ** /
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
				while(LCD_SendCommand(LCD_SHIFTCURSLEFT)!=OperationSuccess);
			}
		}
		LastShiftingState = shifting_State;*/
		for(uint32_t volatile x = 0; x < 50000; x++);//<=====Dummydelay function
	}
}

