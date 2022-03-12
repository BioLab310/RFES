################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Basic.cpp \
../Main.cpp \
../RFES_Base.cpp \
../RFES_FullyDynamic.cpp \
../RFES_Improve.cpp \
../counter.cpp \
../exact_counter.cpp \
../gen_FullyDynamic_graph.cpp \
../hash.cpp \
../neighbor.cpp \
../reservoir.cpp 

OBJS += \
./Basic.o \
./Main.o \
./RFES_Base.o \
./RFES_FullyDynamic.o \
./RFES_Improve.o \
./counter.o \
./exact_counter.o \
./gen_FullyDynamic_graph.o \
./hash.o \
./neighbor.o \
./reservoir.o 

CPP_DEPS += \
./Basic.d \
./Main.d \
./RFES_Base.d \
./RFES_FullyDynamic.d \
./RFES_Improve.d \
./counter.d \
./exact_counter.d \
./gen_FullyDynamic_graph.d \
./hash.d \
./neighbor.d \
./reservoir.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


