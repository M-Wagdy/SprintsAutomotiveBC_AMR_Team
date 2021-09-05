/*
 * File Name: PWM_Lcfg.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for PWM Linker Configuration ...
 */ 
 
#ifndef __PWM_LCFG__
#define __PWM_LCFG__

#include "STD_TYPES.h"

#define PWM_CHANNEL_NUMBERS (4)

//PwmOc0Modes
#define OC0_PHASE_CORRECT_PWM 				1
#define OC0_FAST_PWM 						3

//PwmOc1Modes
#define OC1_PHASE_CORRECT_8BITS  			1
#define OC1_PHASE_CORRECT_9BITS  			2
#define OC1_PHASE_CORRECT_10BITS  			3
#define OC1_FAST_PWM_8BITS  				5
#define OC1_FAST_PWM_9BITS  				6
#define OC1_FAST_PWM_10BITS  				7
#define OC1_PHASE_FREQUENCY_CORRECT_ICR1  	8
#define OC1_PHASE_FREQUENCY_CORRECT_OCR1A  	9
#define OC1_PHASE_CORRECT_ICR1  			10
#define OC1_PHASE_CORRECT_OCR1A  			11	
#define OC1_FAST_PWM_ICR1  					14
#define OC1_FAST_PWM_OCR1A  				15

//PwmOc2Modes
#define OC2_PHASE_CORRECT_PWM 				1
#define OC2_FAST_PWM						3

//PwmChannelWaveformModes
#define DISCONNECT							0
#define NON_INVERTING						2
#define INVERTING							3

enum Enu_PwmOc0Frequency
{
	OC0_NO_CLK = 0,
	OC0_CLK_1 = 1,
	OC0_CLK_8 = 2,
	OC0_CLK_64 = 3,
	OC0_CLK_256 = 4,
	OC0_CLK_1024 = 5
};

enum Enu_PwmOc1Frequency
{
	OC1_NO_CLK = 0,
	OC1_CLK_1 = 1,
	OC1_CLK_8 = 2,
	OC1_CLK_64 = 3,
	OC1_CLK_256 = 4,
	OC1_CLK_1024 = 5
};

enum Enu_PwmOc2Frequency
{
	OC2_NO_CLK = 0,
	OC2_CLK_1 = 1,
	OC2_CLK_8 = 2,
	OC2_CLK_32 = 3,
	OC2_CLK_64 = 4,
	OC2_CLK_128 = 5,
	OC2_CLK_256 = 6,
	OC2_CLK_1024 = 7,	
};	

typedef struct Str_PWMConfig
{
	uint8_t PWMFrequancy;
	uint8_t PWMMode;
	uint8_t PWMWaveformMode;
}Str_PWMConfig_t ;

#endif