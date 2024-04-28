################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service1.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service12.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service128.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service17.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service19.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service20.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service21.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service3.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service5.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service6.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service9.cpp \
../swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_services.cpp 

CPP_DEPS += \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service1.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service12.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service128.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service17.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service19.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service20.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service21.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service3.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service5.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service6.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service9.d \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_services.d 

OBJS += \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service1.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service12.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service128.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service17.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service19.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service20.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service21.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service3.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service5.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service6.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service9.o \
./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_services.o 


# Each subdirectory must supply rules for building sources it contributes
swpackages/icuasw_pus_services_slib_head/src/%.o: ../swpackages/icuasw_pus_services_slib_head/src/%.cpp swpackages/icuasw_pus_services_slib_head/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/config/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/cchk_fdirmng/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/ccbkgtcexec/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/ccepdmanager/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/cctm_channelctrl/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/components/icuasw/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/llsw/rtems_osswr/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDEventList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDRecovAction/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDSensorTMBufferStatus/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTCDescriptor/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTMList/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/asw/dataclasses/CDTMMemory/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/datapool_mng_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/icuasw_pus_services_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swinterfaces/sc_channel_drv_iface_v1/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_x_y_rtems_project_2024/swpackages/emu_sc_channel_drv_slib_head/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-swpackages-2f-icuasw_pus_services_slib_head-2f-src

clean-swpackages-2f-icuasw_pus_services_slib_head-2f-src:
	-$(RM) ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service1.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service1.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service12.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service12.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service128.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service128.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service17.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service17.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service19.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service19.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service20.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service20.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service21.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service21.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service3.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service3.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service5.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service5.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service6.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service6.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service9.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_service9.o ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_services.d ./swpackages/icuasw_pus_services_slib_head/src/icuasw_pus_services.o

.PHONY: clean-swpackages-2f-icuasw_pus_services_slib_head-2f-src

