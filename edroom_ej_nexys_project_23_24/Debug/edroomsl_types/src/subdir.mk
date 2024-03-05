################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroomsl_types/src/edroomsl_types.cpp 

CPP_DEPS += \
./edroomsl_types/src/edroomsl_types.d 

OBJS += \
./edroomsl_types/src/edroomsl_types.o 


# Each subdirectory must supply rules for building sources it contributes
edroomsl_types/src/%.o: ../edroomsl_types/src/%.cpp edroomsl_types/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/config/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/edroomsl_types/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-edroomsl_types-2f-src

clean-edroomsl_types-2f-src:
	-$(RM) ./edroomsl_types/src/edroomsl_types.d ./edroomsl_types/src/edroomsl_types.o

.PHONY: clean-edroomsl_types-2f-src

