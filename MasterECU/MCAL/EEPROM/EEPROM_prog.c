/*
 * EEPROM_prog.c
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohamad Hassan
 */
#include"EEPROM_int.h"
#include"EEPROM_prv.h"

EEPROM_tenuErrorStatus EEPROM_enuWriteByte(u16 Local_u16Address, u8 Local_u8Data)
{
	EEPROM_tenuErrorStatus Local_enuErrorStatus = EEPROM_OK;
	if (0)
	{

	}
	else
	{
		while (GET_BIT(EEPROM_u8_EECR_REG, EEPROM_u8_EECR_EEWE_PIN))
			;

		EEPROM_u16_EEAR_REG = Local_u16Address;

		EEPROM_u8_EEDR_REG = Local_u8Data;

		__asm__
		(
				"sbi 0x1c, 2;"
		);
		__asm__
		(
				"sbi 0x1c, 1;"
		);
	}
	return Local_enuErrorStatus;
}
EEPROM_tenuErrorStatus EEPROM_enuWrite2Bytes(u16 Local_u16Address, u16 Local_u16Data)
{

	EEPROM_tenuErrorStatus Local_enuErrorStatus = EEPROM_OK;
	if (0)
	{

	}
	else
	{
		EEPROM_enuWriteByte(Local_u16Address, (u8) (Local_u16Data >> 8));
		EEPROM_enuWriteByte(Local_u16Address + 1, (u8) (Local_u16Data));

	}
	return Local_enuErrorStatus;
}
u16 EEPROM_enuRead2Bytes(u16 Local_u16Address)
{
	u16 Local_u16Data;
	Local_u16Data = ((EEPROM_enuReadByte(Local_u16Address) << 8) + EEPROM_enuReadByte(Local_u16Address + 1));
	return Local_u16Data;
}
u8 EEPROM_enuReadByte(u16 Local_u16Address)
{

	while (GET_BIT(EEPROM_u8_EECR_REG, EEPROM_u8_EECR_EEWE_PIN))
		;

	EEPROM_u16_EEAR_REG = Local_u16Address;

	SET_BIT(EEPROM_u8_EECR_REG, EEPROM_u8_EECR_EERE_PIN);

	return EEPROM_u8_EEDR_REG;

}

