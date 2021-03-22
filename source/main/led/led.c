/**
 * @file    led.c
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with basic functions to set/clear status led.
 */

#include <led/led.h>

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

void led_wait(int interval)
{
    vTaskDelay(interval / portTICK_PERIOD_MS);
}

void led_initStatusLed(void)
{
    gpio_pad_select_gpio(LED_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
}

void led_startBlinkingStatusLed(int interval)
{
    while(1)
    {
        /* Blink off (output low) */
	    printf("Turning off the LED\n");
        gpio_set_level(LED_GPIO, 0);
        led_wait(interval);

        /* Blink on (output high) */
	    printf("Turning on the LED\n");
        gpio_set_level(LED_GPIO, 1);
        led_wait(interval);
    }
}

