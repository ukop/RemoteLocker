/**
 * @file    led.h
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with basic functions to set/clear status led.
 */

#ifndef _LED_LED_H
#define _LED_LED_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <config.h>

#define LED_GPIO    CONFIG_STATUS_LED_GPIO   ///< Led GPIO.

/** @brief  Function to configure status led.
 */
void led_initStatusLed(void);

/** @brief  Function to set/clear led.
 *
 *  @param  state 0 = OFF, 1 = ON.
 *  @return void
 */
void led_setLed(bool state);

#endif /* _LED_LED_H */