################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/G_INT/G_INT_prog.c 

OBJS += \
./MCAL/G_INT/G_INT_prog.o 

C_DEPS += \
./MCAL/G_INT/G_INT_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/G_INT/%.o: ../MCAL/G_INT/%.c MCAL/G_INT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


