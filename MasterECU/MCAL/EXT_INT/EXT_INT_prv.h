/*
 * EXT_INT_prv.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Mohamad Hassan
 */
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Utils.h"

#ifndef MCAL_EXT_INT_EXT_INT_PRV_H_
#define MCAL_EXT_INT_EXT_INT_PRV_H_

#define EXT_INT_u8_MCUCR_REG  *((volatile u8*)  0x55 )
#define EXT_INT_u8_MCUCSR_REG *((volatile u8*)  0x54 )
#define EXT_INT_u8_GICR_REG   *((volatile u8*)  0x5B )
#define EXT_INT_u8_GIFR_REG   *((volatile u8*)  0x5A )

#define EXT_INT_u8_MCUCR_ISC00_BIT 	0
#define EXT_INT_u8_MCUCR_ISC01_BIT 	1
#define EXT_INT_u8_MCUCR_ISC10_BIT 	2
#define EXT_INT_u8_MCUCR_ISC11_BIT	3

#define EXT_INT_u8_MCUCSR_ISC2_BIT 	6

#define EXT_INT_u8_GICR_INT0_BIT 	6
#define EXT_INT_u8_GICR_INT1_BIT 	7
#define EXT_INT_u8_GICR_INT2_BIT 	5

#define EXT_INT_u8_GIFR_INTF0_BIT 	6
#define EXT_INT_u8_GIFR_INTF1_BIT  	7
#define EXT_INT_u8_GIFR_INTF2_BIT 	5

#endif /* MCAL_EXT_INT_EXT_INT_PRV_H_ */
