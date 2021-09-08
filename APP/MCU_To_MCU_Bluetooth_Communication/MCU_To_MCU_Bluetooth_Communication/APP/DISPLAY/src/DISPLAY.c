
/*
 * DISPLAY.c
 *
 * Created: 9/7/2021 6:37:39 PM
 *  Author: Ahmed Adel
 */ 
#include "DISPLAY.h"

uint8_t Position = 0;
/*Moving to the interface files*/
uint8_t Number_of_Asteriks = 0;
uint8_t State = OperationStarted;//OperationStarted
uint8_t WrongPassEntries = 0;
void DISPLAY_MainFunction(void)
{
	uint8_t static Last_state = OperationStarted;
	uint8_t static Counter = 0;
	DISPLAY_GetNumber_of_Asterisk(&Number_of_Asteriks);
	DISPLAY_GetState(&State);
	if((Last_state == CorrectPassword || Last_state == WrongPassword || Last_state == Waiting)&&(Counter!=0))
	{
		State = Last_state;
	}
	switch(State)
	{
		case SystemLoading:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			DISPLAY_ShiftAndDisplay(14, (uint8_t*)"System Loading");
			break;
		case Welcome:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			DISPLAY_ShiftAndDisplay(7, (uint8_t*)"Welcome");
			break;
		case PassEntering:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			while (LCD_SendCommand(0xc0)!=OperationSuccess);
			for(uint8_t iterator = 0; iterator<Number_of_Asteriks; iterator++)
			{
				if(iterator>6)
				break;
				while(LCD_SendData('*')!=OperationSuccess);
			}
			DISPLAY_ShiftAndDisplay(10,(uint8_t*)"Enter Pass");
			break;
		case CorrectPassword:
			if(Counter == 40)
			{
				WrongPassEntries = 0;
				Counter = 0;
				//State = SevenSegments;
				DISPLAY_SetState(SevenSegments);
				break;
			}
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			DISPLAY_ShiftAndDisplay(10,(uint8_t*)"Pass OK");
			Counter ++;
			break;
			
			/*Counter*/
		case WrongPassword:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			if(Counter == 40)
			{
				Counter = 0;
				WrongPassEntries++;
				if(WrongPassEntries==3)
				DISPLAY_SetState(Waiting);
				else
				DISPLAY_SetState(PassEntering);
				break;
			}
			DISPLAY_ShiftAndDisplay(10,(uint8_t*)"Wrong Pass");
			/*check the counter*/
			Counter ++;
			break;
		case Waiting:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			while (LCD_SendCommand(0xc0)!=OperationSuccess);
			LCD_SendNumber((10000-(Counter*50))/1000);
			if(Counter == 199)
			{
				WrongPassEntries = 0;
				Counter = 0;
				//State = PassEntering;
				DISPLAY_SetState(PassEntering);
				break;
			}
			DISPLAY_ShiftAndDisplay(7,(uint8_t*)"Waiting");
			/*seconds remaining in the second row*/
			Counter ++;
			break;
		case SevenSegments: 
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			DISPLAY_ShiftAndDisplay(12,(uint8_t*)"System is ON");
			/*task of seven segment*/
			break;
		case ChangePassword:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			while (LCD_SendCommand(0xc0)!=OperationSuccess);
			for(uint8_t iterator = 0; iterator<Number_of_Asteriks; iterator++)
			{
				if(iterator>6)
				break;
				while(LCD_SendData('*')!=OperationSuccess);
			}
			DISPLAY_ShiftAndDisplay(13,(uint8_t*)"Changing Pass");
			/*Stars on the second ROW*/
			break;
		default:
			while (LCD_SendCommand(LCD_CLR)!=OperationSuccess);
			break;
	}
	Last_state = State;
}
void DISPLAY_ShiftAndDisplay(uint8_t StringLength, uint8_t* StringPTR)
{
	uint8_t static State = OperationStarted;
	
	switch(State)
	{
		case OperationStarted:
			if(Position<16-StringLength)
			{
				State = ShiftingRight;
			}
			else if (Position == 15-StringLength)
			{
				State = ShiftingLeft;
			}
			else
			{
				Position = 0;
				State = ShiftingRight;
			}
			break;
		case ShiftingRight:
			while(LCD_SendCommand(0x80|Position) != OperationSuccess);
			while(LCD_SendString(StringPTR) != OperationSuccess);
			while(LCD_SendCommand(0x80|(Position-1)) != OperationSuccess);
			while(LCD_SendData(' ')!= OperationSuccess);
			if (Position == 16-StringLength)
			{
				 State = ShiftingLeft;
			}
			Position++;
			break;
		case ShiftingLeft:
			Position--;
			if (Position == 0)
			{
				State = ShiftingRight;
			}
			while(LCD_SendCommand(0x80|Position) != OperationSuccess);
			while(LCD_SendString(StringPTR) != OperationSuccess);
			while(LCD_SendData(' ')!= OperationSuccess);
			break;
		default:
			break;
	}
}