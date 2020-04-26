#pragma once

#define USE_FULL_ASSERT 1

#define HAL_MODULE_ENABLED 1
#define HAL_CORTEX_MODULE_ENABLED 1
#define HAL_PCD_MODULE_ENABLED 1
#define USE_HAL_PCD_REGISTER_CALLBACKS 1

#include "stm32_assert.h"

#include <stm32g4xx_hal_cortex.h>
#include <stm32g4xx_hal_def.h>
#include <stm32g4xx_hal_flash.h>
#include <stm32g4xx_hal_rcc.h>
#include <stm32g4xx_hal_pcd.h>

#define TICK_INT_PRIORITY 0
