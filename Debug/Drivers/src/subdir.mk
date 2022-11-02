################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/ADC.c \
../Drivers/src/LCD.c \
../Drivers/src/gpio.c \
../Drivers/src/keypad.c 

OBJS += \
./Drivers/src/ADC.o \
./Drivers/src/LCD.o \
./Drivers/src/gpio.o \
./Drivers/src/keypad.o 

C_DEPS += \
./Drivers/src/ADC.d \
./Drivers/src/LCD.d \
./Drivers/src/gpio.d \
./Drivers/src/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"C:/Users/Muhammad Al-Barbary/OneDrive/Desktop/Education/Year3/2nd Term/Embedded_Valeo/TasksAndLab/FinalProject_ADC/Eclipse/keypad2/Drivers/include" -I"C:/Users/Muhammad Al-Barbary/OneDrive/Desktop/Education/Year3/2nd Term/Embedded_Valeo/TasksAndLab/FinalProject_ADC/Eclipse/keypad2/inc" -I"C:/Users/Muhammad Al-Barbary/OneDrive/Desktop/Education/Year3/2nd Term/Embedded_Valeo/TasksAndLab/FinalProject_ADC/Eclipse/keypad2/CMSIS/device" -I"C:/Users/Muhammad Al-Barbary/OneDrive/Desktop/Education/Year3/2nd Term/Embedded_Valeo/TasksAndLab/FinalProject_ADC/Eclipse/keypad2/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


