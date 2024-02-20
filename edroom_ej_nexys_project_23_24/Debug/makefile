################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include nexys_gpio_drv/src/subdir.mk
-include leon3_uart_drv/src/subdir.mk
-include edroomsl_types/src/subdir.mk
-include edroomsl/src/subdir.mk
-include edroombp/src/rtemsapi_4_6/rtems_4_6/leon3/subdir.mk
-include edroombp/src/rtemsapi_4_6/rtems_4_6/subdir.mk
-include edroom_glue/src/subdir.mk
-include components/examplenexys/src/subdir.mk
-include components/ccsystemmng/src/subdir.mk
-include components/ccledmng/src/subdir.mk
-include components/ccdisplaysmng/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := edroom_ej_nexys_project_23_24
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: edroom_ej_nexys_project_23_24

# Tool invocations
edroom_ej_nexys_project_23_24: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	sparc-rtems-g++ -msoft-float -o "edroom_ej_nexys_project_23_24" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) edroom_ej_nexys_project_23_24
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
