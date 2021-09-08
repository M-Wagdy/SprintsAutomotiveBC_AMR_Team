/*
 * EEPROM_Proxy.c
 *
 * Created: 9/8/2021 8:37:23 AM
 *  Author: Ahmed Adel
 */ 
#include "EEPROM_Proxy.h"
static uint8_t Last_Accessed_Position = 0; /*holds index of the last accessed position*/

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
	/*Initialize the value of EndingPosition*/
	*EndingPosition = Starting_position;
	/*write the bytes with the calculated check sum to the memory*/
	for(;;iterator++)
	{
		/*check if Ending position is in range*/
		if(*EndingPosition < 1024)
		{
			/*save byte to the EEPROM*/
			EEPROM_Write(CharArr[iterator], *EndingPosition);
			*EndingPosition++;
			/*check if end of the array is reached*/
			if(CharArr[iterator] == NULL_TERMINATOR)
			{
				/*save to EEPROM*/
				EEPROM_Write(CharArr[iterator],*EndingPosition);
				*EndingPosition++;
				/*save calculated CRC bytes*/
				EEPROM_Write(CyclicRedundancyCheck>>8, *EndingPosition);
				*EndingPosition++;
				EEPROM_Write((uint8_t)(CyclicRedundancyCheck|0x00FF), *EndingPosition);
				ErrRetVal = OperationSuccess;
				/*break from for LOOP*/
				break;
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
ERROR_STATE_t EEPROM_ProxyLoadFromMemory(uint16_t StartingPosition, uint8_t* CharArr)
{
	/*initialize the static data buffer to return data back to the calling function 'retains data'*/
	static uint8_t array[255];
	/*initializing the variable that will hold the CRC to be compared with the calculated one*/
	uint16_t CyclicRedundancyCheck = 0;
	/*initialize iterator variable*/
	uint8_t iterator = 0;
	/*return value initializing*/
	uint8_t ErrRetVal = OperationStarted;
	/*read the bytes with the calculated check sum to the memory*/
	for(;;iterator++)
	{
		/*check if end of the data is reached*/
		if(CharArr[iterator] == NULL_TERMINATOR)
		{
			/*Load from EEPROM*/
			
			/*load the calculated checksum bytes*/
			
			/*break from for LOOP*/
			break;
		}
		else if(CharArr[iterator] == 0xFF)
		{
			/*the memory is empty*/
			break;
		}
		/*load byte from the EEPROM*/
	}
	/*calculate the CRC bytes*/
	
	/*compare calculated to to the Loaded CRC*/
	
	/*return the error value*/
	return ErrRetVal;
}