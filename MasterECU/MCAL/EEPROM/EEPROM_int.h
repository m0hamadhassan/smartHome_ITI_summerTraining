/*
 * EEPROM_int.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_EEPROM_EEPROM_INT_H_
#define MCAL_EEPROM_EEPROM_INT_H_
#include"../../LIB/BIT_Utils.h"
#include"../../LIB/STD_Types.h"
#include<avr/io.h>
typedef enum
{
	EEPROM_OK, EEPROM_NOK
} EEPROM_tenuErrorStatus;

EEPROM_tenuErrorStatus EEPROM_enuWriteByte(u16 Local_u16Address, u8 Local_u8Data);
EEPROM_tenuErrorStatus EEPROM_enuWrite2Bytes(u16 Local_u16Address, u16 Local_u16Data);
u16 EEPROM_enuRead2Bytes(u16 Local_u16Address);
u8 EEPROM_enuReadByte(u16 Local_u16Address);
#endif /* MCAL_EEPROM_EEPROM_INT_H_ */
