################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../myDrivers/Src/EXTI.c \
../myDrivers/Src/GPIO.c \
../myDrivers/Src/SPI.c 

OBJS += \
./myDrivers/Src/EXTI.o \
./myDrivers/Src/GPIO.o \
./myDrivers/Src/SPI.o 

C_DEPS += \
./myDrivers/Src/EXTI.d \
./myDrivers/Src/GPIO.d \
./myDrivers/Src/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
myDrivers/Src/%.o myDrivers/Src/%.su: ../myDrivers/Src/%.c myDrivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/EmbeddedDrivers/myDevelopment/myDrivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-myDrivers-2f-Src

clean-myDrivers-2f-Src:
	-$(RM) ./myDrivers/Src/EXTI.d ./myDrivers/Src/EXTI.o ./myDrivers/Src/EXTI.su ./myDrivers/Src/GPIO.d ./myDrivers/Src/GPIO.o ./myDrivers/Src/GPIO.su ./myDrivers/Src/SPI.d ./myDrivers/Src/SPI.o ./myDrivers/Src/SPI.su

.PHONY: clean-myDrivers-2f-Src

