/*
 * DISPLAY.h
 *
 * Created: 9/7/2021 6:37:13 PM
 *  Author: Ahmed Adel
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "LCD.h"
#define ShiftingLeft 1
#define ShiftingRight 2
#define SystemLoading 3
#define Welcome 4
#define PassEntering 5
#define CorrectPassword 6
#define WrongPassword 7
#define Waiting 8
#define SevenSegments 9
#define ChangePassword 10
void DISPLAY_MainFunction(void);
void DISPLAY_ShiftAndDisplay(uint8_t StringLength, uint8_t* StringPTR);


#endif /* DISPLAY_H_ */