/*
 * UTILS.c
 *
 *  Created on: Aug 9, 2021
 *      Author: AMR Team
 */
 
/*- INCLUDES
----------------------------------------------*/
#include "LIB.h"

/*- LOCAL MACROS
------------------------------------------*/
#define TRUE                  (uint8_t)(1)
#define FALSE                 (uint8_t)(0)

/*- APIs IMPLEMENTATION
-----------------------------------*/
/**
* @brief: This function is a dummy delay.
*/
void dummy_delay(void)
{
   for(volatile uint16_t i=0; i<100; i++)
   {
      for(volatile uint8_t j=0; j<32; j++)
      {
         for(volatile uint8_t k=0; k<2; k++)
         {
            
         }
      }
   }
}

/**
* @brief: This function compares if two strings are identical.
*
* @param [in]  str1   -  pointer to the first string.
* @param [in]  str2   -  pointer to the second string.
*
* @return function error state.
*/
uint8_t StringCompare(uint8_t * str1, uint8_t * str2)
{
   uint8_t u8_counter = 0;
   uint8_t u8_isEqual = TRUE;
   
   while(str1[u8_counter] != END_OF_STRING && str1[u8_counter] != NEW_LINE)
   {
      if(str1[u8_counter] != str2[u8_counter])
      {
         u8_isEqual = FALSE;
         u8_counter++;
         break;
      }
      u8_counter++;
   }
   if( str2[u8_counter] != END_OF_STRING )
   {
      u8_isEqual = FALSE;
   }
   return u8_isEqual;
}
/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/
uint8_t STR_Length(uint8_t* String, uint16_t* StringLength)
{
	*StringLength = 0;
	while(*String!='\0')
	{
		(*StringLength)++;
		String++;
	}
	return 0;
}
uint8_t STR_CharIsNumeric(uint8_t Character, uint8_t* Result)
{
	if(Character>=48 && Character<=57)
	{
		*Result=1;
	}
	else
	{
		*Result=0;
	}
	return 0;
}
uint8_t STR_StringIsNumeric(uint8_t* String, uint8_t* Result)
{
	uint8_t FunRetVal = 0;
	while(*String!='\0')
	{
		STR_CharIsNumeric(*String,&FunRetVal);
		if(!FunRetVal)
		{
			*Result = 0;
			break;
		}
		else
		{
			*Result = 1;
			String++;
			continue;
		}
	}
	return 0;
}
uint8_t STR_CompareString(uint8_t* String_1, uint8_t* String_2, uint8_t* Result)
{
	while(1)
	{
		if(*String_1==*String_2)
		{
			*Result = 1;
			String_1++;
			String_2++;
			if(*String_1=='\0'&&*String_2=='\0')
				break;
			continue;
		}
		else if(*String_1=='\0'&&*String_2=='\0')
		{
			*Result = 1;
			break;
		}
		else
		{
			*Result = 0;
			break;
		}
	}
	return 0;
}
uint8_t STR_String2Number(uint8_t* String, uint16_t* Number)
{
	uint32_t Multiplier=1;
	uint8_t* StartOfString=String;
	*Number=0;
	while(*String!='\0')
	{
		String++;
	}

	do
	{
		String--;
		(*Number)+=((*String-48)*Multiplier);
		Multiplier*=10;
	}while(String!=StartOfString);
	return 0;
}
uint8_t STR_Number2String(uint32_t Number, uint8_t* String)
{
	uint8_t* SringCpy = String;
	if(Number==0)
	{
		*String='0';
		*(String+1)='\0';
	}
	else
	{
		do
		{
			*String = (Number%10)+48;
			String++;
			Number/=10;
		}while(Number);
		*String = NULL_TERMINATOR;
	}
	STR_StringReverse(SringCpy);
	return 0;
}
uint8_t STR_StringReverse(uint8_t* String)
{
	uint8_t* A = String;
	uint8_t* B = String;
	uint8_t Temp = 0;
	while(*B != '\0')
	{
		B++;
	}
	B--;
	while(A<B)
	{
		//swap
		Temp=*A;
		*A=*B;
		*B=Temp;
		A++;B--;
	}
	return 0;
}
/*
Used websites:
https://www.rapidtables.com/convert/number/ascii-hex-bin-dec-converter.html
https://rndtool.info/CRC-step-by-step-calculator/
https://www.lammertbies.nl/comm/info/crc-calculation
https://www.youtube.com/watch?v=izG7qT0EpBw
*/
uint8_t CRC_16_Calc (uint8_t* STRING)
{
	/*change array of character to array of bits*/
	/*initialize the array of bits*/
	uint8_t BitArr[255] = {0};
	/*the value of the used polynomial for CRC_16*/
	const uint32_t polynomial = 0b00000000000000011000000000000101;
	/*variable that holds the value to be XORED and SHIFTED*/
	uint32_t volatile Window_16_Element =0;
	/*initialize the variable that holds the number of characters to which CRC is calculated*/
	/*number of characters in the inserted string*/
	uint16_t StrLength =0;
	/*initialize the variable that holds the number of bits in the inserted string*/
	uint8_t BitArr_Size = 0;
	/*using STR_Length() function to calculate Number of characters in the inserted String*/
	STR_Length(STRING, &StrLength);
	/*initializing the iterator for the array of bits of the inserted Character string*/
	uint8_t iterator_of_BitArr = 0;
	/*initializing the iterator for the array of the inserted Characters in the string*/
	uint8_t iterator_of_characters = 0;
	/*assigning the bits of the character in the passed string to the array of bits*/
	/*bits are arranged in the array the form of an extra long number"Index 0:MSB,..,..,..,. . .,Index N:LSB"*/
	for(iterator_of_characters = 0; iterator_of_characters < StrLength; iterator_of_characters++)
	{
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_7);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_6);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_5);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_4);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_3);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_2);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_1);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_0);
		iterator_of_BitArr++;
	}
	/*calculating the size of the array of bits taking into consideration the size of the 16 bits of CRC_16*/
	BitArr_Size = iterator_of_BitArr + 15;
	/*reset the iterator of the Bits Array to zero to iterate through the array*/
	iterator_of_BitArr = 0;
	/*Moving to the first occurance of high bit to start our CRC calculation*/
	while(BitArr[iterator_of_BitArr]!=1)
	{
		/*increment the iterator to the first occurance of High bit*/
		iterator_of_BitArr++;
	}
	for (uint8_t i = 0; i<=16; i++)
	{
		Window_16_Element |= ((uint32_t)BitArr[iterator_of_BitArr+i]<<(16-i));
	}
	/*Start the modulo Operation continues until the polynomial doesn't fit into the reminder*/
	while(iterator_of_BitArr < BitArr_Size-15)
	{
		/*Xoring operation between the Window and the polynomial*/
			Window_16_Element ^= polynomial;
			if(!Window_16_Element)
				break;
		if(iterator_of_BitArr < BitArr_Size-16)
		{
			do 
			{
			Window_16_Element <<= 1;
			iterator_of_BitArr++;
			/*Adding new element from the array of bits to the window*/
			Window_16_Element |= (uint16_t)BitArr[iterator_of_BitArr+16];
			} while ((Get_Bit(Window_16_Element,16) == 0));
		}
		else
		{
			iterator_of_BitArr++;
		}
	}
	/*Add the calculated CRC to the End of the Passed String*/
	STRING[StrLength] = (uint8_t)(Window_16_Element>>8);
	STRING[StrLength+1] = (uint8_t)(Window_16_Element&0x000000FF);
	STRING[StrLength+2] = NULL_TERMINATOR;
	/*return zero*/
	return OperationSuccess;
}

uint8_t CRC_16_Chk (uint8_t* STRING)
{
	/*change array of character to array of bits*/
	/*initialize the array of bits*/
	uint8_t BitArr[255] = {0};
	/*Error Return value*/
	uint8_t ErrRetVal = ERROR_OK;
	/*the value of the used polynomial for CRC_16*/
	const uint32_t polynomial = 0b00000000000000011000000000000101;
	/*variable that holds the value to be XORED and SHIFTED*/
	uint32_t volatile Window_16_Element =0;
	/*initialize the variable that holds the number of characters to which CRC is calculated*/
	/*number of characters in the inserted string*/
	uint16_t StrLength =0;
	/*initialize the variable that holds the number of bits in the inserted string*/
	uint8_t BitArr_Size = 0;
	/*using STR_Length() function to calculate Number of characters in the inserted String*/
	STR_Length(STRING, &StrLength);
	/*initializing the iterator for the array of bits of the inserted Character string*/
	uint8_t iterator_of_BitArr = 0;
	/*initializing the iterator for the array of the inserted Characters in the string*/
	uint8_t iterator_of_characters = 0;
	/*assigning the bits of the character in the passed string to the array of bits*/
	/*bits are arranged in the array the form of an extra long number"Index 0:MSB,..,..,..,. . .,Index N:LSB"*/
	for(iterator_of_characters = 0; iterator_of_characters < StrLength; iterator_of_characters++)
	{
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_7);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_6);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_5);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_4);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_3);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_2);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_1);
		iterator_of_BitArr++;
		BitArr[iterator_of_BitArr] = READ_BIT(STRING[iterator_of_characters],BIT_0);
		iterator_of_BitArr++;
	}
	/*calculating the size of the array of bits taking into consideration the size of the 16 bits of CRC_16*/
	BitArr_Size = iterator_of_BitArr + 15;
	/*reset the iterator of the Bits Array to zero to iterate through the array*/
	iterator_of_BitArr = 0;
	/*Moving to the first occurance of high bit to start our CRC calculation*/
	while(BitArr[iterator_of_BitArr]!=1)
	{
		/*increment the iterator to the first occurance of High bit*/
		iterator_of_BitArr++;
	}
	for (uint8_t i = 0; i<=16; i++)
	{
		Window_16_Element |= ((uint32_t)BitArr[iterator_of_BitArr+i]<<(16-i));
	}
	/*Start the modulo Operation continues until the polynomial doesn't fit into the reminder*/
	while(iterator_of_BitArr < BitArr_Size-16)
	{
		/*Xoring operation between the Window and the polynomial*/
		Window_16_Element ^= polynomial;
		if(!Window_16_Element)
			break;
		if((iterator_of_BitArr < BitArr_Size-16))
		{
			do
			{
				Window_16_Element <<= 1;
				iterator_of_BitArr++;
				/*Adding new element from the array of bits to the window*/
				Window_16_Element |= (uint16_t)BitArr[iterator_of_BitArr+16];
			} while ((Get_Bit(Window_16_Element,16) == 0));
		}
	}
	if((uint16_t)Window_16_Element != 0)
		ErrRetVal = ERROR_NOK;
	else
		ErrRetVal = ERROR_OK;
	return ErrRetVal;
}
