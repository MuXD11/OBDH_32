################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/example1/src/Example1B.cpp \
../components/example1/src/Example1S.cpp 

CPP_DEPS += \
./components/example1/src/Example1B.d \
./components/example1/src/Example1S.d 

OBJS += \
./components/example1/src/Example1B.o \
./components/example1/src/Example1S.o 


# Each subdirectory must supply rules for building sources it contributes
components/example1/src/%.o: ../components/example1/src/%.cpp components/example1/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccconsumer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccproducer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/example1/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-example1-2f-src

clean-components-2f-example1-2f-src:
	-$(RM) ./components/example1/src/Example1B.d ./components/example1/src/Example1B.o ./components/example1/src/Example1S.d ./components/example1/src/Example1S.o

.PHONY: clean-components-2f-example1-2f-src

