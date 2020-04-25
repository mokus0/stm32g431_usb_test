#include "board.h"
#include "system_clock.h"

#include <stm32g4xx.h>
#include <stm32g4xx_ll_gpio.h>

int main(int argc, char const *argv[]) {
  (void)argc; (void)argv;

  system_clock_init();
  board_init();

  __enable_irq();

  // TODO: blink an LED or something
  while(1) {
    HAL_Delay(250);
    LL_GPIO_TogglePin(BOARD_LED_Port, BOARD_LED_Pin);
  }
}
