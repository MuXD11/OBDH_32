################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroomsl_swr/src/edroomsl.cpp \
../edroomsl_swr/src/edroomtc.cpp 

CPP_DEPS += \
./edroomsl_swr/src/edroomsl.d \
./edroomsl_swr/src/edroomtc.d 

OBJS += \
./edroomsl_swr/src/edroomsl.o \
./edroomsl_swr/src/edroomtc.o 


# Each subdirectory must supply rules for building sources it contributes
edroomsl_swr/src/%.o: ../edroomsl_swr/src/%.cpp edroomsl_swr/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccconsumer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccproducer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/example1/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-edroomsl_swr-2f-src

clean-edroomsl_swr-2f-src:
	-$(RM) ./edroomsl_swr/src/edroomsl.d ./edroomsl_swr/src/edroomsl.o ./edroomsl_swr/src/edroomtc.d ./edroomsl_swr/src/edroomtc.o

.PHONY: clean-edroomsl_swr-2f-src

