#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"
static const char* TAG = "BIKE ALARM";

#include "sdkconfig.h"

void SimpeTask(void *pvParam) {

    int a = (int) pvParam;
    ESP_LOGD(TAG, "char: %d", sizeof(char));
    vTaskDelay(pdMS_TO_TICKS(2000));
    ESP_LOGD(TAG, "short: %d", sizeof(short));
    ESP_LOGD(TAG, "int: %d", sizeof(int));
    ESP_LOGD(TAG, "long: %d", sizeof(long));
    ESP_LOGD(TAG, "long long: %d", sizeof(long long));
    ESP_LOGD(TAG, "float: %d", sizeof(float));
    ESP_LOGD(TAG, "double: %d", sizeof(double));
    ESP_LOGD(TAG, "long double: %d", sizeof(long double));

    while (true) {
        ESP_LOGI(TAG, "Log - taks %d.", a);
        vTaskDelay(pdMS_TO_TICKS(2000*a));
    }
    vTaskDelete(NULL);
}

int a,b,c;

void app_main(void) {

    a = 1;
    b = 2;
    c = 3;
    
    xTaskCreate(SimpeTask, "", 2048, (void *) a, 1, NULL);
    xTaskCreate(SimpeTask, "", 2048, (void *) b, 1, NULL);
    xTaskCreate(SimpeTask, "", 2048, (void *) c, 1, NULL);
    
}
