################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/main.c \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/stm32f4xx_hal_msp.c \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/stm32f4xx_it.c \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/syscalls.c \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/vl53l1_platform.c \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/vl53l1_platform_init.c \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/vl53l1_platform_ipp.c \
C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/vl53l1_platform_log.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_it.o \
./Application/User/syscalls.o \
./Application/User/vl53l1_platform.o \
./Application/User/vl53l1_platform_init.o \
./Application/User/vl53l1_platform_ipp.o \
./Application/User/vl53l1_platform_log.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_it.d \
./Application/User/syscalls.d \
./Application/User/vl53l1_platform.d \
./Application/User/vl53l1_platform_init.d \
./Application/User/vl53l1_platform_ipp.d \
./Application/User/vl53l1_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32f4xx_hal_msp.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/stm32f4xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Application/User/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32f4xx_it.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/stm32f4xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Application/User/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/syscalls.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/syscalls.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Application/User/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/vl53l1_platform.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/vl53l1_platform.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Application/User/vl53l1_platform.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/vl53l1_platform_init.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/vl53l1_platform_init.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Application/User/vl53l1_platform_init.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/vl53l1_platform_ipp.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/vl53l1_platform_ipp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Application/User/vl53l1_platform_ipp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/vl53l1_platform_log.o: C:/Users/User/Desktop/VL53L1/en.VL53L1CB_BareDriver/Example/Projects/STM32F401RE-Nucleo/Examples/53L1A2/SimpleRanging/Src/vl53l1_platform_log.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I"../../../../../../../Drivers/CMSIS/Include" -I"../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/vl53l1 -I../../../../../../../Drivers/BSP/53L1A2 -Os -ffunction-sections -Wall -fno-builtin-fputc -fstack-usage -MMD -MP -MF"Application/User/vl53l1_platform_log.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

