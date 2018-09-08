#ifndef GBRL_WIFI_H
#define GBRL_WIFI_H

#include "esp_event.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include <string>

class Wifi {
private:
	struct Configuration {
		std::string ssid;
		std::string password;
	};

public:
	Wifi( const char* nvsStorageName );	
	
private:
	void connectAsAp();
	bool readConfiguration( const char* nvsStorageName, Configuration& configuration );
	void connectAsStation( const Configuration& configuration );
	static esp_err_t eventHandler(void *ctx, system_event_t *event);

private:
	EventGroupHandle_t m_wifiEventGroup;
};

#endif