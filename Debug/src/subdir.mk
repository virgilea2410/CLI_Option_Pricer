################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ApplicationPricer.cpp \
../src/Constants.cpp \
../src/Main.cpp \
../src/Option.cpp \
../src/OptionPricer.cpp \
../src/Pricer.cpp \
../src/Stock.cpp \
../src/TestPricing.cpp \
../src/Tools.cpp 

OBJS += \
./src/ApplicationPricer.o \
./src/Constants.o \
./src/Main.o \
./src/Option.o \
./src/OptionPricer.o \
./src/Pricer.o \
./src/Stock.o \
./src/TestPricing.o \
./src/Tools.o 

CPP_DEPS += \
./src/ApplicationPricer.d \
./src/Constants.d \
./src/Main.d \
./src/Option.d \
./src/OptionPricer.d \
./src/Pricer.d \
./src/Stock.d \
./src/TestPricing.d \
./src/Tools.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


