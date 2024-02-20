################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.cpp 

CPP_DEPS += \
./edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.d 

OBJS += \
./edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.o 


# Each subdirectory must supply rules for building sources it contributes
edroombp/src/rtemsapi_4_6/rtems_4_6/%.o: ../edroombp/src/rtemsapi_4_6/rtems_4_6/%.cpp edroombp/src/rtemsapi_4_6/rtems_4_6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/examplenexys/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccsystemmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccledmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccdisplaysmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-edroombp-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6

clean-edroombp-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6:
	-$(RM) ./edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.d ./edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.o

.PHONY: clean-edroombp-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6

