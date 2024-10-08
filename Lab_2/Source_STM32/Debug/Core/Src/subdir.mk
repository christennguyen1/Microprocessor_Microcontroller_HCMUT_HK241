################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lab_2_Ex_1.c \
../Core/Src/Lab_2_Ex_10.c \
../Core/Src/Lab_2_Ex_2.c \
../Core/Src/Lab_2_Ex_3.c \
../Core/Src/Lab_2_Ex_4.c \
../Core/Src/Lab_2_Ex_5-6-7-8.c \
../Core/Src/Lab_2_Ex_9.c \
../Core/Src/button.c \
../Core/Src/constant.c \
../Core/Src/main.c \
../Core/Src/software_timer.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/Lab_2_Ex_1.o \
./Core/Src/Lab_2_Ex_10.o \
./Core/Src/Lab_2_Ex_2.o \
./Core/Src/Lab_2_Ex_3.o \
./Core/Src/Lab_2_Ex_4.o \
./Core/Src/Lab_2_Ex_5-6-7-8.o \
./Core/Src/Lab_2_Ex_9.o \
./Core/Src/button.o \
./Core/Src/constant.o \
./Core/Src/main.o \
./Core/Src/software_timer.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/Lab_2_Ex_1.d \
./Core/Src/Lab_2_Ex_10.d \
./Core/Src/Lab_2_Ex_2.d \
./Core/Src/Lab_2_Ex_3.d \
./Core/Src/Lab_2_Ex_4.d \
./Core/Src/Lab_2_Ex_5-6-7-8.d \
./Core/Src/Lab_2_Ex_9.d \
./Core/Src/button.d \
./Core/Src/constant.d \
./Core/Src/main.d \
./Core/Src/software_timer.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

