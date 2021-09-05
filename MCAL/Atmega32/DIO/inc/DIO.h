/*
 * File Name: DIO.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for DIO peripheral....
 */ 

#ifndef __DIO__
#define __DIO__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//PORTS NAME
enum Enu_DIOPortName
{
	PORT_A = 0,
	PORT_B = 1,
	PORT_C = 2,
	PORT_D = 3	
};

//PINS
enum Enu_DIOPinNumber
{
	PIN0 = 0,
	PIN1 = 1,
	PIN2 = 2,
	PIN3 = 3,
	PIN4 = 4,
	PIN5 = 5,
	PIN6 = 6,
	PIN7 = 7	
};

//PIN Directions
enum Enu_DIOPinDirection
{
	PIN_INPUT = 0,
	PIN_OUTPUT = 1
};

enum Enu_DIOPinValue
{
	PIN_LOW = 0,
	PIN_HIGH = 1
};

//FUNCTIONS PROTOTYPES
ERROR_STATE_t DIO_SetPinDirection(uint8_t PortName , uint8_t PinNo ,uint8_t PinDirection);
ERROR_STATE_t DIO_WritePin(uint8_t PortName , uint8_t PinNo ,uint8_t PinValue);
ERROR_STATE_t DIO_TogglePin(uint8_t PortName,uint8_t PinNo);
ERROR_STATE_t DIO_ReadPin(uint8_t PortName,uint8_t PinNo,ptr_uint8_t PinData);
ERROR_STATE_t DIO_EnablePinPullup(uint8_t PortName,uint8_t PinNo);

#endif
