/**
 * @file    servo.c
 * @author  ukop
 * @date    07.05.2021
 * @brief   Driver for servo Feetech FT90R.
 */

#include "driver/gpio.h"
#include "sdkconfig.h"
#include <logs/logs.h>

void servo_init(void)
{
    LOG_SEND(LOG_INFO, "Init servo ...\n")
}