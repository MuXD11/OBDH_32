################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../actuators_drv/src/actuators.cpp 

CPP_DEPS += \
./actuators_drv/src/actuators.d 

OBJS += \
./actuators_drv/src/actuators.o 


# Each subdirectory must supply rules for building sources it contributes
actuators_drv/src/%.o: ../actuators_drv/src/%.cpp actuators_drv/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/actuators_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/io_ctrl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/leon3_bprint/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/planner_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/random_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/sensors_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/sensors_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/capathplanner/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/capathtracker/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/ccavoidobstacles/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/vehicle/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/vehicle/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/dataclasses/CDLocation/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/dataclasses/CDPath/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/bprint_swr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-actuators_drv-2f-src

clean-actuators_drv-2f-src:
	-$(RM) ./actuators_drv/src/actuators.d ./actuators_drv/src/actuators.o

.PHONY: clean-actuators_drv-2f-src

