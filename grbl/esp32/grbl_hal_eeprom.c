#include "grbl_hal.h"
#include "nvs_flash.h"
#include "nvs.h"

#define STORAGE_NAMESPACE "grbl"
#define STORAGE_BLOB_SIZE 1024		//Size really needed is 1023
#define STORAGE_KEY		"main"

static bool initialized = false;
static nvs_handle store_handle;

static unsigned char data[STORAGE_BLOB_SIZE];

static void hal_eeprom_init() {
	ESP_CHECK( nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &store_handle) );

	size_t storage_size = STORAGE_BLOB_SIZE;
	esp_err_t err = nvs_get_blob(store_handle, STORAGE_KEY, data, &storage_size);
	if ( err != ESP_ERR_NVS_NOT_FOUND ) {
		ESP_CHECK(err);
		return;
	}
	initialized = true;
}

unsigned char hal_eeprom_get_char(unsigned int addr) {
	if ( addr >= STORAGE_BLOB_SIZE ) {
		ESP_LOGE( LOG_TAG, "eeprom size %d address greater than %d", addr, STORAGE_BLOB_SIZE );
		return -1;
	}
	if ( !initialized ) {
		hal_eeprom_init();
	}

	return data[addr];
}

void hal_eeprom_put_char(unsigned int addr, unsigned char new_value) {
	if ( addr >= STORAGE_BLOB_SIZE ) {
		ESP_LOGE( LOG_TAG, "eeprom size %d address greater than %d", addr, STORAGE_BLOB_SIZE );
		return;
	}
	if ( !initialized ) {
		hal_eeprom_init();
	}

	data[addr] = new_value;
}

void hal_eeprom_commit() {
	ESP_CHECK(nvs_set_blob(store_handle, STORAGE_KEY, data, STORAGE_BLOB_SIZE));
	ESP_CHECK(nvs_commit(store_handle));
}