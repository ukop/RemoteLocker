/**
 * @file    logs.c
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with management logs sendingvia UART.
 */

#ifndef _LOGS_LOGS_H
#define _LOGS_LOGS_H

/** @brief  Function to send logs if logs messages is ON (baudrate: 115200).
 */
void logs_send(char const* const msg);

#endif /* _LOGS_LOGS_H */