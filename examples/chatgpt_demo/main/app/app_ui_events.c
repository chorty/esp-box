// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: chat_gpt_new_gui

#include "app_sr.h"

#include "ui.h"
#include "app_ui_ctrl.h"
#include"OpenAI.h"
#include "esp_ota_ops.h"
#include "esp_system.h"
#include "esp_log.h"

static char *TAG = "ui-events";

void EventBtnSetupClick(lv_event_t *e)
{
    // Your code here
    ui_sleep_show_animation();
}

void EventPanelSleepClickCb(lv_event_t *e)
{
    // Your code here
    app_sr_start_once();
    ESP_LOGI(TAG, "sr start once");
}

static void RestartToFactoryPartition(void){
    const esp_partition_t *update_partition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, NULL);
    // Set the boot partition to switch to Project 1 using OTA handle
    ESP_LOGI(TAG, "Switch to partition OTA_1");
    esp_ota_set_boot_partition(update_partition);
    esp_restart();
}

void EventWifiResetConfirmClick(lv_event_t * e)
{
    ESP_LOGI(TAG, "Reboot from WIFI Page to Factory Partition");
    RestartToFactoryPartition();
}

void EventResetConfirm(lv_event_t * e)
{
    ESP_LOGI(TAG, "Reboot from Settings Page to Factory Partition");
    RestartToFactoryPartition();
}