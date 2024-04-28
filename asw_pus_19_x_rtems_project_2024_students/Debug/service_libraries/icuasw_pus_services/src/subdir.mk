################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service1.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service12.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service17.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service19.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service2.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service20.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service3.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service5.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_service9.cpp \
../service_libraries/icuasw_pus_services/src/icuasw_pus_services.cpp 

CPP_DEPS += \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service1.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service12.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service17.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service19.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service2.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service20.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service3.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service5.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service9.d \
./service_libraries/icuasw_pus_services/src/icuasw_pus_services.d 

OBJS += \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service1.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service12.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service17.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service19.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service2.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service20.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service3.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service5.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_service9.o \
./service_libraries/icuasw_pus_services/src/icuasw_pus_services.o 


# Each subdirectory must supply rules for building sources it contributes
service_libraries/icuasw_pus_services/src/%.o: ../service_libraries/icuasw_pus_services/src/%.cpp service_libraries/icuasw_pus_services/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/config/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/emu_hw_timecode_drv/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/crc/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTMHandler/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/emu_gss/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/ccsds_pus/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/tmtc_dyn_mem/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/serialize/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/edroom_glue/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroombp/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroomsl/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/edroomsl/edroomsl_types/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/rtems_osswr/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDEventList/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDEvAction/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTCHandler/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/asw/dataclasses/CDTMList/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/service_libraries/icuasw_pus_services/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/sc_channel_drv/include" -I"/home/atcsol/eclipse-workspace/asw_pus_19_x_rtems_project_2024_students/llsw/emu_sc_channel_drv/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-service_libraries-2f-icuasw_pus_services-2f-src

clean-service_libraries-2f-icuasw_pus_services-2f-src:
	-$(RM) ./service_libraries/icuasw_pus_services/src/icuasw_pus_service1.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service1.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_service12.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service12.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_service17.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service17.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_service19.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service19.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_service2.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service2.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_service20.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service20.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_service3.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service3.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_service5.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service5.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_service9.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_service9.o ./service_libraries/icuasw_pus_services/src/icuasw_pus_services.d ./service_libraries/icuasw_pus_services/src/icuasw_pus_services.o

.PHONY: clean-service_libraries-2f-icuasw_pus_services-2f-src

