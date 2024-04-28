################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.cpp \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.cpp \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.cpp \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.cpp \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.cpp \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.cpp \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.cpp \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.cpp \
../swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.cpp 

CPP_DEPS += \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.d \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.d \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.d \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.d \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.d \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.d \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.d \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.d \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.d 

OBJS += \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.o \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.o \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.o \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.o \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.o \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.o \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.o \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.o \
./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.o 


# Each subdirectory must supply rules for building sources it contributes
swpackages/emu_sc_channel_drv_slib_head/src/%.o: ../swpackages/emu_sc_channel_drv_slib_head/src/%.cpp swpackages/emu_sc_channel_drv_slib_head/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/config/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/cchk_fdirmng/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/ccbkgtcexec/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/ccepdmanager/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/cctm_channelctrl/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/icuasw/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDEventList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDRecovAction/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDSensorTMBufferStatus/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTCDescriptor/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTMList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTMMemory/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/datapool_mng_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/icuasw_pus_services_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/sc_channel_drv_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swpackages/emu_sc_channel_drv_slib_head/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-swpackages-2f-emu_sc_channel_drv_slib_head-2f-src

clean-swpackages-2f-emu_sc_channel_drv_slib_head-2f-src:
	-$(RM) ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.o ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.o ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.o ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.o ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.o ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.o ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.o ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.o ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.d ./swpackages/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.o

.PHONY: clean-swpackages-2f-emu_sc_channel_drv_slib_head-2f-src

