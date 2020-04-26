#include <usb/cdc.h>

static void pcd_init(PCD_HandleTypeDef* hpcd);
static void pcd_deinit(PCD_HandleTypeDef* hpcd);

PCD_HandleTypeDef board_pcd = {
  .Instance = USB,
  .Init = {
    .dev_endpoints = 8,
    .speed = PCD_SPEED_FULL,
    .phy_itface = PCD_PHY_EMBEDDED,
    .Sof_enable = DISABLE,
    .low_power_enable = DISABLE,
    .lpm_enable = DISABLE,
    .battery_charging_enable = ENABLE,
  },
  .MspInitCallback = pcd_init,
  .MspDeInitCallback = pcd_deinit,
};

static void pcd_init(PCD_HandleTypeDef* hpcd) {

}

static void pcd_deinit(PCD_HandleTypeDef* hpcd) {

}
