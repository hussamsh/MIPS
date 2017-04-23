################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AND_OR.cpp \
../src/FA.cpp \
../src/Gate.cpp \
../src/HA.cpp 

OBJS += \
./src/AND_OR.o \
./src/FA.o \
./src/Gate.o \
./src/HA.o 

CPP_DEPS += \
./src/AND_OR.d \
./src/FA.d \
./src/Gate.d \
./src/HA.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


