################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/MENU_APP/MENU_prog.c 

OBJS += \
./APP/MENU_APP/MENU_prog.o 

C_DEPS += \
./APP/MENU_APP/MENU_prog.d 


# Each subdirectory must supply rules for building sources it contributes
APP/MENU_APP/%.o: ../APP/MENU_APP/%.c APP/MENU_APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


