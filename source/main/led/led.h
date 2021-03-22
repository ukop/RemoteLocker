/**
 * @file    led.h
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with basic functions to set/clear status led.
 */

#ifndef _LED_LED_H
#define _LED_LED_H

#define LED_GPIO    CONFIG_STATUS_LED_GPIO   ///< Led GPIO.

/** @brief  Function to configure status led.
 */
void led_initStatusLed(void);

/** @brief  Function to start blinking status led
 *
 *  @param  interval blinking interval in miliseconds.
 *  @return void
 */
void led_startBlinkingStatusLed(int interval);

#endif /* _LED_LED_H */