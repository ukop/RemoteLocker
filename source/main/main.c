/**
 * @file    main.c
 * @author  ukop
 * @date    22.03.2021
 * @brief   Main program file.
 */
#include <stdio.h>
#include "sdkconfig.h"

#include "webServer/webServer.h"
#include "led/led.h"
#include <logs/logs.h>
#include <config.h>


void app_main(void)
{
    LOG_SEND(LOG_INFO, "Run Remote Locker ...\n");

    led_initStatusLed();

    esp_err_t status = webServer_init();

    if (status == ESP_OK)
    {
        vTaskDelay(1000);
        LOG_SEND(LOG_INFO, "Run Web Server ...\n")
    }
}
