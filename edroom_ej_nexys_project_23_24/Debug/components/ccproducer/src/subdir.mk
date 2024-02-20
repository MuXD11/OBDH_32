################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccproducer/src/CCProducerB.cpp \
../components/ccproducer/src/CCProducerS.cpp 

CPP_DEPS += \
./components/ccproducer/src/CCProducerB.d \
./components/ccproducer/src/CCProducerS.d 

OBJS += \
./components/ccproducer/src/CCProducerB.o \
./components/ccproducer/src/CCProducerS.o 


# Each subdirectory must supply rules for building sources it contributes
components/ccproducer/src/%.o: ../components/ccproducer/src/%.cpp components/ccproducer/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccconsumer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccproducer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/example1/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-ccproducer-2f-src

clean-components-2f-ccproducer-2f-src:
	-$(RM) ./components/ccproducer/src/CCProducerB.d ./components/ccproducer/src/CCProducerB.o ./components/ccproducer/src/CCProducerS.d ./components/ccproducer/src/CCProducerS.o

.PHONY: clean-components-2f-ccproducer-2f-src

