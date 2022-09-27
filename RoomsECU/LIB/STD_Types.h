/*
 * STD_Types.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Mohamad Hassan
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_



#define NULL  ((void*)0x00) 
 
#define TRUE  1
#define FALSE 0

typedef unsigned char 		u8;
typedef signed char   		s8;
typedef short unsigned int u16;
typedef short signed int   s16; 
typedef long unsigned int  u32;
typedef long signed int    s32;
typedef float 			   f32;
typedef double             f64;
typedef long double        f80;
typedef void (*func_ptr)(void);



#endif /* LIB_STD_TYPES_H_ */
