################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../asw/dataclasses/CDSensorTMBufferStatus/src/cdsensortmbufferstatus.cpp 

CPP_DEPS += \
./asw/dataclasses/CDSensorTMBufferStatus/src/cdsensortmbufferstatus.d 

OBJS += \
./asw/dataclasses/CDSensorTMBufferStatus/src/cdsensortmbufferstatus.o 


# Each subdirectory must supply rules for building sources it contributes
asw/dataclasses/CDSensorTMBufferStatus/src/%.o: ../asw/dataclasses/CDSensorTMBufferStatus/src/%.cpp asw/dataclasses/CDSensorTMBufferStatus/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/llsw/config/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/components/cchk_fdirmng/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/components/ccbkgtcexec/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/components/ccepdmanager/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/components/cctm_channelctrl/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/components/icuasw/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/service_libraries/edroomsl/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/service_libraries/edroomsl/edroomsl_types/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/llsw/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/dataclasses/CDEventList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/dataclasses/CDRecovAction/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/dataclasses/CDSensorTMBufferStatus/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/dataclasses/CDTCDescriptor/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/dataclasses/CDTMList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/dataclasses/CDTMMemory/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/service_libraries/icuasw_pus_services/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/llsw/sc_channel_drv/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/llsw/emu_sc_channel_drv/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-asw-2f-dataclasses-2f-CDSensorTMBufferStatus-2f-src

clean-asw-2f-dataclasses-2f-CDSensorTMBufferStatus-2f-src:
	-$(RM) ./asw/dataclasses/CDSensorTMBufferStatus/src/cdsensortmbufferstatus.d ./asw/dataclasses/CDSensorTMBufferStatus/src/cdsensortmbufferstatus.o

.PHONY: clean-asw-2f-dataclasses-2f-CDSensorTMBufferStatus-2f-src

