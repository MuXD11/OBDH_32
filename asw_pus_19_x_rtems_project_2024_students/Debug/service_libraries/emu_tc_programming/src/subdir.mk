################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../service_libraries/emu_tc_programming/src/emu_tc_programming.cpp 

CPP_DEPS += \
./service_libraries/emu_tc_programming/src/emu_tc_programming.d 

OBJS += \
./service_libraries/emu_tc_programming/src/emu_tc_programming.o 


# Each subdirectory must supply rules for building sources it contributes
service_libraries/emu_tc_programming/src/%.o: ../service_libraries/emu_tc_programming/src/%.cpp service_libraries/emu_tc_programming/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/config/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/emu_hw_timecode_drv/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/crc/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTMHandler/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/emu_gss/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/ccsds_pus/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/tmtc_dyn_mem/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/serialize/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/edroom_glue/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroombp/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroomsl/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroomsl_types/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/rtems_osswr/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDEventList/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDEvAction/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTCHandler/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTMList/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/icuasw_pus_services/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/sc_channel_drv/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/emu_sc_channel_drv/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-service_libraries-2f-emu_tc_programming-2f-src

clean-service_libraries-2f-emu_tc_programming-2f-src:
	-$(RM) ./service_libraries/emu_tc_programming/src/emu_tc_programming.d ./service_libraries/emu_tc_programming/src/emu_tc_programming.o

.PHONY: clean-service_libraries-2f-emu_tc_programming-2f-src

