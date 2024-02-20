################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/examplenexys/src/ExampleNexysB.cpp \
../components/examplenexys/src/ExampleNexysS.cpp 

CPP_DEPS += \
./components/examplenexys/src/ExampleNexysB.d \
./components/examplenexys/src/ExampleNexysS.d 

OBJS += \
./components/examplenexys/src/ExampleNexysB.o \
./components/examplenexys/src/ExampleNexysS.o 


# Each subdirectory must supply rules for building sources it contributes
components/examplenexys/src/%.o: ../components/examplenexys/src/%.cpp components/examplenexys/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/config/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/examplenexys/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccsystemmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccledmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/components/ccdisplaysmng/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl_types/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-components-2f-examplenexys-2f-src

clean-components-2f-examplenexys-2f-src:
	-$(RM) ./components/examplenexys/src/ExampleNexysB.d ./components/examplenexys/src/ExampleNexysB.o ./components/examplenexys/src/ExampleNexysS.d ./components/examplenexys/src/ExampleNexysS.o

.PHONY: clean-components-2f-examplenexys-2f-src

