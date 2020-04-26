#include "board.h"

#include <stm32g4xx_ll_bus.h>
#include <stm32g4xx_ll_gpio.h>

void board_init(void) {
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);

  LL_GPIO_ResetOutputPin(BOARD_LED_Port, BOARD_LED_Pin);
  LL_GPIO_SetPinMode(BOARD_LED_Port, BOARD_LED_Pin, LL_GPIO_MODE_OUTPUT);
}
