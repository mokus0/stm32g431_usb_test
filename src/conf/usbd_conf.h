#pragma once

#include <stm32g4xx_hal.h>
#include <stdlib.h>

#define DEVICE_FS               0
#define USBD_MAX_STR_DESC_SIZ   100

#define USBD_free               free
#define USBD_malloc             malloc
#define USBD_memcpy             memcpy
#define USBD_memset             memset
