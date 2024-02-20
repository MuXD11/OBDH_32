################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroomsl_types_swr/src/edroomsl_types.cpp 

CPP_DEPS += \
./edroomsl_types_swr/src/edroomsl_types.d 

OBJS += \
./edroomsl_types_swr/src/edroomsl_types.o 


# Each subdirectory must supply rules for building sources it contributes
edroomsl_types_swr/src/%.o: ../edroomsl_types_swr/src/%.cpp edroomsl_types_swr/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccconsumer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccproducer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/example1/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-edroomsl_types_swr-2f-src

clean-edroomsl_types_swr-2f-src:
	-$(RM) ./edroomsl_types_swr/src/edroomsl_types.d ./edroomsl_types_swr/src/edroomsl_types.o

.PHONY: clean-edroomsl_types_swr-2f-src

