#include <usb/cdc.h>

USBD_HandleTypeDef board_usb;

USBD_StatusTypeDef USBD_LL_Init(USBD_HandleTypeDef *pdev) {
  (void)pdev;

  if (HAL_PCD_Init(&board_pcd) != HAL_OK) {
    return USBD_FAIL;
  }

  return USBD_OK;
}
