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
Simple_calc.lss \

FLASH_IMAGE += \
Simple_calc.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Simple_calc.elf secondary-outputs

# Tool invocations
Simple_calc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Simple_calc.map -mmcu=atmega32 -o "Simple_calc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Simple_calc.lss: Simple_calc.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Simple_calc.elf  >"Simple_calc.lss"
	@echo 'Finished building: $@'
	@echo ' '

Simple_calc.hex: Simple_calc.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Simple_calc.elf  "Simple_calc.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Simple_calc.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Simple_calc.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Simple_calc.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
