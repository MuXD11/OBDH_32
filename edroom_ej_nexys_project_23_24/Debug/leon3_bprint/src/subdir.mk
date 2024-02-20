################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../leon3_bprint/src/leon3_bprint.c \
../leon3_bprint/src/leon3_uart.c 

C_DEPS += \
./leon3_bprint/src/leon3_bprint.d \
./leon3_bprint/src/leon3_uart.d 

OBJS += \
./leon3_bprint/src/leon3_bprint.o \
./leon3_bprint/src/leon3_uart.o 


# Each subdirectory must supply rules for building sources it contributes
leon3_bprint/src/%.o: ../leon3_bprint/src/%.c leon3_bprint/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	sparc-rtems-gcc -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/bprint_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/edroom_glue/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/edroombp_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/edroomsl_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/edroomsl_types_swr/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/leon3_bprint/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/components/ccconsumer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/components/ccproducer/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/components/example1/include" -I"/home/opolo70/EDROOM-workspace/edroom_ej1_project_23_24/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-leon3_bprint-2f-src

clean-leon3_bprint-2f-src:
	-$(RM) ./leon3_bprint/src/leon3_bprint.d ./leon3_bprint/src/leon3_bprint.o ./leon3_bprint/src/leon3_uart.d ./leon3_bprint/src/leon3_uart.o

.PHONY: clean-leon3_bprint-2f-src

