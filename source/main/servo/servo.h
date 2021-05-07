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

/** @brief  Function to configure servo.
 * 
 *  @return void
 */
void servo_init(void);

#endif /* _SERVO_SERVO_H */