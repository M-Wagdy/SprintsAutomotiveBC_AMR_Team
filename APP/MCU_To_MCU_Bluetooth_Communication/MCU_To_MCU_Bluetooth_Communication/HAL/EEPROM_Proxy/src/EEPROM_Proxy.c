/*
 * EEPROM_Proxy.c
 *
 * Created: 9/8/2021 8:37:23 AM
 *  Author: Ahmed Adel
 */ 
#include "EEPROM_Proxy.h"
//static uint8_t Last_Accessed_Position = 0; /*holds index of the last accessed position*/

ERROR_STATE_t EEPROM_ProxySaveToMemory(uint8_t* CharArr, uint16_t Starting_position, uint16_t* EndingPosition)
{
	/*initialize iterator variable*/
	uint8_t iterator = 0;
	/*return value initializing*/
	uint8_t ErrRetVal = OperationStarted;
	/*initializing the variable that will hold the CRC to be saved to the EEPROM*/
	uint16_t CyclicRedundancyCheck = 0;
	/*calculate the checksum bytes*/
	/*/CRC_16_Calc(ChatArr,&CyclicRedundancyCheck)/*///==> Line of un-implemented code
	CRC_16_Calc(CharArr, &CyclicRedundancyCheck);
	/*Initialize the value of EndingPosition*/
	uint8_t CurrentPosition = Starting_position;
	/*write the bytes with the calculated check sum to the memory*/
	for(;;)
	{
		/*check if Ending position is in range*/
		if(CurrentPosition < 1024)
		{
			/*check if end of the array is reached*/
			if(CharArr[iterator] == NULL_TERMINATOR)
			{
				/*save to EEPROM*/
				EEPROM_Write(CharArr[iterator],CurrentPosition);
				CurrentPosition++;
				iterator++;
				/*save calculated CRC bytes*/
				EEPROM_Write(CyclicRedundancyCheck>>8, CurrentPosition);
				CurrentPosition++;
				iterator++;
				EEPROM_Write((uint8_t)(CyclicRedundancyCheck&0x00FF), CurrentPosition);
				*EndingPosition = CurrentPosition;
				iterator++;
				ErrRetVal = OperationSuccess;
				/*break from for LOOP*/
				break;
			}
			else
			{
				/*save byte to the EEPROM*/
				EEPROM_Write(CharArr[iterator], CurrentPosition);
				CurrentPosition++;
				iterator++;
			}
		}
		else
		{
			ErrRetVal = OperationFail;
			break;
		}
	}
	return ErrRetVal;
}
ERROR_STATE_t EEPROM_ProxyLoadFromMemory(uint16_t StartingPosition, uint16_t EndingPosition, uint8_t* CharArr)
{
	/*initialize the static data buffer to return data back to the calling function 'retains data'*/
	//static uint8_t array[255];
	/*initializing the variable that will hold the CRC to be compared with the calculated one*/
	uint16_t CyclicRedundancyCheckLoaded = 0;
	uint16_t CyclicRedundancyCheck = 0;
	uint8_t CRC_HalfBits = 0;
	/*initialize iterator variable*/
	uint8_t iterator = 0;
	/*return value initializing*/
	uint8_t ErrRetVal = OperationStarted;
	/*initialize a variable that hold the current reading position*/
	uint16_t CurrentReadingPosition = StartingPosition;
	/*read the bytes with the calculated check sum to the memory*/
	for(;;)
	{
		if((CurrentReadingPosition<= EndingPosition) && (EndingPosition <= 1023))
		{
			/*load byte from the EEPROM*/
			EEPROM_Read(&(CharArr[iterator]), CurrentReadingPosition);
			CurrentReadingPosition++;
			/*check if end of the data is reached*/
			if(CharArr[iterator] == NULL_TERMINATOR)
			{
				/*load the calculated checksum bytes*/
				EEPROM_Read(&CRC_HalfBits, CurrentReadingPosition);
				CurrentReadingPosition++;
				iterator++;
				CyclicRedundancyCheckLoaded |= CRC_HalfBits;
				CyclicRedundancyCheckLoaded <<= 8;
				CurrentReadingPosition++;
				EEPROM_Read(&CRC_HalfBits, CurrentReadingPosition);
				CurrentReadingPosition++;
				iterator++;
				CyclicRedundancyCheckLoaded |= CRC_HalfBits;
				ErrRetVal = OperationSuccess;
				/*break from for LOOP*/
				//CharArr = array;
				break;
			}
			else if (CharArr[iterator] == 0xFF)
			{
				/*the memory is empty*/
				ErrRetVal = MemoryEmpty;
				break;
			}
			iterator++;
		}
		else
		{
			ErrRetVal = OperationFail;
		}	
	}
	/*calculate the CRC bytes*/
	/*/CRC_16_Calc(ChatArr,&CyclicRedundancyCheck)/*///==> Line of un-implemented code
	/*compare calculated to to the Loaded CRC*/
	/*/CRC_16_Check(ChatArr,&CyclicRedundancyCheck)/*///==> Line of un-implemented code
	/*return the error value*/
	return ErrRetVal;
}
ERROR_STATE_t EEPROM_EraseSection(uint16_t StartingPosition)
{
	uint8_t ErrRetVal = OperationStarted;
	ErrRetVal = EEPROM_Write(0xff,StartingPosition);
	return ErrRetVal;
}