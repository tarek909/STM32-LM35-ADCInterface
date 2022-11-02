################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include Drivers/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ADC_Project.elf

# Tool invocations
ADC_Project.elf: $(OBJS) $(USER_OBJS) C:\Users\Muhammad\ Al-Barbary\OneDrive\Desktop\Education\Year3\2nd\ Term\Embedded_Valeo\TasksAndLab\FinalProject_ADC\Eclipse\keypad2/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"C:/Users/Muhammad Al-Barbary/OneDrive/Desktop/Education/Year3/2nd Term/Embedded_Valeo/TasksAndLab/FinalProject_ADC/Eclipse/keypad2/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "ADC_Project.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O ihex "ADC_Project.elf" "ADC_Project.hex"
	arm-none-eabi-size "ADC_Project.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
