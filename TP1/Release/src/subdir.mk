################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/get_numbers.c \
../src/main.c \
../src/maths.c \
../src/navigation.c 

OBJS += \
./src/get_numbers.o \
./src/main.o \
./src/maths.o \
./src/navigation.o 

C_DEPS += \
./src/get_numbers.d \
./src/main.d \
./src/maths.d \
./src/navigation.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


