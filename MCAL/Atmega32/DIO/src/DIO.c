/*
 * File Name: DIO.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for DIO peripheral....
 */ 

#include "MC_REGISTERS.h"
#include "DIO.h"

ERROR_STATE_t DIO_SetPinDirection(uint8_t PortName , uint8_t PinNo ,uint8_t PinDirection)
{
	uint8_t u8_ErrorState=ERROR_OK;
	if((PIN_INPUT!=PinDirection)&&(PIN_OUTPUT!=PinDirection))
	{
		u8_ErrorState=ERROR_NOK;
	}
	else if(PinNo>PIN7)
	{
		u8_ErrorState=ERROR_NOK;
	}
	else
	{
		switch(PortName)
		{
			case PORT_A:
				BIT_WRITE(DDRA,PinNo,PinDirection);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_B:
				BIT_WRITE(DDRB,PinNo,PinDirection);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_C:
				BIT_WRITE(DDRC,PinNo,PinDirection);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_D:
				BIT_WRITE(DDRD,PinNo,PinDirection);
				u8_ErrorState=ERROR_OK;
				break;
			default:
				u8_ErrorState=ERROR_NOK;
				break;
		}		
	}
	return u8_ErrorState;
}

ERROR_STATE_t DIO_WritePin(uint8_t PortName , uint8_t PinNo ,uint8_t PinValue)
{
	uint8_t u8_ErrorState=ERROR_OK;
	if((PIN_LOW!=PinValue)&&(PIN_HIGH!=PinValue))
	{
		u8_ErrorState=ERROR_NOK;
	}
	else if(PinNo>PIN7)
	{
		u8_ErrorState=ERROR_NOK;
	}
	else
	{
		switch(PortName)
		{
			case PORT_A:
				BIT_WRITE(PORTA,PinNo,PinValue);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_B:
				BIT_WRITE(PORTB,PinNo,PinValue);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_C:
				BIT_WRITE(PORTC,PinNo,PinValue);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_D:
				BIT_WRITE(PORTD,PinNo,PinValue);
				u8_ErrorState=ERROR_OK;
				break;
			default:
				u8_ErrorState=ERROR_NOK;
				break;
		}
	}	
	return u8_ErrorState;
}
ERROR_STATE_t DIO_TogglePin(uint8_t PortName,uint8_t PinNo)
{
	uint8_t u8_ErrorState=ERROR_OK;
	if(PinNo>PIN7)
	{
		u8_ErrorState=ERROR_NOK;
	}
	else
	{
		switch(PortName)
		{
			case PORT_A:
				BIT_TOGGLE(PORTA,PinNo);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_B:
				BIT_TOGGLE(PORTB,PinNo);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_C:
				BIT_TOGGLE(PORTC,PinNo);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_D:
				BIT_TOGGLE(PORTD,PinNo);
				u8_ErrorState=ERROR_OK;
				break;
			default:
				u8_ErrorState=ERROR_NOK;
				break;	
		}	
	}	
	return u8_ErrorState;
}
ERROR_STATE_t DIO_ReadPin(uint8_t PortName,uint8_t PinNo,ptr_uint8_t PinData)
{
	uint8_t u8_ErrorState=ERROR_OK;
	if(PinNo>PIN7)
	{
		u8_ErrorState=ERROR_NOK;
	}
	else if(NULL_PTR==PinData)
	{
		u8_ErrorState=ERROR_NOK;
	}
	else
	{
		switch(PortName)
		{
			case PORT_A:
				* PinData=BIT_GET(PINA,PinNo);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_B:
				* PinData=BIT_GET(PINB,PinNo);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_C:
				* PinData=BIT_GET(PINC,PinNo);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_D:
				* PinData=BIT_GET(PIND,PinNo);
				u8_ErrorState=ERROR_OK;
				break;
			default:
				u8_ErrorState=ERROR_NOK;
				break;
		}
	}	
	return u8_ErrorState;
}


ERROR_STATE_t DIO_EnablePinPullup(uint8_t PortName,uint8_t PinNo)
{
	uint8_t u8_ErrorState=ERROR_OK;
	if(PinNo>PIN7)
	{
		u8_ErrorState=ERROR_NOK;
	}
	else
	{	
		switch(PortName)
		{
			case PORT_A:
				BIT_WRITE(PORTA,PinNo,PIN_HIGH);
				u8_ErrorState=ERROR_OK;
				break;
			case PORT_B:
				BIT_WRITE(PORTB,PinNo,PIN_HIGH);
				u8_ErrorState=ERROR_OK;
				break;                            
			case PORT_C:                          
				BIT_WRITE(PORTC,PinNo,PIN_HIGH);
				u8_ErrorState=ERROR_OK;
				break;                            
			case PORT_D:                          
				BIT_WRITE(PORTD,PinNo,PIN_HIGH);
				u8_ErrorState=ERROR_OK;
				break;
			default:
				u8_ErrorState=ERROR_NOK;
				break;
		}	
	}	
	return u8_ErrorState;
}