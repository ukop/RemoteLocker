/**
 * @file    servo.h
 * @author  ukop
 * @date    07.05.2021
 * @brief   Driver for servo Feetech FT90R.
 */

#ifndef _SERVO_SERVO_H
#define _SERVO_SERVO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <config.h>

/**
 * @brief Servo directions
 */
enum servoDir
{
    SERVO_DIR_NEUTRAL,
    SERVO_DIR_RIGHT,
    SERVO_DIR_LEFT
};

/** @brief  Function to configure servo.
 * 
 *  @return void
 */
void servo_init(void);

/** @brief  Function to set servo direction.
 * 
 *  @param  direction servo direction NEUTRAL/RIGHT/LEFT.
 *  @return void
 */
void servo_setDir(enum servoDir direction);

#endif /* _SERVO_SERVO_H */