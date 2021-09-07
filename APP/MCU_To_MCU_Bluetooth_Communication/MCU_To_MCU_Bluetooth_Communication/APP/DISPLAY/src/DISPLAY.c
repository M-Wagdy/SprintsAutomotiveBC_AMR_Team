
/*
 * DISPLAY.c
 *
 * Created: 9/7/2021 6:37:39 PM
 *  Author: Ahmed Adel
 */ 
#include "DISPLAY.h"
#define ShiftingLeft 1
#define ShiftingRight 2
uint8_t Position = 0;
void DISPLAY_MainFunction(void)
{
	
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
/*
while(LCD_SendCommand(0x80|Position) != OperationSuccess);
while(LCD_SendString(StringPTR) != OperationSuccess);
while(LCD_SendCommand(0x80|Position) != OperationSuccess);
while(LCD_SendData(' ')!= OperationSuccess);
Position++;*/