################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../leon3_uart_drv/src/leon3_uart_drv.c 

C_DEPS += \
./leon3_uart_drv/src/leon3_uart_drv.d 

OBJS += \
./leon3_uart_drv/src/leon3_uart_drv.o 


# Each subdirectory must supply rules for building sources it contributes
leon3_uart_drv/src/%.o: ../leon3_uart_drv/src/%.c leon3_uart_drv/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	sparc-rtems-gcc -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/nexys_gpio_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroombp/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/edroomsl/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/leon3_uart_drv/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej_nexys_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-leon3_uart_drv-2f-src

clean-leon3_uart_drv-2f-src:
	-$(RM) ./leon3_uart_drv/src/leon3_uart_drv.d ./leon3_uart_drv/src/leon3_uart_drv.o

.PHONY: clean-leon3_uart_drv-2f-src

