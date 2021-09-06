/*
 * HMI.c
 *
 * Created: 9/5/2021 6:39:36 PM
 * Author: Mohamed Wagdy
 */ 

/*INCLUDES-------------------------------*/
#include "MC_REGISTERS.h"
#include "math.h"
#include "Keypad.h"
#include "HMI.h"
#include "HMI_Interface.h"

/*- LOCAL MACROS
------------------------------------------*/
#define DEVICE_ERASE_VALUE          (uint32_t)(0x1043)
#define PASSWORD_CHANGE_VALUE       (uint32_t)(0x443)
#define MULTI_PRESS_BIT             (uint32_t)(1)

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const uint8_t KP_UsedChannel;

/*APIs IMPLEMENTATION------------------------*/
/**
* @brief: This function is the HMI main function.
*
* @return function error state.
*/
extern void HMI_MainFunction(void)
{
   ERROR_STATE_t KP_ErrorState;
   static uint8_t u8_Init = 0;
   uint32_t u32_Key;
   static uint32_t u32_OldKey = 0;
   
   if (u8_Init == 0)
   {
      KP_Init(KP_UsedChannel);
      DDRB = 0xF0;
      u8_Init = 1;
   }
   
   KP_ErrorState = KP_GetPressedValue(KP_UsedChannel, &u32_Key);
   if(KP_ErrorState == ERROR_OK && u32_OldKey != u32_Key)
   {
      u32_OldKey = u32_Key;
      if(MULTI_PRESS_BIT & u32_Key)
      {
         if(DEVICE_ERASE_VALUE == u32_Key)
         {
            HMI_SetDeviceEraseFlag();
            PORTB = (13<<4);
         }
         else if(PASSWORD_CHANGE_VALUE == u32_Key)
         {
            HMI_SetPasswordChangeFlag();
            PORTB = (14<<4);
         }
         else
         {
            PORTB &= ~(0xF0);
         }
      }
      else if(u32_Key != 0)
      {
         u32_Key = (log(u32_Key)/log(2));
         HMI_SetKeyPressed(u32_Key);
         PORTB = (u32_Key<<4);
      }
      else
      {
         PORTB &= ~(0xF0);
      }
   }
}