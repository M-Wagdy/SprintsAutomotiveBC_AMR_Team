/*
 * LED.c
 *
 * Created: 7/7/2021 1:50:26 PM
 * Author: Mohamed Wagdy
 */ 

/*- INCLUDES
----------------------------------------------*/
#include "DIO.h"
#include "PWM.h"
#include "LED.h"

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static uint8_t gu8_IsLEDInit[LED_CH_NUMBERS] = {NOT_INIT};

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/
extern const STR_LED_config_t gSTR_LEDConfig[LED_CH_NUMBERS];

/*- APIs IMPLEMENTATION
-----------------------------------*/

/**
* @brief: This function initialize LEDs.
*
* @param [in]  LED_ch   -  LED channel number.
*
* @return function error state.
*/
extern ERROR_STATE_t LED_Init(uint8_t LED_ch)
{
   ERROR_STATE_t LED_ErrorState;
   
   /* Check valid channel */
   if(LED_INVALID_CH <= LED_ch)
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_INVALID_CH_NO);
   }
   /* check if init function was called before */
   else if(INIT == gu8_IsLEDInit[LED_ch])
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_INIT_BEFORE);
   }
   else
   {
      if(PWM_OFF == gSTR_LEDConfig[LED_ch].u8_PWM)
      {
         ERROR_STATE_t DIO_ErrorState;
         
         /* configure LED pin */
         DIO_ErrorState = DIO_SetPinDirection(gSTR_LEDConfig[LED_ch].u8_LEDPort, gSTR_LEDConfig[LED_ch].u8_LEDPin, PIN_OUTPUT);
         /* make sure pin configuration is successful */
         if(ERROR_OK != DIO_ErrorState)
         {
            LED_ErrorState = ERROR_NOK;
         }
         else
         {
            gu8_IsLEDInit[LED_ch] = INIT;
            LED_ErrorState = ERROR_OK;
         }
      }
      else if(PWM_ON == gSTR_LEDConfig[LED_ch].u8_PWM)
      {
         ERROR_STATE_t ErrorState;
         
         ErrorState = PWM_Init(gSTR_LEDConfig[LED_ch].u8_PWMCh);
         ErrorState |= DIO_SetPinDirection(gSTR_LEDConfig[LED_ch].u8_LEDPort, gSTR_LEDConfig[LED_ch].u8_LEDPin, PIN_OUTPUT);
         /*START THE PWM WAVE*/
         ErrorState |= PWM_Start(gSTR_LEDConfig[LED_ch].u8_PWMCh);
         ErrorState |= PWM_Connect(gSTR_LEDConfig[LED_ch].u8_PWMCh);
         if(ERROR_OK != ErrorState)
         {
            LED_ErrorState = ERROR_NOK;
         }  
         else
         {
            gu8_IsLEDInit[LED_ch] = INIT;
            LED_ErrorState = ERROR_OK;
         }          
      }
      else
      {
         LED_ErrorState = ERROR_NOK;
      }   
   }
   
   return LED_ErrorState;
}

/**
* @brief: This function turns off a LED.
*
* @param [in]  LED_ch   -  LED channel number.
*
* @return function error state.
*/
extern ERROR_STATE_t LED_Off(uint8_t LED_ch)
{
   ERROR_STATE_t LED_ErrorState;
   
   /* Check valid channel */
   if(LED_INVALID_CH <= LED_ch)
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_INVALID_CH_NO);
   }
   /* check if init function wasn't called before */
   else if(INIT != gu8_IsLEDInit[LED_ch])
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_NOT_INIT);
   }
   else
   {
      if(PWM_OFF == gSTR_LEDConfig[LED_ch].u8_PWM)
      {
         ERROR_STATE_t DIO_ErrorState;
         
         /* set LED pin to low */
         DIO_ErrorState = DIO_WritePin(gSTR_LEDConfig[LED_ch].u8_LEDPort, gSTR_LEDConfig[LED_ch].u8_LEDPin, PIN_LOW);
         
         /* make sure DIO function was successful */
         if(ERROR_OK != DIO_ErrorState)
         {
            LED_ErrorState = ERROR_NOK;
         }
         else
         {
            LED_ErrorState = ERROR_OK;
         }
      }
      else if(PWM_ON == gSTR_LEDConfig[LED_ch].u8_PWM)
      {
         ERROR_STATE_t PWM_ErrorState;
         
         PWM_ErrorState = PWM_SetDuty(gSTR_LEDConfig[LED_ch].u8_PWMCh, 0);
         
         if(ERROR_OK != PWM_ErrorState)
         {
            LED_ErrorState = ERROR_NOK;
         }
         else
         {
            LED_ErrorState = ERROR_OK;
         }
      }
      else
      {
         LED_ErrorState = ERROR_NOK;
      }
   }
   
   return LED_ErrorState;
}

/**
* @brief: This function turns on a LED.
*
* @param [in]  LED_ch   -  LED channel number.
*
* @return function error state.
*/
extern ERROR_STATE_t LED_On(uint8_t LED_ch)
{
   ERROR_STATE_t LED_ErrorState;
   
   /* Check valid channel */
   if(LED_INVALID_CH <= LED_ch)
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_INVALID_CH_NO);
   }
   /* check if init function wasn't called before */
   else if(INIT != gu8_IsLEDInit[LED_ch])
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_NOT_INIT);
   }
   else
   {
      if(PWM_OFF == gSTR_LEDConfig[LED_ch].u8_PWM)
      {
         ERROR_STATE_t DIO_ErrorState;
         
         /* set LED pin to low */
         DIO_ErrorState = DIO_WritePin(gSTR_LEDConfig[LED_ch].u8_LEDPort, gSTR_LEDConfig[LED_ch].u8_LEDPin, PIN_HIGH);
         
         /* make sure DIO function was successful */
         if(ERROR_OK != DIO_ErrorState)
         {
            LED_ErrorState = ERROR_NOK;
         }
         else
         {
            LED_ErrorState = ERROR_OK;
         }
      }
      else if(PWM_ON == gSTR_LEDConfig[LED_ch].u8_PWM)
      {
         ERROR_STATE_t PWM_ErrorState;
         
         PWM_ErrorState = PWM_SetDuty(gSTR_LEDConfig[LED_ch].u8_PWMCh, 100);
         
         if(ERROR_OK != PWM_ErrorState)
         {
            LED_ErrorState = ERROR_NOK;
         }
         else
         {
            LED_ErrorState = ERROR_OK;
         }
      }
      else
      {
         LED_ErrorState = ERROR_NOK;
      }
   }
   
   return LED_ErrorState;
}

/**
* @brief: This function turns on a LED with a certain duty.
*
* @param [in]  LED_ch   -  LED channel number.
* @param [in]  Duty     -  Duty cycle to turn the led with.
*
* @return function error state.
*/
extern ERROR_STATE_t LED_Dim(uint8_t LED_ch, uint8_t Duty)
{
   ERROR_STATE_t LED_ErrorState;
   
   /* Check valid channel */
   if(LED_INVALID_CH <= LED_ch)
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_INVALID_CH_NO);
   }
   /* check if init function wasn't called before */
   else if(INIT != gu8_IsLEDInit[LED_ch])
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_NOT_INIT);
   }
   else if(PWM_OFF == gSTR_LEDConfig[LED_ch].u8_PWM)
   {
      LED_ErrorState = ERROR_NOK;
   }
   else if(100 < Duty)
   {
      LED_ErrorState = ERROR_NOK;
   }     
   else
   {
      ERROR_STATE_t PWM_ErrorState;
         
      PWM_ErrorState = PWM_SetDuty(gSTR_LEDConfig[LED_ch].u8_PWMCh, Duty);
         
      if(ERROR_OK != PWM_ErrorState)
      {
         LED_ErrorState = ERROR_NOK;
      }
      else
      {
         LED_ErrorState = ERROR_OK;
      }
   }
   
   return LED_ErrorState;
}
   
/**
* @brief: This function toggles a LED.
*
* @param [in]  LED_ch   -  LED channel number.
*
* @return function error state.
*/
extern ERROR_STATE_t LED_Toggle(uint8_t LED_ch)
{
   ERROR_STATE_t LED_ErrorState;
   
   /* Check valid channel */
   if(LED_INVALID_CH <= LED_ch)
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_INVALID_CH_NO);
   }
   /* check if init function wasn't called before */
   else if(INIT != gu8_IsLEDInit[LED_ch])
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_NOT_INIT);
   }
   else if(PWM_ON == gSTR_LEDConfig[LED_ch].u8_PWM)
   {
      LED_ErrorState = ERROR_NOK;
   }      
   else
   {
      ERROR_STATE_t DIO_ErrorState;
         
      /* set LED pin to low */
      DIO_ErrorState = DIO_TogglePin(gSTR_LEDConfig[LED_ch].u8_LEDPort, gSTR_LEDConfig[LED_ch].u8_LEDPin);
         
      /* make sure DIO function was successful */
      if(ERROR_OK != DIO_ErrorState)
      {
         LED_ErrorState = ERROR_NOK;
      }
      else
      {
         LED_ErrorState = ERROR_OK;
      }    
   }
   
   return LED_ErrorState;
}

/**
* @brief: This function returns a led state.
*
* @param [in]  LED_ch   -  LED channel number.
* @param [out] state    -  pointer to where to save the LED state.
*
* @return function error state.
*/
extern ERROR_STATE_t LED_Status(uint8_t LED_ch, uint8_t * state)
{
   ERROR_STATE_t LED_ErrorState;
   
   /* Check valid channel */
   if(LED_INVALID_CH <= LED_ch)
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_INVALID_CH_NO);
   }
   /* check if init function wasn't called before */
   else if(INIT != gu8_IsLEDInit[LED_ch])
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_NOT_INIT);
   }
   else if(PWM_ON == gSTR_LEDConfig[LED_ch].u8_PWM)
   {
      LED_ErrorState = ERROR_NOK;
   }
   else if(NULL_PTR == state)
   {
      LED_ErrorState = (E_LED_MODULE_ID | E_LED_NULL_PTR);
   }
   else
   {
      ERROR_STATE_t DIO_ErrorState;
      
      /* set LED pin to low */
      DIO_ErrorState = DIO_ReadPin(gSTR_LEDConfig[LED_ch].u8_LEDPort, gSTR_LEDConfig[LED_ch].u8_LEDPin, state);
      
      /* make sure DIO function was successful */
      if(ERROR_OK != DIO_ErrorState)
      {
         LED_ErrorState = ERROR_NOK;
      }
      else
      {
         LED_ErrorState = ERROR_OK;
      }
   }
   
   return LED_ErrorState;
}