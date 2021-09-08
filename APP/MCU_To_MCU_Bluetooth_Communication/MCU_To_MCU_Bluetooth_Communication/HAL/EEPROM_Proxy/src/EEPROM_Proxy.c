/*
 * EEPROM_Proxy.c
 *
 * Created: 9/8/2021 8:37:23 AM
 *  Author: Ahmed Adel
 */ 
#include "EEPROM_Proxy.h"
static uint8_t Last_Accessed_Position = 0; /*holds index of the last accessed position*/

ERROR_STATE_t EEPROM_ProxySaveToMemory(uint8_t* CharArr, uint16_t Starting_position)
{
	/*initialize iterator variable*/
	uint8_t iterator = 0;
	/*calculate the checksum bytes*/
	
	/*write the bytes with the calculated check sum to the memory*/
	for(;;iterator++)
	{
		/*check if end of the array is reached*/
		if(CharArr[iterator] == NULL_TERMINATOR)
		{
			/*save to EEPROM*/
			
			/*save calculated CRC bytes*/
			
			/*break from for LOOP*/
			break;
		}
		/*save byte to the EEPROM*/
		
	}
	return OperationSuccess;
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