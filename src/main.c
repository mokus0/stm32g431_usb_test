#include "board.h"
#include "sys/clocks.h"
#include "usb/cdc.h"

#include <stm32g4xx.h>
#include <stm32g4xx_ll_gpio.h>

int main(int argc, char const *argv[]) {
  (void)argc; (void)argv;

  HAL_Init();

  system_clock_init();
  board_init();
  usb_cdc_init();

  __enable_irq();

  while(1) {
    usb_cdc_print("Ping\r\n");
    HAL_Delay(250);
    LL_GPIO_TogglePin(BOARD_LED_Port, BOARD_LED_Pin);
  }
}
