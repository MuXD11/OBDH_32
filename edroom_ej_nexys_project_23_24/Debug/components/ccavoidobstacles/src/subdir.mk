################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccavoidobstacles/src/CCAvoidObstaclesB.cpp \
../components/ccavoidobstacles/src/CCAvoidObstaclesS.cpp 

CPP_DEPS += \
./components/ccavoidobstacles/src/CCAvoidObstaclesB.d \
./components/ccavoidobstacles/src/CCAvoidObstaclesS.d 

OBJS += \
./components/ccavoidobstacles/src/CCAvoidObstaclesB.o \
./components/ccavoidobstacles/src/CCAvoidObstaclesS.o 


# Each subdirectory must supply rules for building sources it contributes
components/ccavoidobstacles/src/%.o: ../components/ccavoidobstacles/src/%.cpp components/ccavoidobstacles/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/actuators_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/io_ctrl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/leon3_bprint/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/planner_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/random_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/sensors_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/sensors_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/capathplanner/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/capathtracker/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/ccavoidobstacles/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/vehicle/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/components/vehicle/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/dataclasses/CDLocation/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/dataclasses/CDPath/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_eclipse_project/bprint_swr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-ccavoidobstacles-2f-src

clean-components-2f-ccavoidobstacles-2f-src:
	-$(RM) ./components/ccavoidobstacles/src/CCAvoidObstaclesB.d ./components/ccavoidobstacles/src/CCAvoidObstaclesB.o ./components/ccavoidobstacles/src/CCAvoidObstaclesS.d ./components/ccavoidobstacles/src/CCAvoidObstaclesS.o

.PHONY: clean-components-2f-ccavoidobstacles-2f-src

