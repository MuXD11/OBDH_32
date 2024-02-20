################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sensors_drv/src/sensors.cpp 

CPP_DEPS += \
./sensors_drv/src/sensors.d 

OBJS += \
./sensors_drv/src/sensors.o 


# Each subdirectory must supply rules for building sources it contributes
sensors_drv/src/%.o: ../sensors_drv/src/%.cpp sensors_drv/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/actuators_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/io_ctrl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/leon3_bprint/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/planner_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/random_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/sensors_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/sensors_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/capathplanner/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/capathtracker/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/ccavoidobstacles/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/vehicle/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/vehicle/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/dataclasses/CDLocation/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/dataclasses/CDPath/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/bprint_swr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-sensors_drv-2f-src

clean-sensors_drv-2f-src:
	-$(RM) ./sensors_drv/src/sensors.d ./sensors_drv/src/sensors.o

.PHONY: clean-sensors_drv-2f-src

