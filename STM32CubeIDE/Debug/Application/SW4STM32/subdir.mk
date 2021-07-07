################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f401xe.s 

OBJS += \
./Application/SW4STM32/startup_stm32f401xe.o 

S_DEPS += \
./Application/SW4STM32/startup_stm32f401xe.d 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32f401xe.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f401xe.s Application/SW4STM32/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Application/SW4STM32/startup_stm32f401xe.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

