################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccconsumer/src/CCConsumerB.cpp \
../components/ccconsumer/src/CCConsumerS.cpp 

CPP_DEPS += \
./components/ccconsumer/src/CCConsumerB.d \
./components/ccconsumer/src/CCConsumerS.d 

OBJS += \
./components/ccconsumer/src/CCConsumerB.o \
./components/ccconsumer/src/CCConsumerS.o 


# Each subdirectory must supply rules for building sources it contributes
components/ccconsumer/src/%.o: ../components/ccconsumer/src/%.cpp components/ccconsumer/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccconsumer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccproducer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/example1/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-ccconsumer-2f-src

clean-components-2f-ccconsumer-2f-src:
	-$(RM) ./components/ccconsumer/src/CCConsumerB.d ./components/ccconsumer/src/CCConsumerB.o ./components/ccconsumer/src/CCConsumerS.d ./components/ccconsumer/src/CCConsumerS.o

.PHONY: clean-components-2f-ccconsumer-2f-src

