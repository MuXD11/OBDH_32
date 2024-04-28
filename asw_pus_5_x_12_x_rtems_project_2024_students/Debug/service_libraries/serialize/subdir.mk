################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../service_libraries/serialize/serialize.c 

C_DEPS += \
./service_libraries/serialize/serialize.d 

OBJS += \
./service_libraries/serialize/serialize.o 


# Each subdirectory must supply rules for building sources it contributes
service_libraries/serialize/%.o: ../service_libraries/serialize/%.c service_libraries/serialize/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	sparc-rtems-gcc -std=c99 -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/asw/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/llsw/config/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/llsw/emu_sc_channel_drv/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/llsw/sc_channel_drv/include" -I"/home/opolo70/EDROOM-workspace/asw_pus_1_x_rtems_project_2024/llsw/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-service_libraries-2f-serialize

clean-service_libraries-2f-serialize:
	-$(RM) ./service_libraries/serialize/serialize.d ./service_libraries/serialize/serialize.o

.PHONY: clean-service_libraries-2f-serialize

