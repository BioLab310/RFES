################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Basic.cpp \
../Main.cpp \
../RFES_Base.cpp \
../RFES_Improve.cpp \
../counter.cpp \
../hash.cpp \
../neighbor.cpp \
../reservoir.cpp 

OBJS += \
./Basic.o \
./Main.o \
./RFES_Base.o \
./RFES_Improve.o \
./counter.o \
./hash.o \
./neighbor.o \
./reservoir.o 

CPP_DEPS += \
./Basic.d \
./Main.d \
./RFES_Base.d \
./RFES_Improve.d \
./counter.d \
./hash.d \
./neighbor.d \
./reservoir.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


