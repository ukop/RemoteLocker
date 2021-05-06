/**
 * @file    led.c
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with basic functions to set/clear status led.
 */

#include <led/led.h>

#include "driver/gpio.h"
#include "sdkconfig.h"
#include <logs/logs.h>

static bool led_initialized = FALSE;

void led_initStatusLed(void)
{
    if (!led_initialized)
    {
        gpio_pad_select_gpio(LED_GPIO);

        /* Set the GPIO as a push/pull output */
        gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

        led_initialized = TRUE;
    }
    else
    {
        LOG_SEND(LOG_ERROR, "Led initialized yet.");
    }
}

void led_setLed(bool state)
{
    if (led_initialized)
    {
        gpio_set_level(LED_GPIO, state);
        LOG_SEND(LOG_INFO, "Set led to %d", state);
    }
    else
    {
        LOG_SEND(LOG_ERROR, "Led not initialized. Failed set led to %d", state);
    }
}