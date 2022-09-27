/*
 * EEPROM_prv.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_EEPROM_EEPROM_PRV_H_
#define MCAL_EEPROM_EEPROM_PRV_H_

#define EEPROM_u16_EEAR_REG 		*((volatile u16*)	0x3E)
#define EEPROM_u8_EEDR_REG 			*((volatile u8*)	0x3D)
#define EEPROM_u8_EECR_REG 			*((volatile u8*)	0x3C)

#define EEPROM_u8_EECR_EERIE_PIN	3
#define EEPROM_u8_EECR_EEMWE_PIN	2
#define EEPROM_u8_EECR_EEWE_PIN 1
#define EEPROM_u8_EECR_EERE_PIN		0

#define EEPROM_u8_SPMCR_SPMEN_PIN 0

#endif /* MCAL_EEPROM_EEPROM_PRV_H_ */

