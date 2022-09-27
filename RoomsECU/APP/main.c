/*
 * main.c
 *
 *  Created on: Aug 22, 2022
 *      Author: Mohamad Hassan
 */
//=====================================================[RoomsUnit]=============================================
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include <util/delay.h>

void main()
{
	u8 Local_u8SPI_Messege;
	u8 Local_u8SPI_PREVIOUSMessege;
	u8 Local_u8PinValue;
	u8 Local_u8PinValue1;
	u8 Local_u8PinValue2;
	u16 Local_u16ADCReadValue;
	u8 Local_u8ExitFlag = 0;	//for oven and coffee timers
	DIO_vidInit();
	ADC_vidInit();
	SPI_vidInit(SPI_Slave);

	// super loop
	while (TRUE)
	{
		//===========================================================================================================
		// check sensor for bathroom lights
		DIO_enuGetPinValue(DIO_u8_PORTC, DIO_u8_PIN5, &Local_u8PinValue);
		if (Local_u8PinValue == 0)
		{
			DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN4, DIO_u8_HIGH);
		}
		else
		{
			_delay_ms(1000);
			DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN4, DIO_u8_LOW);
		}
		//===========================================================================================================
		// check LDR for entrance lights control
		ADC_enuReadValuePolling(&Local_u16ADCReadValue);
		if (Local_u16ADCReadValue > 200)
		{
			DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_LOW);
		}
		//===========================================================================================================
		// Recieve instruction from master
		SPI_enuTranscieveAsynch(&Local_u8SPI_Messege);
		// CHECK FOR NEW INSTRUCTIONS
		if (SPI_u8RecievedValue() != Local_u8SPI_PREVIOUSMessege)
		{
			// CHECK FOR COMING INSTRUCTION AND EXCUTE IT
			switch (SPI_u8RecievedValue())
			{
			//==================KITCHEN=========================
			//===============WaitForOven======================
			case 55:
				while (Local_u8ExitFlag == 0)
				{
					DIO_enuGetPinValue(DIO_u8_PORTD, DIO_u8_PIN1, &Local_u8PinValue1);
					if (Local_u8PinValue1 == 0)
					{
						Local_u8SPI_Messege = 36;
						SPI_enuTranscieveAsynch(&Local_u8SPI_Messege);
						Local_u8ExitFlag++;
					}
				}
				Local_u8ExitFlag = 0;
				break;
				//=================================DOORS=========================================
				//=============Open DOOR=================
				//=========ROOM 1 DOOR===============
			case 40:
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN7, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN7, DIO_u8_LOW);
				break;
				//=========ROOM 2 DOOR===============
			case 1:
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN3, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN3, DIO_u8_LOW);
				break;
				//=========ROOM 3 DOOR===============
			case 2:
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN4, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN4, DIO_u8_LOW);
				break;

				//=============CLOSE DOOR=================
				//=========ROOM 1 DOOR===============
			case 3:
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN5, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN5, DIO_u8_LOW);
				break;
				//=========ROOM 2 DOOR===============
			case 4:
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN6, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN6, DIO_u8_LOW);
				break;
				//=========ROOM 3 DOOR===============
			case 5:
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN7, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN7, DIO_u8_LOW);
				break;
				//=================================ROOMS=========================================
				//=========Room 1===============
				// lights on
			case 6:
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN0, DIO_u8_HIGH);
				break;
				// lights off
			case 7:
				DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN0, DIO_u8_LOW);
				break;
				// conditioner on
			case 8:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_HIGH);
				break;
				// conditioner off
			case 9:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_LOW);
				break;
				// tv on
			case 12:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_HIGH);
				break;
				// tv off
			case 13:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_LOW);
				break;
				// wondow on
			case 14:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_LOW);
				break;
				// wondow off
			case 15:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_LOW);
				break;

				//=========Room 2===============
				// lights on
			case 16:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN5, DIO_u8_HIGH);
				break;
				// lights off
			case 17:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN5, DIO_u8_LOW);
				break;
				// conditioner on
			case 18:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN6, DIO_u8_HIGH);
				break;
				// conditioner off
			case 19:
				DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN6, DIO_u8_LOW);
				break;
				// tv on
			case 22:
				DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_HIGH);
				break;
				// tv off
			case 23:
				DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_LOW);
				break;
				// wondow on
			case 24:
				DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
				break;
				// wondow off
			case 25:
				DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW);
				break;

				//=========Room 3===============
				// lights on
			case 26:
				DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_HIGH);
				break;
				// lights off
			case 27:
				DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_LOW);
				break;
				// conditioner on
			case 28:
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_HIGH);
				break;
				// conditioner off
			case 29:
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);
				break;
				// tv on
			case 32:
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_HIGH);
				break;
				// tv off
			case 33:
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_LOW);
				break;
				// wondow on
			case 34:
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_LOW);
				break;
				// wondow off
			case 35:
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN3, DIO_u8_HIGH);
				_delay_ms(1500);
				DIO_enuSetPinValue(DIO_u8_PORTC, DIO_u8_PIN3, DIO_u8_LOW);
				break;
			}

			Local_u8SPI_PREVIOUSMessege = SPI_u8RecievedValue();
		}
	}
}
