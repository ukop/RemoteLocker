/**
 * @file    servo.c
 * @author  ukop
 * @date    07.05.2021
 * @brief   Driver for servo Feetech FT90R.
 */

#include "servo/servo.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include <logs/logs.h>

#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_attr.h"

#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"

#define SERVO_MIN_PULSEWIDTH        900 //Minimum pulse width in microsecond
#define SERVO_NEUTRAL_PULSEWIDTH    1500 //Neutral pulse width in microsecond
#define SERVO_MAX_PULSEWIDTH        2100 //Maximum pulse width in microsecond

#define SERVO_LEFT_PULSEWIDTH       1540
#define SERVO_RIGHT_PULSEWIDTH      1449

static void mcpwm_example_gpio_initialize(void)
{
    LOG_SEND(LOG_INFO, "Set GPIO 18 as PWM0A (Init servo gpio)\n")
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, 18);
}


void servo_setDir(enum servoDir direction)
{
    switch (direction)
    {
        case SERVO_DIR_NEUTRAL:
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, SERVO_NEUTRAL_PULSEWIDTH);
        break;
        case SERVO_DIR_RIGHT:
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, SERVO_RIGHT_PULSEWIDTH);
        break;
        case SERVO_DIR_LEFT:
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, SERVO_LEFT_PULSEWIDTH);
        break;
        default:
            mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, SERVO_NEUTRAL_PULSEWIDTH);
        break;

    }
}

/**
 * @brief Configure MCPWM module
 */
void mcpwm_example_servo_control(void *arg)
{
    LOG_SEND(LOG_INFO, "Configuring Initial Parameters of mcpwm for servo ...\n")
    mcpwm_example_gpio_initialize();

    mcpwm_config_t pwm_config;
    pwm_config.frequency = 50;      //frequency = 50Hz, i.e. for every servo motor time period should be 20ms
    pwm_config.cmpr_a = 0;          //duty cycle of PWMxA = 0
    pwm_config.cmpr_b = 0;          //duty cycle of PWMxb = 0
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);    //Configure PWM0A & PWM0B with above settings
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, SERVO_NEUTRAL_PULSEWIDTH);
    
    while (1) 
    {
        vTaskDelay(10);
    }
}

void servo_init(void)
{
    LOG_SEND(LOG_INFO, "Init servo ...\n")

    xTaskCreate(mcpwm_example_servo_control, "mcpwm_example_servo_control", 4096, NULL, 5, NULL);
}