/**
 * @file    webServer.h
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with basic functions to create webServer.
 */

#ifndef _WEBSERVER_WEBSERVER_H
#define _WEBSERVER_WEBSERVER_H

#include <esp_wifi.h>
//#include <esp_event_loop.h>
#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include <esp_http_server.h>

#if 0
#include <systemheader1.h>
#include <systemheader2.h>

#include <box/header1.h>
#include <box/header2.h>

#include "local_header1.h"
#include "local_header2.h"
#endif

#define WEBSERVER_SSID      "ssid"      ///< WiFi SSID.
#define WEBSERVER_PASSWODD  "password"  ///< WiFi password.

/** @brief  Function t o initialize web server.
 *
 *  @return void
 */
void webServer_init(void);

#endif /* _WEBSERVER_WEBSERVER_H */