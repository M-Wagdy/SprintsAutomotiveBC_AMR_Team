/*
 * DISPLAY.h
 *
 * Created: 9/7/2021 6:37:13 PM
 *  Author: Ahmed Adel
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "LCD.h"
void DISPLAY_MainFunction(void);
void DISPLAY_ShiftAndDisplay(uint8_t StringLength, uint8_t* StringPTR);


#endif /* DISPLAY_H_ */