MAIN_TARGET = usb.elf
WARNINGS = -Werror=all -Werror=extra -Wfatal-errors

GCC_PREFIX = arm-none-eabi-
CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT_ABI = -mfloat-abi=hard

DEBUG = 1
OPT = -Og

LIBS = -lc -lm -lnosys
LD_SCRIPT = src/stm32g431kbtx_flash.ld
DEFS = -DSTM32G431xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER
SOURCES = \
	src \
	ext/cmsis_device_g4/Source/Templates/gcc/startup_stm32g431xx.s \
	ext/stm32g4xx_hal_driver/Src/stm32g4xx_hal.c \
	ext/cmsis_device_g4/Source/Templates/system_stm32g4xx.c \
	ext/stm32g4xx_hal_driver/Src/stm32g4xx_ll_utils.c \
	ext/stm32g4xx_hal_driver/Src/stm32g4xx_hal_cortex.c \
	ext/stm32g4xx_hal_driver/Src/stm32g4xx_ll_gpio.c
INC_DIRS = \
	include \
	ext/cmsis_device_g4/Include \
	ext/stm32g4xx_hal_driver/Inc \
	ext/cmsis_core/Core/Include

# try to keep the rest of this more-or-less project independent:

BUILD_DIR ?= build

CC = $(GCC_PREFIX)gcc
AS = $(GCC_PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PREFIX)objcopy
SZ = $(GCC_PREFIX)size

SRCS := $(shell find $(SOURCES) -name '*.[cs]')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)
INCLUDES := $(addprefix -I,$(INC_DIRS))
OPT ?=

AS_DEFS ?= $(DEFS)
AS_INC_DIRS ?= 
AS_INCLUDES := $(addprefix -I,$(AS_INC_DIRS)) $(INCLUDES)
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) $(WARNINGS) -fdata-sections -ffunction-sections

C_DEFS ?= $(DEFS)
C_INC_DIRS ?=
C_INCLUDES := $(addprefix -I,$(C_INC_DIRS)) $(INCLUDES)
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) $(WARNINGS) -fdata-sections -ffunction-sections
CFLAGS += -MMD -MP

LIB_DIRS ?= 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LD_SCRIPT) $(LIB_DIRS) $(LIBS) \
	-Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

MKDIR_P ?= mkdir -p

$(BUILD_DIR)/$(MAIN_TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	$(SZ) $@

$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

flash: $(BUILD_DIR)/$(MAIN_TARGET)
	STM32_Programmer.sh -c port=SWD -e all -w $(BUILD_DIR)/$(MAIN_TARGET) -v -rst