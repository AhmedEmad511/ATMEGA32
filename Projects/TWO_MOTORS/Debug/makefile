################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include COTS/2-HAL/SW/subdir.mk
-include COTS/2-HAL/SS/subdir.mk
-include COTS/2-HAL/LED/subdir.mk
-include COTS/2-HAL/LCD/subdir.mk
-include COTS/2-HAL/KeyPad/subdir.mk
-include COTS/1-MCAL/3-GIE/subdir.mk
-include COTS/1-MCAL/2-EXTI/subdir.mk
-include COTS/1-MCAL/1-DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TWO_MOTORS.lss \

FLASH_IMAGE += \
TWO_MOTORS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TWO_MOTORS.elf secondary-outputs

# Tool invocations
TWO_MOTORS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TWO_MOTORS.map -mmcu=atmega32 -o "TWO_MOTORS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TWO_MOTORS.lss: TWO_MOTORS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TWO_MOTORS.elf  >"TWO_MOTORS.lss"
	@echo 'Finished building: $@'
	@echo ' '

TWO_MOTORS.hex: TWO_MOTORS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TWO_MOTORS.elf  "TWO_MOTORS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TWO_MOTORS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TWO_MOTORS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TWO_MOTORS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
