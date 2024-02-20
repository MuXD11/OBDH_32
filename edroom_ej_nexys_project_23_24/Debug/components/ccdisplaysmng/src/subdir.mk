################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccdisplaysmng/src/CCDisplaysMngB.cpp \
../components/ccdisplaysmng/src/CCDisplaysMngS.cpp 

CPP_DEPS += \
./components/ccdisplaysmng/src/CCDisplaysMngB.d \
./components/ccdisplaysmng/src/CCDisplaysMngS.d 

OBJS += \
./components/ccdisplaysmng/src/CCDisplaysMngB.o \
./components/ccdisplaysmng/src/CCDisplaysMngS.o 


# Each subdirectory must supply rules for building sources it contributes
components/ccdisplaysmng/src/%.o: ../components/ccdisplaysmng/src/%.cpp components/ccdisplaysmng/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/examplenexys/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccsystemmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccledmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccdisplaysmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-ccdisplaysmng-2f-src

clean-components-2f-ccdisplaysmng-2f-src:
	-$(RM) ./components/ccdisplaysmng/src/CCDisplaysMngB.d ./components/ccdisplaysmng/src/CCDisplaysMngB.o ./components/ccdisplaysmng/src/CCDisplaysMngS.d ./components/ccdisplaysmng/src/CCDisplaysMngS.o

.PHONY: clean-components-2f-ccdisplaysmng-2f-src

