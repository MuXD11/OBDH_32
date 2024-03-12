################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../llsw/emu_gss/src/emu_gss.cpp \
../llsw/emu_gss/src/emu_gss_pus_service1.cpp \
../llsw/emu_gss/src/emu_gss_pus_service17.cpp \
../llsw/emu_gss/src/emu_gss_pus_service3.cpp \
../llsw/emu_gss/src/emu_gss_pus_service9.cpp \
../llsw/emu_gss/src/emu_gss_tc_program.cpp \
../llsw/emu_gss/src/emu_gss_tm_handler.cpp 

CPP_DEPS += \
./llsw/emu_gss/src/emu_gss.d \
./llsw/emu_gss/src/emu_gss_pus_service1.d \
./llsw/emu_gss/src/emu_gss_pus_service17.d \
./llsw/emu_gss/src/emu_gss_pus_service3.d \
./llsw/emu_gss/src/emu_gss_pus_service9.d \
./llsw/emu_gss/src/emu_gss_tc_program.d \
./llsw/emu_gss/src/emu_gss_tm_handler.d 

OBJS += \
./llsw/emu_gss/src/emu_gss.o \
./llsw/emu_gss/src/emu_gss_pus_service1.o \
./llsw/emu_gss/src/emu_gss_pus_service17.o \
./llsw/emu_gss/src/emu_gss_pus_service3.o \
./llsw/emu_gss/src/emu_gss_pus_service9.o \
./llsw/emu_gss/src/emu_gss_tc_program.o \
./llsw/emu_gss/src/emu_gss_tm_handler.o 


# Each subdirectory must supply rules for building sources it contributes
llsw/emu_gss/src/%.o: ../llsw/emu_gss/src/%.cpp llsw/emu_gss/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/config/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/emu_hw_timecode_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/crc/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDTMHandler/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/emu_gss/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/ccsds_pus/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/tmtc_dyn_mem/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/serialize/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/components/cchk_fdirmng/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/components/ccepdmanager/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/components/cctm_channelctrl/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/components/icuasw/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/edroom_glue/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/edroomsl/edroomsl/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/edroomsl/edroomsl_types/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/rtems_osswr/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDEventList/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDRecovAction/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDSensorTMBufferStatus/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDTCHandler/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDTMList/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDTMMemory/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/icuasw_pus_services/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/sc_channel_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/emu_sc_channel_drv/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-llsw-2f-emu_gss-2f-src

clean-llsw-2f-emu_gss-2f-src:
	-$(RM) ./llsw/emu_gss/src/emu_gss.d ./llsw/emu_gss/src/emu_gss.o ./llsw/emu_gss/src/emu_gss_pus_service1.d ./llsw/emu_gss/src/emu_gss_pus_service1.o ./llsw/emu_gss/src/emu_gss_pus_service17.d ./llsw/emu_gss/src/emu_gss_pus_service17.o ./llsw/emu_gss/src/emu_gss_pus_service3.d ./llsw/emu_gss/src/emu_gss_pus_service3.o ./llsw/emu_gss/src/emu_gss_pus_service9.d ./llsw/emu_gss/src/emu_gss_pus_service9.o ./llsw/emu_gss/src/emu_gss_tc_program.d ./llsw/emu_gss/src/emu_gss_tc_program.o ./llsw/emu_gss/src/emu_gss_tm_handler.d ./llsw/emu_gss/src/emu_gss_tm_handler.o

.PHONY: clean-llsw-2f-emu_gss-2f-src

