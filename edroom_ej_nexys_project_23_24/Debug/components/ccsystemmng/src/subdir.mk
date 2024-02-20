################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccsystemmng/src/CCSystemMngB.cpp \
../components/ccsystemmng/src/CCSystemMngS.cpp 

CPP_DEPS += \
./components/ccsystemmng/src/CCSystemMngB.d \
./components/ccsystemmng/src/CCSystemMngS.d 

OBJS += \
./components/ccsystemmng/src/CCSystemMngB.o \
./components/ccsystemmng/src/CCSystemMngS.o 


# Each subdirectory must supply rules for building sources it contributes
components/ccsystemmng/src/%.o: ../components/ccsystemmng/src/%.cpp components/ccsystemmng/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/examplenexys/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccsystemmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccledmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccdisplaysmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-ccsystemmng-2f-src

clean-components-2f-ccsystemmng-2f-src:
	-$(RM) ./components/ccsystemmng/src/CCSystemMngB.d ./components/ccsystemmng/src/CCSystemMngB.o ./components/ccsystemmng/src/CCSystemMngS.d ./components/ccsystemmng/src/CCSystemMngS.o

.PHONY: clean-components-2f-ccsystemmng-2f-src

