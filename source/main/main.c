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
    logs_send("Run Remote Locker ...\n");

    led_initStatusLed();
    led_startBlinkingStatusLed(1000);

    webServer_init();
}
