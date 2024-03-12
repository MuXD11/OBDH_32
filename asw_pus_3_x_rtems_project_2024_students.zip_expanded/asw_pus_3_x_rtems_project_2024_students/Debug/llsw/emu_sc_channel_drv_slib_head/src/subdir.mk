################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.cpp \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.cpp \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.cpp \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.cpp \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.cpp \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.cpp \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.cpp \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.cpp \
../llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.cpp 

CPP_DEPS += \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.d \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.d \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.d \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.d \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.d \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.d \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.d \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.d \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.d 

OBJS += \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.o \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.o \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.o \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.o \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.o \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.o \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.o \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.o \
./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.o 


# Each subdirectory must supply rules for building sources it contributes
llsw/emu_sc_channel_drv_slib_head/src/%.o: ../llsw/emu_sc_channel_drv_slib_head/src/%.cpp llsw/emu_sc_channel_drv_slib_head/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/config/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/cchk_fdirmng/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/ccbkgtcexec/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/ccepdmanager/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/cctm_channelctrl/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/icuasw/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/service_libraries/edroomsl/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/service_libraries/edroomsl/edroomsl_types/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDEventList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDRecovAction/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDSensorTMBufferStatus/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTCDescriptor/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTMList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTMMemory/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/service_libraries/icuasw_pus_services/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/emu_sc_channel_drv_slib_head/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-llsw-2f-emu_sc_channel_drv_slib_head-2f-src

clean-llsw-2f-emu_sc_channel_drv_slib_head-2f-src:
	-$(RM) ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_channel_drv.o ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service12.o ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service17.o ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service19.o ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service20.o ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service3.o ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service5.o ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service6.o ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.d ./llsw/emu_sc_channel_drv_slib_head/src/emu_sc_pus_service9.o

.PHONY: clean-llsw-2f-emu_sc_channel_drv_slib_head-2f-src

