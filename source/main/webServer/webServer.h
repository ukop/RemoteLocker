/**
 * @file    webServer.h
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with basic functions to create webServer.
 */

#ifndef _WEBSERVER_WEBSERVER_H
#define _WEBSERVER_WEBSERVER_H

#include <esp_wifi.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include <esp_http_server.h>

#define WEBSERVER_SSID      "ssid"      ///< WiFi SSID.
#define WEBSERVER_PASSWORD  "password"  ///< WiFi password.

/** @brief  Function to initialize web server.
 *
 *  @return esp_err_t
 */
esp_err_t webServer_init(void);

/** @brief  Function to deinitialize web server.
 *
 *  @return esp_err_t
 */
esp_err_t webServer_deinit(void);

#endif /* _WEBSERVER_WEBSERVER_H */