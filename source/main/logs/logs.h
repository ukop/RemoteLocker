/**
 * @file    logs.c
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with management logs sendingvia UART.
 */

#include <esp_log.h>
#include <config.h>

#ifndef _LOGS_LOGS_H
#define _LOGS_LOGS_H

#define LOG_SEND(level, format, ... ) { \
    if (CONFIG_LOG_MSG_ON) \
    { \
        switch (level) \
        { \
            case LOG_ERROR: ESP_LOG_LEVEL_LOCAL(ESP_LOG_ERROR, "APP", format, ##__VA_ARGS__); break; \
            case LOG_WARN: ESP_LOG_LEVEL_LOCAL(ESP_LOG_WARN, "APP", format, ##__VA_ARGS__); break; \
            case LOG_INFO: ESP_LOG_LEVEL_LOCAL(ESP_LOG_INFO, "APP", format, ##__VA_ARGS__); break; \
            case LOG_DEBUG: ESP_LOG_LEVEL_LOCAL(ESP_LOG_DEBUG, "APP", format, ##__VA_ARGS__); break; \
            case LOG_VERBOSE: ESP_LOG_LEVEL_LOCAL(ESP_LOG_VERBOSE, "APP", format, ##__VA_ARGS__); break; \
            default: ESP_LOG_LEVEL_LOCAL(ESP_LOG_NONE, "APP", format, ##__VA_ARGS__); break; \
        } \
    } \
}

/**
 * @brief Log levels
 */
enum logLevel
{
    LOG_ERROR,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG,
    LOG_VERBOSE
};

/** @brief  Function to send logs if logs messages is ON (baudrate: 115200).
 */
void logs_send(char const* const msg);

#endif /* _LOGS_LOGS_H */