#include "grbl_hal.h"
#include "tcp_server.h"
#include "grbl_wifi.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include <string.h>
#include <errno.h>


#define PORT_NUMBER 8001

const char *ssid = "pinguin";
const char *password = "anorimakianorimaki";

static EventGroupHandle_t wifi_event_group;
const int CONNECTED_BIT = BIT0;
const int DISCONNECTED_BIT = BIT1;

#define CONNECTION_TIMEOUT_MS 20000


static uint32_t wifi_get_local_ip(void)
{
    int bits = xEventGroupWaitBits(wifi_event_group, CONNECTED_BIT, 0, 1, CONNECTION_TIMEOUT_MS/portTICK_RATE_MS);
    tcpip_adapter_if_t ifx = TCPIP_ADAPTER_IF_AP;
    tcpip_adapter_ip_info_t ip_info;
    wifi_mode_t mode;

    esp_wifi_get_mode(&mode);
    if (WIFI_MODE_STA == mode) {
        bits = xEventGroupWaitBits(wifi_event_group, CONNECTED_BIT, 0, 1, CONNECTION_TIMEOUT_MS/portTICK_RATE_MS);
        if (bits & CONNECTED_BIT) {
            ifx = TCPIP_ADAPTER_IF_STA;
        } else {
            ESP_LOGE(LOG_TAG, "sta has no IP");
            return 0;
        }
     }

     tcpip_adapter_get_ip_info(ifx, &ip_info);
     return ip_info.ip.addr;
}


static esp_err_t event_handler(void *ctx, system_event_t *event)
{
	switch(event->event_id) {
		case SYSTEM_EVENT_STA_GOT_IP:
			xEventGroupClearBits(wifi_event_group, DISCONNECTED_BIT);
			xEventGroupSetBits(wifi_event_group, CONNECTED_BIT);
			break;
		default:
			break;
	}
    return ESP_OK;
}

void wifi_connect() {
	wifi_event_group = xEventGroupCreate();

	nvs_flash_init();
    tcpip_adapter_init();
    ESP_CHECK( esp_event_loop_init(event_handler, NULL) );
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_CHECK( esp_wifi_init(&cfg) );
    ESP_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
    ESP_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    wifi_config_t sta_config;
	sta_config.sta.bssid_set = false;
	strncpy((char*) sta_config.sta.ssid, ssid, sizeof(sta_config.sta.ssid));
	strncpy((char*) sta_config.sta.password, password, sizeof(sta_config.sta.password));
    ESP_CHECK( esp_wifi_set_config(WIFI_IF_STA, &sta_config) );
    ESP_CHECK( esp_wifi_start() );
    ESP_CHECK( esp_wifi_connect() );
}


Wifi wifi("wifi");


void hal_socket_init() {

}