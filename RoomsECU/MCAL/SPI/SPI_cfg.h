/*
 * SPI_cfg.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohamad Hassan
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

/* options:
 * 			SPI_u8_MSB_FIRST
 * 			SPI_u8_LSB_FIRST
 * 
 */
#define SPI_u8_DATA_ORDER SPI_u8_LSB_FIRST
/*
 * options :
 * 			SPI_u8_SAMPLE_RISING_SETUP_FALLING
 * 			SPI_u8_SETUP_RISING_SAMPLE_FALLING
 * 			
 * 			SPI_u8_SAMPLE_FALLING_SETUP_RISING
 * 			SPI_u8_SETUP_FALLING_SAMPLE_RISING
 */
#define SPI_u8_DATA_MODE SPI_u8_SAMPLE_RISING_SETUP_FALLING

/*
 * options :
 * 			SPI_u8_SPI1X_F_4
 * 			SPI_u8_SPI1X_F_16
 * 			SPI_u8_SPI1X_F_64
 * 			SPI_u8_SPI1X_F_128
 * 			SPI_u8_SPI2X_F_2
 * 			SPI_u8_SPI2X_F_8
 * 			SPI_u8_SPI2X_F_32
 * 			SPI_u8_SPI2X_F_64
 */
#define SPI_u8_SCK_FREQUENCY SPI_u8_SPI1X_F_128




#define SPI_u8_MSB_FIRST 0
#define SPI_u8_LSB_FIRST 1


#define SPI_u8_SAMPLE_RISING_SETUP_FALLING 0
#define SPI_u8_SETUP_RISING_SAMPLE_FALLING 1
#define SPI_u8_SAMPLE_FALLING_SETUP_RISING 2
#define SPI_u8_SETUP_FALLING_SAMPLE_RISING 3

#define SPI_u8_SPI1X_F_4 	0
#define SPI_u8_SPI1X_F_16	1
#define SPI_u8_SPI1X_F_64	2
#define SPI_u8_SPI1X_F_128	3
#define SPI_u8_SPI2X_F_2	4
#define SPI_u8_SPI2X_F_8	5
#define SPI_u8_SPI2X_F_32	6
#define SPI_u8_SPI2X_F_64	7
#endif /* MCAL_SPI_SPI_CFG_H_ */
