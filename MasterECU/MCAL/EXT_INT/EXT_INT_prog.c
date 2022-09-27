/*
 * EXT_INT_prog.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Mohamad Hassan
 */
#include"EXT_INT_int.h"
#include"EXT_INT_prv.h"
#include"../G_INT/G_INT_int.h"
#include"../../LIB/STD_Types.h"
struct ptr
{
	func_ptr EXT_INT0_FuncPtr;
	func_ptr EXT_INT1_FuncPtr;
	func_ptr EXT_INT2_FuncPtr;
} EXT_INT_ISR;
EXT_INT_tenuErrorStatus EXT_INT_vidEnable(u8 Copy_u8Interrupt, u8 Copy_u8SenseControl)
{
	EXT_INT_tenuErrorStatus Local_tenuErrorStatus = EXT_INT_OK;
	if (/*Copy_u8Interrupt>EXT_INT2 || ( Copy_u8Interrupt==2 && (Copy_u8SenseControl==0||Copy_u8SenseControl==1) )*/0)
	{
		Local_tenuErrorStatus = EXT_INT_NOK;

	}
	else
	{
		G_INT_vidEnable();
		switch (Copy_u8Interrupt)
		{
		case EXT_INT0:

			SET_BIT(EXT_INT_u8_GICR_REG, EXT_INT_u8_GICR_INT0_BIT);
			switch (Copy_u8SenseControl)
			{
			case EXT_INT_u8_LOW_LEVEL:
				CLR_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC00_BIT);
				CLR_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC01_BIT);
				break;

			case EXT_INT_u8_ANY_CHANGE:
				SET_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC00_BIT);
				CLR_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC01_BIT);
				break;

			case EXT_INT_u8_FALLING_EDGE:
				CLR_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC00_BIT);
				SET_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC01_BIT);
				break;

			case EXT_INT_u8_RISING_EDGE:
				SET_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC00_BIT);
				SET_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC01_BIT);
				break;
			}

			break;

		case EXT_INT1:

			SET_BIT(EXT_INT_u8_GICR_REG, EXT_INT_u8_GICR_INT1_BIT);
			switch (Copy_u8SenseControl)
			{
			case EXT_INT_u8_LOW_LEVEL:
				CLR_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC10_BIT);
				CLR_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC11_BIT);
				break;

			case EXT_INT_u8_ANY_CHANGE:
				SET_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC10_BIT);
				CLR_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC11_BIT);
				break;

			case EXT_INT_u8_FALLING_EDGE:
				CLR_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC10_BIT);
				SET_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC11_BIT);

				break;

			case EXT_INT_u8_RISING_EDGE:
				SET_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC10_BIT);
				SET_BIT(EXT_INT_u8_MCUCR_REG, EXT_INT_u8_MCUCR_ISC11_BIT);
				break;
			}

			break;

		case EXT_INT2:

			SET_BIT(EXT_INT_u8_GICR_REG, EXT_INT_u8_GICR_INT2_BIT);
			switch (Copy_u8SenseControl)
			{

			case EXT_INT_u8_FALLING_EDGE:
				CLR_BIT(EXT_INT_u8_MCUCSR_REG, EXT_INT_u8_MCUCSR_ISC2_BIT);
				break;
			case EXT_INT_u8_RISING_EDGE:
				SET_BIT(EXT_INT_u8_MCUCSR_REG, EXT_INT_u8_MCUCSR_ISC2_BIT);
				break;
			}

			break;

		}
	}
	return Local_tenuErrorStatus;
}

EXT_INT_tenuErrorStatus EXT_INT_vidDisable(u8 Copy_u8Interrupt)
{
	EXT_INT_tenuErrorStatus Local_tenuErrorStatus = EXT_INT_OK;
	if (0)
	{
		Local_tenuErrorStatus = EXT_INT_NOK;
	}
	else
	{
		switch (Copy_u8Interrupt)
		{
		case EXT_INT0:
			CLR_BIT(EXT_INT_u8_GICR_REG, EXT_INT_u8_GICR_INT0_BIT);
			break;
		case EXT_INT1:
			CLR_BIT(EXT_INT_u8_GICR_REG, EXT_INT_u8_GICR_INT1_BIT);
			break;
		case EXT_INT2:
			CLR_BIT(EXT_INT_u8_GICR_REG, EXT_INT_u8_GICR_INT2_BIT);
			break;
		}
	}
	return Local_tenuErrorStatus;
}

void EXT_INT_vidRegisterCBF(u8 Copy_u8Interrupt, func_ptr Add_pfunCBF)
{
	EXT_INT_tenuErrorStatus Local_tenuErrorStatus = EXT_INT_OK;
	static func_ptr Local_pfunPtr;
	Local_pfunPtr = Add_pfunCBF;

	if (Add_pfunCBF == NULL)
	{
		Local_tenuErrorStatus = EXT_INT_NOK;
	}
	else
	{
		switch (Copy_u8Interrupt)
		{
		case EXT_INT0:
			EXT_INT_ISR.EXT_INT0_FuncPtr = Add_pfunCBF;
			break;
		case EXT_INT1:
			EXT_INT_ISR.EXT_INT1_FuncPtr = Add_pfunCBF;
			break;
		case EXT_INT2:
			EXT_INT_ISR.EXT_INT2_FuncPtr = Add_pfunCBF;
			break;
		}
	}
}

/*INT0 ISR*/
void __vector_1(void) __attribute((signal,used));
void __vector_1(void)
{
	EXT_INT_ISR.EXT_INT0_FuncPtr();
}
/*INT1 ISR*/
void __vector_2(void) __attribute((signal,used));
void __vector_2(void)
{
	EXT_INT_ISR.EXT_INT1_FuncPtr();
}
/*INT2 ISR*/
void __vector_3(void) __attribute((signal,used));
void __vector_3(void)
{
	EXT_INT_ISR.EXT_INT2_FuncPtr();
}
