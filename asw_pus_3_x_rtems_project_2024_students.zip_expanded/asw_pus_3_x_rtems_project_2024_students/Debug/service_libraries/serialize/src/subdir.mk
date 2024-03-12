################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../service_libraries/serialize/src/serialize.c 

C_DEPS += \
./service_libraries/serialize/src/serialize.d 

OBJS += \
./service_libraries/serialize/src/serialize.o 


# Each subdirectory must supply rules for building sources it contributes
service_libraries/serialize/src/%.o: ../service_libraries/serialize/src/%.c service_libraries/serialize/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	sparc-rtems-gcc -std=c99 -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/edroom_glue/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/crc/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDTMHandler/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/emu_gss/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/ccsds_pus/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/tmtc_dyn_mem/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/serialize/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/config/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/emu_sc_channel_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/sc_channel_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-service_libraries-2f-serialize-2f-src

clean-service_libraries-2f-serialize-2f-src:
	-$(RM) ./service_libraries/serialize/src/serialize.d ./service_libraries/serialize/src/serialize.o

.PHONY: clean-service_libraries-2f-serialize-2f-src

