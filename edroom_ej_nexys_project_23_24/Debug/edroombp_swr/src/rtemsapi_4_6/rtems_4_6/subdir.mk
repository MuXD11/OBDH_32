################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.cpp 

CPP_DEPS += \
./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.d 

OBJS += \
./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.o 


# Each subdirectory must supply rules for building sources it contributes
edroombp_swr/src/rtemsapi_4_6/rtems_4_6/%.o: ../edroombp_swr/src/rtemsapi_4_6/rtems_4_6/%.cpp edroombp_swr/src/rtemsapi_4_6/rtems_4_6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccconsumer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccproducer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/example1/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-edroombp_swr-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6

clean-edroombp_swr-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6:
	-$(RM) ./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.d ./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.o

.PHONY: clean-edroombp_swr-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6

