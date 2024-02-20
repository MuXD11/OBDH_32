################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccledmng/src/CCLEDMngB.cpp \
../components/ccledmng/src/CCLEDMngS.cpp 

CPP_DEPS += \
./components/ccledmng/src/CCLEDMngB.d \
./components/ccledmng/src/CCLEDMngS.d 

OBJS += \
./components/ccledmng/src/CCLEDMngB.o \
./components/ccledmng/src/CCLEDMngS.o 


# Each subdirectory must supply rules for building sources it contributes
components/ccledmng/src/%.o: ../components/ccledmng/src/%.cpp components/ccledmng/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/examplenexys/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccsystemmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccledmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccdisplaysmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-ccledmng-2f-src

clean-components-2f-ccledmng-2f-src:
	-$(RM) ./components/ccledmng/src/CCLEDMngB.d ./components/ccledmng/src/CCLEDMngB.o ./components/ccledmng/src/CCLEDMngS.d ./components/ccledmng/src/CCLEDMngS.o

.PHONY: clean-components-2f-ccledmng-2f-src

