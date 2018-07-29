#include "grbl_hal.h"
#include "nvs_flash.h"
#include "nvs.h"
#include <string.h>

#define STORAGE_NAMESPACE "grbl"
#define STORAGE_BLOB_SIZE 1024		//Size really needed is 1023
#define STORAGE_KEY		"main"

static bool initialized = false;
static nvs_handle store_handle;

static unsigned char storage_data[STORAGE_BLOB_SIZE];

static void hal_eeprom_init() {
	ESP_CHECK(nvs_flash_init());
	ESP_CHECK(nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &store_handle));

	size_t storage_size = STORAGE_BLOB_SIZE;
	esp_err_t err = nvs_get_blob(store_handle, STORAGE_KEY, storage_data, &storage_size);
	if ( err == ESP_ERR_NVS_NOT_FOUND ) {
		memset( storage_data, 0, sizeof(storage_data) );
	}
	else {
		ESP_CHECK(err);
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

	return storage_data[addr];
}

void hal_eeprom_put_char(unsigned int addr, unsigned char new_value) {
	if ( addr >= STORAGE_BLOB_SIZE ) {
		ESP_LOGE( LOG_TAG, "eeprom size %d address greater than %d", addr, STORAGE_BLOB_SIZE );
		return;
	}
	if ( !initialized ) {
		hal_eeprom_init();
	}

	storage_data[addr] = new_value;
}

void hal_eeprom_commit() {
	ESP_CHECK(nvs_set_blob(store_handle, STORAGE_KEY, storage_data, STORAGE_BLOB_SIZE));
	ESP_CHECK(nvs_commit(store_handle));
}