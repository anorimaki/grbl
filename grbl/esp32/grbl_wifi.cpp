#include "grbl_wifi.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include <string>

const int CONNECTED_BIT = BIT0;
const int DISCONNECTED_BIT = BIT1;


Wifi::Wifi( const char* nvsStorageName ) {
	m_wifiEventGroup = xEventGroupCreate();

	tcpip_adapter_init();
	esp_event_loop_init(Wifi::eventHandler, this);

	wifi_init_config_t wifiInitializationConfig = WIFI_INIT_CONFIG_DEFAULT();
	esp_wifi_init(&wifiInitializationConfig);
	esp_wifi_set_storage(WIFI_STORAGE_RAM);
	connectAsAp();
	
	Configuration configuration;
	if ( readConfiguration( nvsStorageName,  configuration ) ) {
		connectAsStation( configuration );
	}
}

bool Wifi::readConfiguration( const char* nvsStorageName, Wifi::Configuration& configuration ) {
	return false;
}

void Wifi::connectAsStation( const Wifi::Configuration& configuration ) {

}

void Wifi::connectAsAp() {
	esp_wifi_set_mode(WIFI_MODE_AP);
    wifi_config_t apConfig = {
          .ap = {
            .ssid = "grbl",
            .channel = 0,
            .authmode = WIFI_AUTH_OPEN,
            .ssid_hidden = 0,
            .max_connection = 1,
            .beacon_interval = 100
          }
        };
    esp_wifi_set_config(WIFI_IF_AP, &apConfig);
    esp_wifi_start();
}

esp_err_t Wifi::eventHandler(void *ctx, system_event_t *event) {
	Wifi* wifi = static_cast<Wifi*>(ctx);

	switch(event->event_id) {
		case SYSTEM_EVENT_STA_GOT_IP:
			xEventGroupClearBits(wifi->m_wifiEventGroup, DISCONNECTED_BIT);
			xEventGroupSetBits(wifi->m_wifiEventGroup, CONNECTED_BIT);
			break;
		default:
			break;
	}
    return ESP_OK;
}