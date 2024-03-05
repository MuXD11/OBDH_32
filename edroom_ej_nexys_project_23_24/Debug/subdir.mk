################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../examplenexys_mmesp_project.cpp 

CPP_DEPS += \
./examplenexys_mmesp_project.d 

OBJS += \
./examplenexys_mmesp_project.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/config/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/edroomsl_types/include" -I"/home/atcsol/git/OBDH_32/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./examplenexys_mmesp_project.d ./examplenexys_mmesp_project.o

.PHONY: clean--2e-

