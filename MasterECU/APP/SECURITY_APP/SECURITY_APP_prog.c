/*
 * SECURITY_APP_prog.c
 *
 *  Created on: Sep 27, 2022
 *      Author: Mohamad Hassan
 */
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/KEYPAD/KEYPAD_int.h"
#include "../../MCAL/EEPROM/EEPROM_int.h"
#include"SECURITY_APP_int.h"
#include<util/delay.h>
u8 Global_u8Iterator = 0;
u8 SECURITY_u8ArrPassword[4] =
{ 0 };
void SECURITY_APP_vidStartCheck(void)
{
	u8 Local_u8PswrdTries = 0;
	//===================start checking=========================
	if (SECURITY_u8CheckForSetPassword() == NO_PASSSWORD_SET)
	{
		// its first time : ask user to set new password
		LCD_enuSendString("First Time :)");
		_delay_ms(1000);
		SECURITY_vidSetNewPassword();
		//recall function
		SECURITY_APP_vidStartCheck();
	}
	else
	{
		// Password is set already
		// first check for violation
		if (SECURITY_u8CheckForViolation() == VOLATED)
		{
			LCD_Clear_Display();
			LCD_enuSendString("Can't open");
			LCD_enuChangePosition(1, 0);
			LCD_enuSendString("Call maintenance");

			while (1)
				;
		}
		else
		{
			// not violated before
			// fetch password from EEPROM
			LCD_enuSendString("Enter Your");
			LCD_enuChangePosition(1, 0);
			LCD_enuSendString("Password :");
			do
			{
				GetPassword(~PSWRD_INDICATOR_1ST_TIME);
				Local_u8PswrdTries++;
				// check for password
				if (SECURITY_vidCheckEnterdPassword() == CORRECT_PASSWORD)
				{
					// password correct
					//===============correct password===============
					LCD_Clear_Display();
					LCD_enuSendString("    Welcome");
					_delay_ms(500);
					break;
				}
				else
				{
					// password not correct
					if (Local_u8PswrdTries < 3)
					{
						// not exceeded number of tries
						LCD_Clear_Display();
						LCD_enuSendString("Try again");
						LCD_enuChangePosition(1, 0);
						LCD_enuSendString(": ");
					}
					else
					{
						// if exceeded number of tries
						LCD_Clear_Display();
						LCD_enuSendString("Can't open");
						LCD_enuChangePosition(1, 0);
						LCD_enuSendString("CallingEmergancy");
						// mark on eeprom for violation
						SECURITY_vidMarkViolated();
						// and call emergancy
						CallEmergancy();
						// then close program and never open
						while (1)
							;
					}
				}
			} while (1);
			//=======================================================================================================================================================================================
		}
	}
}
void GetPassword(u8 Local_u8Indicator)
{

	u8 Local_u8_PressedKey = 0;
	for (Global_u8Iterator = 0; Global_u8Iterator < 4; Global_u8Iterator++)
	{
		do
		{
			KEYPAD_vidGetPressedKey(&Local_u8_PressedKey);
		} while (Local_u8_PressedKey == 0);

		if (Local_u8_PressedKey != 0)
		{
			SECURITY_u8ArrPassword[Global_u8Iterator] = Local_u8_PressedKey;

			if (Local_u8Indicator == PSWRD_INDICATOR_1ST_TIME)
			{
				LCD_enuSendCharacter(Local_u8_PressedKey);
			}
			else
			{
				LCD_enuSendCharacter('*');
			}
		}
	}
}
u8 SECURITY_u8CheckForSetPassword(void)
{
	return EEPROM_enuReadByte(STATUS_AD);
}
void SECURITY_vidSetNewPassword(void)
{
	do
	{
		LCD_Clear_Display();
		LCD_enuSendString("Set 4 Digits");
		LCD_enuChangePosition(1, 0);
		LCD_enuSendString("Password :");
		GetPassword(PSWRD_INDICATOR_1ST_TIME);
		LCD_Clear_Display();
		LCD_enuSendString("Your Password is");
		LCD_enuChangePosition(1, 0);
		_delay_ms(50);
		for (Global_u8Iterator = 0; Global_u8Iterator < 4; Global_u8Iterator++)
		{
			LCD_enuSendCharacter(SECURITY_u8ArrPassword[Global_u8Iterator]);
		}
		_delay_ms(1000);
		LCD_Clear_Display();
		LCD_enuSendString("Are you sure ?");
		_delay_ms(1000);
		LCD_Clear_Display();
		LCD_enuSendString("1: Yes");
		LCD_enuChangePosition(1, 0);
		LCD_enuSendString("2: No ");
		if (GetChioce() == '1')
		{
			LCD_Clear_Display();
			LCD_enuSendString("OK");
			_delay_ms(500);
			SECURITY_vidWritePassword();
			LCD_Clear_Display();
			break;
		}
		LCD_Clear_Display();

	} while (1);
}
void SECURITY_vidWritePassword(void)
{
	EEPROM_enuWriteByte(STATUS_AD, 0);
	for (Global_u8Iterator = 0; Global_u8Iterator < 4; Global_u8Iterator++)
	{
		EEPROM_enuWriteByte(PASS_AD + Global_u8Iterator, SECURITY_u8ArrPassword[Global_u8Iterator]);
	}
}
u8 SECURITY_vidCheckEnterdPassword(void)
{
	u8 Local_u8WrongFlag = 0;
	for (Global_u8Iterator = 0; Global_u8Iterator < 4; Global_u8Iterator++)
	{

		if (SECURITY_u8ArrPassword[Global_u8Iterator] != EEPROM_enuReadByte(PASS_AD + Global_u8Iterator))
		{
			Local_u8WrongFlag++;
		}
	}
	return Local_u8WrongFlag;
}
u8 SECURITY_u8CheckForViolation(void)
{
	return EEPROM_enuReadByte(LockStatus_AD);
}
void CallEmergancy(void)
{
	DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_HIGH);
}
void SECURITY_vidMarkViolated(void)
{
	EEPROM_enuWriteByte(LockStatus_AD, 0);
}
