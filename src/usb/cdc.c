#include "sys/clocks.h"
#include "usb/cdc.h"

#include <assert.h>
#include <stm32g4xx_hal.h>
#include <usbd_cdc.h>
#include <usbd_core.h>

void usb_cdc_init(void) {
  usb_clk_init();

  assert(USBD_Init(&board_usb, &cdc_descriptors, DEVICE_FS) == USBD_OK);
  // assert(USBD_RegisterClass(&board_usb, USBD_CDC_CLASS) == USBD_OK);
  // assert(USBD_CDC_RegisterInterface(&board_usb, &board_cdc) == USBD_OK);
  // assert(USBD_Start(&board_usb) == USBD_OK);
}

bool usb_cdc_write(char const* str) {
  // TODO
  (void) str;
  return false;
}
