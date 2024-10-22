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
-include COTS/2-HAL/EEPROM/subdir.mk
-include COTS/1-MCAL/9-TWI/subdir.mk
-include COTS/1-MCAL/8-SPI/subdir.mk
-include COTS/1-MCAL/7-USART/subdir.mk
-include COTS/1-MCAL/6-PORT/subdir.mk
-include COTS/1-MCAL/5-TIMER/subdir.mk
-include COTS/1-MCAL/4-ADC/subdir.mk
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
TWI_EEPROM.lss \

FLASH_IMAGE += \
TWI_EEPROM.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TWI_EEPROM.elf secondary-outputs

# Tool invocations
TWI_EEPROM.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TWI_EEPROM.map -mmcu=atmega32 -o "TWI_EEPROM.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TWI_EEPROM.lss: TWI_EEPROM.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TWI_EEPROM.elf  >"TWI_EEPROM.lss"
	@echo 'Finished building: $@'
	@echo ' '

TWI_EEPROM.hex: TWI_EEPROM.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TWI_EEPROM.elf  "TWI_EEPROM.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TWI_EEPROM.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TWI_EEPROM.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TWI_EEPROM.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
