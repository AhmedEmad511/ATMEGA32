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
TWO_SS_MUX.lss \

FLASH_IMAGE += \
TWO_SS_MUX.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TWO_SS_MUX.elf secondary-outputs

# Tool invocations
TWO_SS_MUX.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TWO_SS_MUX.map -mmcu=atmega32 -o "TWO_SS_MUX.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TWO_SS_MUX.lss: TWO_SS_MUX.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TWO_SS_MUX.elf  >"TWO_SS_MUX.lss"
	@echo 'Finished building: $@'
	@echo ' '

TWO_SS_MUX.hex: TWO_SS_MUX.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TWO_SS_MUX.elf  "TWO_SS_MUX.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TWO_SS_MUX.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TWO_SS_MUX.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TWO_SS_MUX.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
