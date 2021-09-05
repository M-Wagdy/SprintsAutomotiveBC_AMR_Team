/*
 * File Name: PWM_Lcfg.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for PWM Linker Configuration  ...
 */ 

  
#include "PWM_Lcfg.h"

Str_PWMConfig_t gastr_PWMConfig[PWM_CHANNEL_NUMBERS] = {
															{OC0_CLK_1024,OC0_FAST_PWM,NON_INVERTING},
															{OC1_CLK_1024,OC1_FAST_PWM_8BITS,NON_INVERTING},
															{OC1_CLK_1024,OC1_FAST_PWM_8BITS,NON_INVERTING},
															{OC2_NO_CLK,OC2_FAST_PWM,DISCONNECT},
													   };