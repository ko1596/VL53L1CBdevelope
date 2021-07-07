################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Drivers/BSP/53L1A2/53L1A2.c 

OBJS += \
./Drivers/BSP/53L1A2/53L1A2.o 

C_DEPS += \
./Drivers/BSP/53L1A2/53L1A2.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/53L1A2/53L1A2.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Drivers/BSP/53L1A2/53L1A2.c Drivers/BSP/53L1A2/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Drivers/BSP/53L1A2/53L1A2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

