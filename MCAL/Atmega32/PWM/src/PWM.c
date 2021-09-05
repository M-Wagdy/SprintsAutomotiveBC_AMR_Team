/*
 * File Name: PWM.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for PWM peripheral....
 */ 

#include "MC_REGISTERS.h"
#include "PWM.h"

#define PWM0_PORT			PORT_B
#define PWM0_PIN			PIN3

#define PWM1A_PORT			PORT_D
#define PWM1A_PIN			PIN5

#define PWM1B_PORT			PORT_D
#define PWM1B_PIN			PIN4

#define PWM2_PORT			PORT_D
#define PWM2_PIN			PIN7		

extern Str_PWMConfig_t gastr_PWMConfig[PWM_CHANNEL_NUMBERS];

ERROR_STATE_t PWM_Init(uint8_t PwmChannelNumber)
{
	uint8_t u8_ErrorState=ERROR_OK;
	switch(PwmChannelNumber)
	{
		#if OC0
			case PWM_CHANNEL_OC0:
				BIT_WRITE(TCCR0,WGM00,BIT_GET(gastr_PWMConfig[PWM_CHANNEL_OC0].PWMMode,BIT0));
				BIT_WRITE(TCCR0,WGM01,BIT_GET(gastr_PWMConfig[PWM_CHANNEL_OC0].PWMMode,BIT1));
				
				TWO_BITS_WRITE(TCCR0,COM00,gastr_PWMConfig[PWM_CHANNEL_OC0].PWMWaveformMode);
				
				DIO_SetPinDirection(PWM0_PORT,PWM0_PIN,PIN_OUTPUT);
				
				u8_ErrorState=ERROR_OK;
				break;
		#endif
		
		#if OC1A
			case PWM_CHANNEL_OC1A:
				TWO_BITS_WRITE(TCCR1A,WGM10,TWO_BITS_GET(gastr_PWMConfig[PWM_CHANNEL_OC1A].PWMMode,BIT0));
				TWO_BITS_WRITE(TCCR1B,WGM12,TWO_BITS_GET(gastr_PWMConfig[PWM_CHANNEL_OC1A].PWMMode,BIT2));
				
				TWO_BITS_WRITE(TCCR1A,COM1A0,gastr_PWMConfig[PWM_CHANNEL_OC1A].PWMWaveformMode);
				
				DIO_SetPinDirection(PWM1A_PORT,PWM1A_PIN,PIN_OUTPUT);
				
				u8_ErrorState=ERROR_OK;
				break;
		#endif	
		
		#if OC1B
			case PWM_CHANNEL_OC1B:
				TWO_BITS_WRITE(TCCR1A,WGM10,TWO_BITS_GET(gastr_PWMConfig[PWM_CHANNEL_OC1B].PWMMode,BIT0));
				TWO_BITS_WRITE(TCCR1B,WGM12,TWO_BITS_GET(gastr_PWMConfig[PWM_CHANNEL_OC1B].PWMMode,BIT2));	
				
				TWO_BITS_WRITE(TCCR1A,COM1B0,gastr_PWMConfig[PWM_CHANNEL_OC1B].PWMWaveformMode);				
				
				DIO_SetPinDirection(PWM1B_PORT,PWM1B_PIN,PIN_OUTPUT);
				
				u8_ErrorState=ERROR_OK;
				break;
		#endif
		
		#if OC2
			case PWM_CHANNEL_OC2:
				BIT_WRITE(TCCR2,WGM20,BIT_GET(gastr_PWMConfig[PWM_CHANNEL_OC2].PWMMode,BIT0));
				BIT_WRITE(TCCR2,WGM21,BIT_GET(gastr_PWMConfig[PWM_CHANNEL_OC2].PWMMode,BIT1));
				
				TWO_BITS_WRITE(TCCR2,COM20,gastr_PWMConfig[PWM_CHANNEL_OC2].PWMWaveformMode);
				
				DIO_SetPinDirection(PWM2_PORT,PWM2_PIN,PIN_OUTPUT);
				
				u8_ErrorState=ERROR_OK;
				break;
		#endif	
		default:
			u8_ErrorState=ERROR_NOK;
			break;			
	}
	return u8_ErrorState;
}

ERROR_STATE_t PWM_Start(uint8_t PwmChannelNumber)
{
	uint8_t u8_ErrorState=ERROR_OK;
	switch(PwmChannelNumber)
	{
		#if OC0
			case PWM_CHANNEL_OC0:
				THREE_BITS_WRITE(TCCR0,CS00,gastr_PWMConfig[PWM_CHANNEL_OC0].PWMFrequancy);	
				u8_ErrorState=ERROR_OK;	
				break;
		#endif
		
		#if OC1A
			case PWM_CHANNEL_OC1A:
				THREE_BITS_WRITE(TCCR1B,CS10,gastr_PWMConfig[PWM_CHANNEL_OC1A].PWMFrequancy);
				u8_ErrorState=ERROR_OK;	
				break;
		#endif	
		
		#if OC1B
			case PWM_CHANNEL_OC1B:
				THREE_BITS_WRITE(TCCR1B,CS10,gastr_PWMConfig[PWM_CHANNEL_OC1B].PWMFrequancy);
				u8_ErrorState=ERROR_OK;	
				break;
		#endif
		
		#if OC2
			case PWM_CHANNEL_OC2:
				THREE_BITS_WRITE(TCCR2,CS20,gastr_PWMConfig[PWM_CHANNEL_OC2].PWMFrequancy);
				u8_ErrorState=ERROR_OK;				
				break;
		#endif	
		default:
			u8_ErrorState=ERROR_NOK;
			break;			
	}
	return u8_ErrorState;
}

ERROR_STATE_t PWM_Stop(uint8_t PwmChannelNumber )
{
	uint8_t u8_ErrorState=ERROR_OK;
	switch(PwmChannelNumber)
	{
		#if OC0
			case PWM_CHANNEL_OC0:
				THREE_BITS_WRITE(TCCR0,CS00,OC0_NO_CLK);
				u8_ErrorState=ERROR_OK;	
				break;
		#endif

		#if OC1A
			case PWM_CHANNEL_OC1A:
				THREE_BITS_WRITE(TCCR1B,CS10,OC1_NO_CLK);
				u8_ErrorState=ERROR_OK;	
				break;
		#endif

		#if OC1B
			case PWM_CHANNEL_OC1B:
				THREE_BITS_WRITE(TCCR1B,CS10,OC1_NO_CLK);
				u8_ErrorState=ERROR_OK;	
				break;
		#endif

		#if OC2
			case PWM_CHANNEL_OC2:
				THREE_BITS_WRITE(TCCR2,CS20,OC2_NO_CLK);	
				u8_ErrorState=ERROR_OK;	
				break;
		#endif	
		default:
			u8_ErrorState=ERROR_NOK;	
			break;			
	}
	return u8_ErrorState;
}

ERROR_STATE_t PWM_Connect(uint8_t PwmChannelNumber)
{
	uint8_t u8_ErrorState=ERROR_OK;
	switch(PwmChannelNumber)
	{
		#if OC0
			case PWM_CHANNEL_OC0:
				TWO_BITS_WRITE(TCCR0,COM00,gastr_PWMConfig[PWM_CHANNEL_OC0].PWMWaveformMode);
				u8_ErrorState=ERROR_OK;
				break;
		#endif	
		
		#if OC1A
			case PWM_CHANNEL_OC1A:
				TWO_BITS_WRITE(TCCR1A,COM1A0,gastr_PWMConfig[PWM_CHANNEL_OC1A].PWMWaveformMode);
				u8_ErrorState=ERROR_OK;
				break;
		#endif

		#if OC1B
			case PWM_CHANNEL_OC1B:
				TWO_BITS_WRITE(TCCR1A,COM1B0,gastr_PWMConfig[PWM_CHANNEL_OC1B].PWMWaveformMode);
				u8_ErrorState=ERROR_OK;
				break;	
		#endif	
		
		#if OC2
			case PWM_CHANNEL_OC2:
				TWO_BITS_WRITE(TCCR2,COM20,gastr_PWMConfig[PWM_CHANNEL_OC2].PWMWaveformMode);
				u8_ErrorState=ERROR_OK;
				break;
		#endif	
		default:
			u8_ErrorState=ERROR_NOK;
			break;			
	}
	return u8_ErrorState;	
}

ERROR_STATE_t PWM_Disconnect(uint8_t PwmChannelNumber)
{
	uint8_t u8_ErrorState=ERROR_OK;
	switch(PwmChannelNumber)
	{
		#if OC0
			case PWM_CHANNEL_OC0:
				TWO_BITS_WRITE(TCCR0,COM00,DISCONNECT);
				u8_ErrorState=ERROR_OK;
				break;
		#endif	
		
		#if OC1A
			case PWM_CHANNEL_OC1A:
				TWO_BITS_WRITE(TCCR1A,COM1A0,DISCONNECT);
				u8_ErrorState=ERROR_OK;
				break;
		#endif	
		
		#if OC1B
			case PWM_CHANNEL_OC1B:
				TWO_BITS_WRITE(TCCR1A,COM1B0,DISCONNECT);
				u8_ErrorState=ERROR_OK;
				break;	
		#endif	
		
		#if OC2
			case PWM_CHANNEL_OC2:
				TWO_BITS_WRITE(TCCR2,COM20,DISCONNECT);	
				u8_ErrorState=ERROR_OK;
				break;
		#endif	
		default:
			u8_ErrorState=ERROR_NOK;
			break;			
	}
	return u8_ErrorState;
}

ERROR_STATE_t PWM_SetDuty(uint8_t PwmChannelNumber,uint8_t PwmDuty )
{
	uint8_t u8_ErrorState=ERROR_OK;
	if(PwmDuty==0||PwmDuty>100)
	{
		u8_ErrorState=ERROR_NOK;
	}
	else
	{
		switch(PwmChannelNumber)
		{
			#if OC0
				case PWM_CHANNEL_OC0:
					switch(gastr_PWMConfig[PWM_CHANNEL_OC0].PWMWaveformMode)
					{
						case NON_INVERTING:
							OCR0 = (uint8_t)(((PwmDuty/100.0)*256.0)-1);
							u8_ErrorState=ERROR_OK;
							break;
						default:
							u8_ErrorState=ERROR_NOK;
							break;
					}
					break;
			#endif
			
			#if OC1A	
				case PWM_CHANNEL_OC1A:
					switch(gastr_PWMConfig[PWM_CHANNEL_OC1A].PWMWaveformMode)
					{
						case NON_INVERTING:
							if(	(gastr_PWMConfig[PWM_CHANNEL_OC1A].PWMMode==OC1_PHASE_CORRECT_8BITS)||
								(gastr_PWMConfig[PWM_CHANNEL_OC1A].PWMMode==OC1_FAST_PWM_8BITS) )
							{
								OCR1A = (uint16_t)(((PwmDuty/100.0)*256.0)-1);
								u8_ErrorState=ERROR_OK;
							}
							else
							{
								u8_ErrorState=ERROR_NOK;
							}
							break;
						default:
							u8_ErrorState=ERROR_NOK;
							break;
					}
					break;				
			#endif
			
			#if OC1B
				case PWM_CHANNEL_OC1B:
					switch(gastr_PWMConfig[PWM_CHANNEL_OC1B].PWMWaveformMode)
					{
						case NON_INVERTING:
							if(	(gastr_PWMConfig[PWM_CHANNEL_OC1B].PWMMode==OC1_PHASE_CORRECT_8BITS)||
								(gastr_PWMConfig[PWM_CHANNEL_OC1B].PWMMode==OC1_FAST_PWM_8BITS) )
							{
								OCR1B = (uint16_t)(((PwmDuty/100.0)*256.0)-1);
								u8_ErrorState=ERROR_OK;
							}
							else
							{
								u8_ErrorState=ERROR_NOK;
							}							
							break;
						default:
							u8_ErrorState=ERROR_NOK;
							break;
					}
					break;	
			#endif	
			
			#if OC2
				case PWM_CHANNEL_OC2:
					switch(gastr_PWMConfig[PWM_CHANNEL_OC2].PWMWaveformMode)
					{
						case NON_INVERTING:
							OCR2 = (uint8_t)(((PwmDuty/100.0)*256.0)-1);
							u8_ErrorState=ERROR_OK;
							break;
						default:
							u8_ErrorState=ERROR_NOK;
							break;
					}
					break;
			#endif	
			default:
				u8_ErrorState=ERROR_NOK;
				break;			
		}		
	}
	return u8_ErrorState;
}