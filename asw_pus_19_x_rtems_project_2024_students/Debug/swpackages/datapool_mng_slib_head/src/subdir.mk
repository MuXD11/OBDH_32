################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../swpackages/datapool_mng_slib_head/src/datapool_mng.cpp 

CPP_DEPS += \
./swpackages/datapool_mng_slib_head/src/datapool_mng.d 

OBJS += \
./swpackages/datapool_mng_slib_head/src/datapool_mng.o 


# Each subdirectory must supply rules for building sources it contributes
swpackages/datapool_mng_slib_head/src/%.o: ../swpackages/datapool_mng_slib_head/src/%.cpp swpackages/datapool_mng_slib_head/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/config/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/components/cchk_fdirmng/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/components/ccbkgtcexec/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/components/ccepdmanager/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/components/cctm_channelctrl/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/components/icuasw/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/dataclasses/CDEventList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/dataclasses/CDRecovAction/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/dataclasses/CDSensorTMBufferStatus/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/dataclasses/CDTCDescriptor/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/dataclasses/CDTMList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/dataclasses/CDTMMemory/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/datapool_mng_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/icuasw_pus_services_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/sc_channel_drv_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swpackages/emu_sc_channel_drv_slib_head/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-swpackages-2f-datapool_mng_slib_head-2f-src

clean-swpackages-2f-datapool_mng_slib_head-2f-src:
	-$(RM) ./swpackages/datapool_mng_slib_head/src/datapool_mng.d ./swpackages/datapool_mng_slib_head/src/datapool_mng.o

.PHONY: clean-swpackages-2f-datapool_mng_slib_head-2f-src

