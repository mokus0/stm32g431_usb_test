#pragma once

#include <stdbool.h>
#include <usbd_core.h>

void usb_cdc_init(void);
bool usb_cdc_write(char const* str);

extern USBD_HandleTypeDef board_usb;
extern PCD_HandleTypeDef board_pcd;
extern USBD_DescriptorsTypeDef cdc_descriptors;
