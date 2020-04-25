#include <stm32g4xx_hal.h>

#define HANDLER(thing, action)                                        \
  void thing##_Handler(void);                                         \
  void thing##_Handler(void) { action; }

HANDLER(HardFault, while(1));
HANDLER(MemManage, while(1));
HANDLER(BusFault, while(1));
HANDLER(UsageFault, while(1));

HANDLER(DebugMon, );

HANDLER(SysTick, HAL_IncTick());
