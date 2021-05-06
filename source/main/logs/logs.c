/**
 * @file    logs.c
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with management logs sendingvia UART.
 */

#include <logs/logs.h>

#include <stdio.h>

void logs_send(char const* const msg)
{
#if CONFIG_LOG_MSG_ON
    printf(msg);
#endif
}