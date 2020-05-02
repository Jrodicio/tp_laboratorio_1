################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/ArrayEmployees.c \
../Sources/GetValues.c \
../Sources/Menu.c \
../Sources/main.c 

OBJS += \
./Sources/ArrayEmployees.o \
./Sources/GetValues.o \
./Sources/Menu.o \
./Sources/main.o 

C_DEPS += \
./Sources/ArrayEmployees.d \
./Sources/GetValues.d \
./Sources/Menu.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


