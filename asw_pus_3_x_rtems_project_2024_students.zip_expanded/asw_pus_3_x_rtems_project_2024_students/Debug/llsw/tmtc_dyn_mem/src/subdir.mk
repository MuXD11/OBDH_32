################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../llsw/tmtc_dyn_mem/src/tmtc_pool.c 

C_DEPS += \
./llsw/tmtc_dyn_mem/src/tmtc_pool.d 

OBJS += \
./llsw/tmtc_dyn_mem/src/tmtc_pool.o 


# Each subdirectory must supply rules for building sources it contributes
llsw/tmtc_dyn_mem/src/%.o: ../llsw/tmtc_dyn_mem/src/%.c llsw/tmtc_dyn_mem/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	sparc-rtems-gcc -std=c99 -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/edroom_glue/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/crc/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/asw/dataclasses/CDTMHandler/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/emu_gss/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/ccsds_pus/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/tmtc_dyn_mem/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/service_libraries/serialize/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/config/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/emu_sc_channel_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/sc_channel_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_3_x_rtems_project_2024_students/llsw/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-llsw-2f-tmtc_dyn_mem-2f-src

clean-llsw-2f-tmtc_dyn_mem-2f-src:
	-$(RM) ./llsw/tmtc_dyn_mem/src/tmtc_pool.d ./llsw/tmtc_dyn_mem/src/tmtc_pool.o

.PHONY: clean-llsw-2f-tmtc_dyn_mem-2f-src

