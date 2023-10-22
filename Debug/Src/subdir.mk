################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_program.c \
../Src/GI_program.c \
../Src/MOTOR_program.c \
../Src/SERVO_program.c \
../Src/TIMER0_program.c \
../Src/TIMER1_program.c \
../Src/TIMER2_program.c \
../Src/UART_program.c \
../Src/ULTRASONIC_program.c \
../Src/main.c 

OBJS += \
./Src/DIO_program.o \
./Src/GI_program.o \
./Src/MOTOR_program.o \
./Src/SERVO_program.o \
./Src/TIMER0_program.o \
./Src/TIMER1_program.o \
./Src/TIMER2_program.o \
./Src/UART_program.o \
./Src/ULTRASONIC_program.o \
./Src/main.o 

C_DEPS += \
./Src/DIO_program.d \
./Src/GI_program.d \
./Src/MOTOR_program.d \
./Src/SERVO_program.d \
./Src/TIMER0_program.d \
./Src/TIMER1_program.d \
./Src/TIMER2_program.d \
./Src/UART_program.d \
./Src/ULTRASONIC_program.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


