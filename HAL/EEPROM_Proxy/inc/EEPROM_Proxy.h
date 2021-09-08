/*
 * EEPROM_Proxy.h
 *
 * Created: 9/8/2021 8:37:05 AM
 *  Author: vetmo
 */ 


#ifndef EEPROM_PROXY_H_
#define EEPROM_PROXY_H_
#include "EEPROM.h"
ERROR_STATE_t EEPROM_ProxySaveToMemory(uint8_t* CharArr, uint16_t Starting_position);
ERROR_STATE_t EEPROM_ProxyLoadFromMemory(uint16_t StartingPosition, uint8_t* CharArr);

#endif /* EEPROM_PROXY_H_ */