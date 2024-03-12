################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.cpp 

CPP_DEPS += \
./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.d 

OBJS += \
./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.o 


# Each subdirectory must supply rules for building sources it contributes
edroombp_swr/src/rtemsapi_4_6/rtems_4_6/%.o: ../edroombp_swr/src/rtemsapi_4_6/rtems_4_6/%.cpp edroombp_swr/src/rtemsapi_4_6/rtems_4_6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/config/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/cchk_fdirmng/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/ccbkgtcexec/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/ccepdmanager/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/cctm_channelctrl/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/icuasw/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDEventList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDRecovAction/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDSensorTMBufferStatus/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTCDescriptor/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTMList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTMMemory/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/datapool_mng_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/icuasw_pus_services_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/sc_channel_drv_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swpackages/emu_sc_channel_drv_slib_head/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-edroombp_swr-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6

clean-edroombp_swr-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6:
	-$(RM) ./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.d ./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.o

.PHONY: clean-edroombp_swr-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6

