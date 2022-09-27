/*
 * MENU_prog.c
 *
 *  Created on: Sep 27, 2022
 *      Author: moham
 */
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/KEYPAD/KEYPAD_int.h"
#include "../../MCAL/SPI/SPI_int.h"
#include "../../MCAL/EXT_INT/EXT_INT_int.h"
#include"MENU_int.h"
#include<util/delay.h>
void FireAlarm(void);
void APP_voidInit(void)
{
	DIO_vidInit();
	LCD_vidInit();
	KEYPAD_vidInit();
	SPI_vidInit(SPI_Master);
	EXT_INT_vidEnable(EXT_INT1, EXT_INT_u8_FALLING_EDGE);
	EXT_INT_vidRegisterCBF(EXT_INT1, FireAlarm);
}
void MENU_vidControlMenu(void)
{
	u8 Local_u8Choice = 0;
	u8 Local_u8SPI_Messege;
	u8 Local_u8RoomOffset;

	while (1)
	{

		LCD_Clear_Display();
		LCD_enuSendString("1: Doors Unit");
		LCD_enuChangePosition(1, 0);
		LCD_enuSendString("2: Rooms Unit  v");
		Local_u8Choice = GetChioce();
		switch (Local_u8Choice)
		{
		case '1':
			do
			{
				LCD_Clear_Display();
				LCD_enuSendString("1: Open Door");
				LCD_enuChangePosition(1, 0);
				LCD_enuSendString("2: Close Door");
				Local_u8Choice = GetChioce();
				switch (Local_u8Choice)
				{
				case '1':
					do
					{
						LCD_Clear_Display();
						LCD_enuSendString("1:Room1 2:Room2");
						LCD_enuChangePosition(1, 0);
						LCD_enuSendString("3:Room3 4:Main");
						Local_u8Choice = GetChioce();
						switch (Local_u8Choice)
						{
						case '1':
							MENU_vidSendInstruction(40, 0);
							LCD_Clear_Display();
							LCD_enuSendString("Room 1 Opened");
							_delay_ms(500);
							Local_u8Choice = '-';
							break;
						case '2':
							MENU_vidSendInstruction(1, 0);

							LCD_Clear_Display();
							LCD_enuSendString("Room 2 Opened");
							_delay_ms(500);
							Local_u8Choice = '-';
							break;
						case '3':
							MENU_vidSendInstruction(2, 0);

							LCD_Clear_Display();
							LCD_enuSendString("Room 3 Opened");
							_delay_ms(500);
							Local_u8Choice = '-';
							break;
						case '4':
							DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN1, DIO_u8_HIGH);
							_delay_ms(1500);
							DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN1, DIO_u8_LOW);
							LCD_Clear_Display();
							LCD_enuSendString("Main Door Opened");
							_delay_ms(500);
							Local_u8Choice = '-';
							break;
						case '/':
							break;
						case '-':
							break;
						}
					} while (Local_u8Choice != '-' && Local_u8Choice != '/');
					Local_u8Choice = 0;
					break;
				case '2':
					do
					{
						LCD_Clear_Display();
						LCD_enuSendString("1:Room1 2:Room2");
						LCD_enuChangePosition(1, 0);
						LCD_enuSendString("3:Room3 4:Main");
						Local_u8Choice = GetChioce();
						switch (Local_u8Choice)
						{
						case '1':
							MENU_vidSendInstruction(3, 0);

							LCD_Clear_Display();
							LCD_enuSendString("Room 1 Closed");
							_delay_ms(500);
							Local_u8Choice = '-';
							break;
						case '2':
							MENU_vidSendInstruction(4, 0);

							LCD_Clear_Display();
							LCD_enuSendString("Room 2 Closed");
							_delay_ms(500);
							Local_u8Choice = '-';
							break;
						case '3':
							MENU_vidSendInstruction(5, 0);

							LCD_Clear_Display();
							LCD_enuSendString("Room 3 Closed");
							_delay_ms(500);
							Local_u8Choice = '-';
							break;
						case '4':

							DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_HIGH);
							_delay_ms(1500);
							DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_LOW);
							LCD_Clear_Display();
							LCD_enuSendString("Main Door Closed");
							_delay_ms(500);

							Local_u8Choice = '-';
							break;
						case '/':
							break;
						case '-':
							break;
						}
					} while (Local_u8Choice != '-' && Local_u8Choice != '/');
					Local_u8Choice = 0;
				case '/':
					break;
				case '-':
					break;
				}
			} while (Local_u8Choice != '-' && Local_u8Choice != '/');
			Local_u8Choice = 0;
			break;
		case '2':
			do
			{
				LCD_Clear_Display();
				LCD_enuSendString("1:Room1 2:Room2");
				LCD_enuChangePosition(1, 0);
				LCD_enuSendString("3:Room3");
				Local_u8Choice = GetChioce();
				switch (Local_u8Choice)
				{
				case '1':
					Local_u8RoomOffset = 0;
					break;
				case '2':
					Local_u8RoomOffset = 10;
					break;
				case '3':
					Local_u8RoomOffset = 20;
					break;
				case '/':
					break;
				case '-':
					break;
				}
				if (Local_u8Choice == '-')
					break;
				do
				{
					LCD_Clear_Display();
					LCD_enuSendString("1: Lights");
					LCD_enuChangePosition(1, 0);
					LCD_enuSendString("2: Conditioner v");
					Local_u8Choice = GetChioce();
					switch (Local_u8Choice)
					{
					case '1':
						do
						{
							LCD_Clear_Display();
							LCD_enuSendString("1: Turn On");
							LCD_enuChangePosition(1, 0);
							LCD_enuSendString("2: Turn Off");
							Local_u8Choice = GetChioce();
							switch (Local_u8Choice)
							{
							case '1':

								MENU_vidSendInstruction(Local_u8RoomOffset + 6, 0);

								LCD_Clear_Display();
								LCD_enuSendString("Light turned On");
								_delay_ms(500);
								Local_u8Choice = '-';
								break;
							case '2':
								MENU_vidSendInstruction(Local_u8RoomOffset + 7, 0);

								LCD_Clear_Display();
								LCD_enuSendString("Light turned Off");
								_delay_ms(500);
								Local_u8Choice = '-';
								break;
							case '/':
								break;
							case '-':
								break;
							}
						} while (Local_u8Choice != '-' && Local_u8Choice != '/');
						Local_u8Choice = 0;
						break;
					case '2':
						do
						{
							LCD_Clear_Display();
							LCD_enuSendString("1: Turn on");
							LCD_enuChangePosition(1, 0);
							LCD_enuSendString("2: Turn Off");
							Local_u8Choice = GetChioce();
							switch (Local_u8Choice)
							{
							case '1':
								MENU_vidSendInstruction(Local_u8RoomOffset + 8, 0);

								LCD_Clear_Display();
								LCD_enuSendString("Cond. Turned On");
								_delay_ms(500);

								Local_u8Choice = '-';
								break;
							case '2':
								MENU_vidSendInstruction(Local_u8RoomOffset + 9, 0);

								LCD_Clear_Display();
								LCD_enuSendString("Cond. Turned Off");
								_delay_ms(500);

								Local_u8Choice = '-';
								break;

							case '/':
								break;
							case '-':
								break;
							}
						} while (Local_u8Choice != '-' && Local_u8Choice != '/');
						Local_u8Choice = 0;
						break;
					case '*':
						do
						{
							LCD_Clear_Display();
							LCD_enuSendString("3: TV          ^");
							LCD_enuChangePosition(1, 0);
							LCD_enuSendString("4: Window");
							Local_u8Choice = GetChioce();
							switch (Local_u8Choice)
							{
							case '3':
								do
								{
									LCD_Clear_Display();
									LCD_enuSendString("1: Turn On");
									LCD_enuChangePosition(1, 0);
									LCD_enuSendString("2: Turn Off");
									Local_u8Choice = GetChioce();
									switch (Local_u8Choice)
									{
									case '1':
										MENU_vidSendInstruction(Local_u8RoomOffset + 12, 0);

										LCD_Clear_Display();
										LCD_enuSendString("TV turned On");
										_delay_ms(500);
										Local_u8Choice = '-';
										break;
									case '2':
										MENU_vidSendInstruction(Local_u8RoomOffset + 13, 0);

										LCD_Clear_Display();
										LCD_enuSendString("TV turned Off");
										_delay_ms(500);
										Local_u8Choice = '-';
										break;
									case '/':
										break;
									case '-':
										break;
									}
								} while (Local_u8Choice != '-' && Local_u8Choice != '/');
								Local_u8Choice = 0;
								break;
							case '4':
								do
								{
									LCD_Clear_Display();
									LCD_enuSendString("1: Open");
									LCD_enuChangePosition(1, 0);
									LCD_enuSendString("2: Close");
									Local_u8Choice = GetChioce();
									switch (Local_u8Choice)
									{
									case '1':
										MENU_vidSendInstruction(Local_u8RoomOffset + 14, 0);

										LCD_Clear_Display();
										LCD_enuSendString("Window Opened");
										_delay_ms(500);
										Local_u8Choice = '-';
										break;
									case '2':
										MENU_vidSendInstruction(Local_u8RoomOffset + 15, 0);

										LCD_Clear_Display();
										LCD_enuSendString("Window Closed");
										_delay_ms(500);
										Local_u8Choice = '-';
										break;
									case '/':
										break;
									case '-':
										break;
									}
								} while (Local_u8Choice != '-' && Local_u8Choice != '/');
								Local_u8Choice = 0;
								break;
							case '/':
								break;
							case '-':
								break;
							}
						} while (Local_u8Choice != '-' && Local_u8Choice != '/');
						Local_u8Choice = 0;
						break;
					case '/':
						break;
					case '-':
						break;
					}
				} while (Local_u8Choice != '-' && Local_u8Choice != '/');
				Local_u8Choice = 0;
			} while (Local_u8Choice != '-' && Local_u8Choice != '/');
			Local_u8Choice = 0;
			break;
		case '*':
			do
			{
				LCD_Clear_Display();
				LCD_enuSendString("3: Kitchen Unit");
				LCD_enuChangePosition(1, 0);
				LCD_enuSendString("               ^");
				Local_u8Choice = GetChioce();
				switch (Local_u8Choice)
				{
				case '3':
					do
					{
						LCD_Clear_Display();
						LCD_enuSendString("1:WaitFor Oven");
						Local_u8Choice = GetChioce();
						switch (Local_u8Choice)
						{
						case '1':
							LCD_Clear_Display();
							LCD_enuSendString("Waiting. . . ");
							MENU_vidWaitAndRecieve(36, 55);
							LCD_Clear_Display();
							LCD_enuSendString("Oven finished");
							LaunchBuzzer();
							_delay_ms(500);
							Local_u8Choice = '-';
							break;
						case '/':
							break;
						case '-':
							break;
						}
					} while (Local_u8Choice != '-' && Local_u8Choice != '/');
					Local_u8Choice = 0;
					break;
				case '/':
					break;
				case '-':
					break;
				}
			} while (Local_u8Choice != '-' && Local_u8Choice != '/');
			Local_u8Choice = 0;
			break;
		case '/':
			break;
		case '-':
			break;
		}
	}
}
u8 GetChioce(void)
{
	u8 Local_u8_PressedKey = 0;
	do
	{
		KEYPAD_vidGetPressedKey(&Local_u8_PressedKey);
		if (Local_u8_PressedKey != 0)
		{
			return Local_u8_PressedKey;
		}

	} while (1);
}
void LaunchBuzzer(void)
{
	DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN0, DIO_u8_HIGH);
	_delay_ms(1000);
	DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN0, DIO_u8_LOW);
}
void ReleaseBuzzer(void)
{
	DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN0, DIO_u8_HIGH);
}
void MENU_vidSendInstruction(u8 Copy_pu8Instruction, u8 Copy_pu8SlaveSelect)
{
	switch (Copy_pu8SlaveSelect)
	{
	case 0:
		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
		SPI_enuTranscieveAsynch(&Copy_pu8Instruction);
		_delay_ms(250);
		DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_HIGH);
		break;
	}
}
void MENU_vidWaitAndRecieve(u8 Copy_u8ValueToWaitFor, u8 Copy_u8ValueToSend)
{
	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
	while (1)
	{
		SPI_enuTranscieveAsynch(&Copy_u8ValueToSend);
		_delay_ms(250);
		if (SPI_u8RecievedValue() == Copy_u8ValueToWaitFor)
			break;
	}
	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_HIGH);
}
void FireAlarm(void)
{
	CallEmergancy();
	ReleaseBuzzer();
	LCD_Clear_Display();
	LCD_enuSendString("Fire Alarm");
	_delay_ms(1000);

}
