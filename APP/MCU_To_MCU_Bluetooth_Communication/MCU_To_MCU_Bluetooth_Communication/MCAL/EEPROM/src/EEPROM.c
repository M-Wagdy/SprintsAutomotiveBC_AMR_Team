/*
 * EEPROM.c
 *
 * Created: 9/6/2021 6:08:02 AM
 *  Author: Ahmed Adel
 */ 

#include "EEPROM.h"

uint8_t EEPROM_Init(void)
{
	uint16_t Iterator = 0;
	for(Iterator = 0; Iterator < 1024; Iterator++)
	{
		EEPROM_Write(NULL_TERMINATOR,Iterator);
	}
	return OperationSuccess;
}
uint8_t EEPROM_Read(uint8_t * Data,uint16_t Address)
{
	uint8_t ErrRetVal = OperationStarted;
	uint8_t StatusRegVal = 0;
	/*1. Wait until EEWE becomes zero.*/
	if(~(READ_BIT(EECR,EEWE)))
	{
		/*2. Write new EEPROM address to EEAR (optional).*/
		WRITE_REG(EEAR, Address);
		/*3. Disable the Global Interrupt*/ 
		StatusRegVal = READ_REG(SREG);
		CLEAR_BIT(SREG, I);
		/*4. Start EEPROM read by writing a logical one to EERE bit in EECR*/
		SET_BIT(EECR,EERE);
		/*5. get data from the EEPROM EEDR*/
		*Data = READ_REG(EEDR);
		/*6. Return the state of status register*/
		WRITE_REG(SREG, StatusRegVal);
		/*7. Set function's return*/
		ErrRetVal = OperationSuccess;
	}
	else
	{
		ErrRetVal = OperationFail;
	}
	return ErrRetVal;
}
uint8_t EEPROM_Write(uint8_t Data,uint16_t Address)
{
	uint8_t ErrRetVal = OperationStarted;
	uint8_t StatusRegVal = 0;
	/*1. Wait until EEWE becomes zero.*/
	/*2. Wait until SPMEN in SPMCR becomes zero.*/
	if(~(READ_BIT(EECR,EEWE) || READ_BIT(SPMCR,SPMEN)))
	{
		/*3. Write new EEPROM address to EEAR (optional).*/
		WRITE_REG(EEARH, 0x00);
		WRITE_REG(EEARL, 0x05);
		/*4. Write new EEPROM data to EEDR (optional).*/
		WRITE_REG(*((volatile ptr_uint8_t)(0X3D)), Data);
		/*5. Disable the Global Interrupt*/
		StatusRegVal = READ_REG(SREG);
		CLEAR_BIT(SREG, I);
		/*6. Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR.*/
		SET_BIT(EECR, EEMWE);
		/*7. Within four clock cycles after setting EEMWE, write a logical one to EEWE.*/
		SET_BIT(EECR, EEWE);
		/*8. Return the state of status register*/
		WRITE_REG(SREG, StatusRegVal);
		/*9. Set function's return*/
		ErrRetVal = OperationSuccess;			
	}
	else
	{
		ErrRetVal = OperationFail;
	}
		return ErrRetVal;
}
//void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
//{
	///* Wait for completion of previous write */
	//while(EECR & (1<<EEWE))
	//;
	///* Set up address and data registers */
	//EEAR = uiAddress;
	//EEDR = ucData;
	///* Write logical one to EEMWE */
	////for(volatile int i = 0; i<5000;i++)
	////EECR |= (1<<EEMWE);
	////CLEAR_BIT(EECR,EEMWE);
	////CLEAR_BIT(EECR,EEWE);
	////for(volatile int i = 0; i<5000;i++);
	////SET_BIT(EECR,EEMWE);
	///* Start eeprom write by setting EEWE */
	////EECR |= (1<<EEMWE)|(1<<EEWE);
	//EECR =0x04;
	//EECR =0x02;
	////SET_BIT(EECR,EEWE);
	//while(READ_BIT(EECR,EEWE));
	//for(volatile int i = 0; i<5000;i++);
//}
//unsigned char EEPROM_read(unsigned int uiAddress)
//{
	///* Wait for completion of previous write */
	//while(EECR & (1<<EEWE))
	//;
	///* Set up address register */
	//EEAR = uiAddress;
	///* Start eeprom read by writing EERE */
	//EECR |= (1<<EERE);
	///* Return data from data register */
	//return EEDR;
//}
