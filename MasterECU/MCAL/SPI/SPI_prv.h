/*
 * SPI_prv.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPI_u8_SPCR_REG  *((volatile u8*) 0x2D)
#define SPI_u8_SPSR_REG  *((volatile u8*) 0x2E)
#define SPI_u8_SPDR_REG  *((volatile u8*) 0x2F)

#define SPI_u8_SPCR_SPIE_PIN 	7
#define SPI_u8_SPCR_SPE_PIN 	6
#define SPI_u8_SPCR_DORTD_PIN 	5
#define SPI_u8_SPCR_MSTR_PIN 	4
#define SPI_u8_SPCR_CPOL_PIN 	3
#define SPI_u8_SPCR_CPHA_PIN 	2
#define SPI_u8_SPCR_SPR1_PIN 	1
#define SPI_u8_SPCR_SPR0_PIN 	0

#define SPI_u8_SPSR_SPI2X_PIN 0
#define SPI_u8_SPSR_WCOL_PIN  6
#define SPI_u8_SPSR_SPIF_PIN  7

#endif /* MCAL_SPI_SPI_PRV_H_ */
