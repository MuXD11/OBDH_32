################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccdisplaymng/src/CCDisplayMngB.cpp \
../components/ccdisplaymng/src/CCDisplayMngS.cpp 

CPP_DEPS += \
./components/ccdisplaymng/src/CCDisplayMngB.d \
./components/ccdisplaymng/src/CCDisplayMngS.d 

OBJS += \
./components/ccdisplaymng/src/CCDisplayMngB.o \
./components/ccdisplaymng/src/CCDisplayMngS.o 


# Each subdirectory must supply rules for building sources it contributes
components/ccdisplaymng/src/%.o: ../components/ccdisplaymng/src/%.cpp components/ccdisplaymng/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/examplenexys/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccsystemmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccledmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccdisplaymng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-ccdisplaymng-2f-src

clean-components-2f-ccdisplaymng-2f-src:
	-$(RM) ./components/ccdisplaymng/src/CCDisplayMngB.d ./components/ccdisplaymng/src/CCDisplayMngB.o ./components/ccdisplaymng/src/CCDisplayMngS.d ./components/ccdisplaymng/src/CCDisplayMngS.o

.PHONY: clean-components-2f-ccdisplaymng-2f-src

