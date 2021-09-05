/*
 * File Name: PWM.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for PWM peripheral....
 */ 

#ifndef __PWM__
#define __PWM__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "PWM_Cfg.h"
#include "PWM_Lcfg.h"

enum Enu_PwmChannelNumber
{
	PWM_CHANNEL_OC0 = 0,
	PWM_CHANNEL_OC1A = 1,
	PWM_CHANNEL_OC1B = 2,
	PWM_CHANNEL_OC2 = 3
};

//FUNCTIONS PROTOTYPES
ERROR_STATE_t PWM_Init(uint8_t PwmChannelNumber);
ERROR_STATE_t PWM_Start(uint8_t PwmChannelNumber);
ERROR_STATE_t PWM_Stop(uint8_t PwmChannelNumber);
ERROR_STATE_t PWM_Connect(uint8_t PwmChannelNumber);
ERROR_STATE_t PWM_Disconnect(uint8_t PwmChannelNumber);
ERROR_STATE_t PWM_SetDuty(uint8_t PwmChannelNumber,uint8_t PwmDuty);

#endif
