################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../COTS/5-RTOS\ Stack/2-Timer0/TIMER_program.c 

OBJS += \
./COTS/5-RTOS\ Stack/2-Timer0/TIMER_program.o 

C_DEPS += \
./COTS/5-RTOS\ Stack/2-Timer0/TIMER_program.d 


# Each subdirectory must supply rules for building sources it contributes
COTS/5-RTOS\ Stack/2-Timer0/TIMER_program.o: ../COTS/5-RTOS\ Stack/2-Timer0/TIMER_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"COTS/5-RTOS Stack/2-Timer0/TIMER_program.d" -MT"COTS/5-RTOS\ Stack/2-Timer0/TIMER_program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


