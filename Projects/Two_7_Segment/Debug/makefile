################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Two_7_Segment.lss \

FLASH_IMAGE += \
Two_7_Segment.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Two_7_Segment.elf secondary-outputs

# Tool invocations
Two_7_Segment.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Two_7_Segment.map -mmcu=atmega32 -o "Two_7_Segment.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Two_7_Segment.lss: Two_7_Segment.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Two_7_Segment.elf  >"Two_7_Segment.lss"
	@echo 'Finished building: $@'
	@echo ' '

Two_7_Segment.hex: Two_7_Segment.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Two_7_Segment.elf  "Two_7_Segment.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Two_7_Segment.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Two_7_Segment.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Two_7_Segment.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
