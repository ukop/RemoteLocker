/**
 * @file    webServer.c
 * @author  ukop
 * @date    22.03.2021
 * @brief   File with basic functions to create webServer.
 */
#include <esp_wifi.h>
#include <esp_event.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include <esp_http_server.h>
#include <webServer/webServer.h>
#include <logs/logs.h>
#include <led/led.h>

static httpd_handle_t webServer_server;

#define GREEN_COLOR "#00FF00"
#define RED_COLOR   "#FF0000"

//Max len = 512
const char* test = "<!DOCTYPE html><html>\
<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
<link rel=\"icon\" href=\"data:,\">\
<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\
.button { background-color: %s; border: none; color: white; padding: 16px 40px;</style></head>\
<body><h1>Remote Locker</h1>\
<p><a href=\"/%s\"><button class=\"button\">%s</button></a></p>\
</body></html>\
";

esp_err_t action_handler(httpd_req_t *req)
{
    char*  buf;
    size_t buf_len;
    char state[8];

    buf_len = httpd_req_get_hdr_value_len(req, "Host") + 1;
    if (buf_len > 1)
    {
        buf = malloc(buf_len);
        httpd_req_get_hdr_value_str(req, "Host", buf, buf_len);
        LOG_SEND(LOG_INFO, "Host = %s", buf);
        free(buf);
    }

    buf_len = httpd_req_get_url_query_len(req) + 1;
    if (buf_len > 1)
    {
        buf = malloc(buf_len);
        if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK)
        {
            httpd_query_key_value(buf, "state", state, sizeof(state));
            LOG_SEND(LOG_INFO, "state = %s", state);
        }
        free(buf);
    }
    
    char* response;
    size_t response_len = 512;
    response =  malloc(response_len);

    if (strcmp(state, "open") == 0)
    {
        sprintf(response, test, GREEN_COLOR, "?state=close", "OPENED");
        led_setLed(1);
    }
    else if (strcmp(state, "close") == 0)
    {
        sprintf(response, test, RED_COLOR, "?state=open", "CLOSED");
        led_setLed(0);
    }
    else
    {
        sprintf(response, test, RED_COLOR, "?state=close", "NO DEFINED");
    }

    httpd_resp_send(req, response, strlen(response));

    free(response);

    return ESP_OK;
}

httpd_uri_t mainUri = {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = action_handler,
    .user_ctx  = "Hello Remote Locker!"
};

httpd_handle_t start_webserver(void)
{
    httpd_handle_t ret = NULL;
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    if (httpd_start(&server, &config) == ESP_OK) 
    {
        httpd_register_uri_handler(server, &mainUri);
        ret = server;
    }
    return ret;
}

static esp_err_t wifiEventHandler(httpd_handle_t *server, system_event_t *event)
{
    esp_err_t error = ESP_OK;

    switch (event->event_id)
    {
        case SYSTEM_EVENT_STA_START:
             error |= esp_wifi_connect();
            break;

        case SYSTEM_EVENT_STA_GOT_IP:

            if (*server == NULL)
            {
                *server = start_webserver();
            }
            break;

        case SYSTEM_EVENT_STA_DISCONNECTED:

            error |= esp_wifi_connect();

            if (*server) {
                error |= httpd_stop(server);
                *server = NULL;
            }
            break;
        default:
            break;
    }
    return error;
}

static esp_err_t initialise_wifi(httpd_handle_t *serverHandle)
{
    esp_err_t error = ESP_OK;
    wifi_init_config_t wifiInitDefaultConfig = WIFI_INIT_CONFIG_DEFAULT();
    wifi_config_t wifiConfig = 
    {
        .sta = 
        {
            .ssid =  WEBSERVER_SSID,
            .password = WEBSERVER_PASSWORD,
        },
    };

    tcpip_adapter_init();
    
    error |= esp_event_loop_init(wifiEventHandler, serverHandle);
    error |= esp_wifi_init(&wifiInitDefaultConfig);
    error |= esp_wifi_set_storage(WIFI_STORAGE_RAM);
    error |= esp_wifi_set_mode(WIFI_MODE_STA);
    error |= esp_wifi_set_config(ESP_IF_WIFI_STA, &wifiConfig);
    error |= esp_wifi_start();

    return error;
}

esp_err_t webServer_init(void)
{
    esp_err_t error = nvs_flash_init();
    if (error == ESP_OK)
    {
        error |= initialise_wifi(&webServer_server);
    }

    return error;
}

esp_err_t webServer_deinit(void)
{
    esp_err_t error = ESP_OK;

    // TODO

    return error;
}
