################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Event.cpp \
../src/EventContinue.cpp \
../src/EventError.cpp \
../src/EventExit.cpp \
../src/EventGenerator.cpp \
../src/EventMoveLeft.cpp \
../src/EventMoveRight.cpp \
../src/EventNoop.cpp \
../src/EventPause.cpp \
../src/EventQueue.cpp \
../src/EventRestart.cpp \
../src/Keyboard.cpp \
../src/MotorController.cpp \
../src/State.cpp \
../src/StateError.cpp \
../src/StateFinished.cpp \
../src/StateMachine.cpp \
../src/StatePaused.cpp \
../src/StateRunning.cpp \
../src/StateStart.cpp \
../src/main.cpp \
../src/mutex.cpp \
../src/thread.cpp 

OBJS += \
./src/Event.o \
./src/EventContinue.o \
./src/EventError.o \
./src/EventExit.o \
./src/EventGenerator.o \
./src/EventMoveLeft.o \
./src/EventMoveRight.o \
./src/EventNoop.o \
./src/EventPause.o \
./src/EventQueue.o \
./src/EventRestart.o \
./src/Keyboard.o \
./src/MotorController.o \
./src/State.o \
./src/StateError.o \
./src/StateFinished.o \
./src/StateMachine.o \
./src/StatePaused.o \
./src/StateRunning.o \
./src/StateStart.o \
./src/main.o \
./src/mutex.o \
./src/thread.o 

CPP_DEPS += \
./src/Event.d \
./src/EventContinue.d \
./src/EventError.d \
./src/EventExit.d \
./src/EventGenerator.d \
./src/EventMoveLeft.d \
./src/EventMoveRight.d \
./src/EventNoop.d \
./src/EventPause.d \
./src/EventQueue.d \
./src/EventRestart.d \
./src/Keyboard.d \
./src/MotorController.d \
./src/State.d \
./src/StateError.d \
./src/StateFinished.d \
./src/StateMachine.d \
./src/StatePaused.d \
./src/StateRunning.d \
./src/StateStart.d \
./src/main.d \
./src/mutex.d \
./src/thread.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


