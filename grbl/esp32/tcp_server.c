#include "grbl_hal.h"
#include "lwip/sockets.h"
#include <errno.h>
#include <string.h>

#define PORT_NUMBER	8001

#define READ_BUFFER_LEN	128
static uint8_t read_buffer[READ_BUFFER_LEN];

static void server_attend_connection( int clientSock ) {
	// Loop reading data.
	while(1) {
		ssize_t sizeRead = recv(clientSock, &read_buffer, sizeof(read_buffer), 0);
		if (sizeRead < 0) {
			ESP_LOGE(LOG_TAG, "recv: %d %s", sizeRead, strerror(errno));
			return;
		}
		if (sizeRead == 0) {
			break;
		}
		uart_rx_isr(NULL);
	}
}

/**
 * Create a listening socket.  We then wait for a client to connect.
 */
void server_start(void *ignore) {
	// Create a socket that we will listen upon.
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock < 0) {
		ESP_LOGE(LOG_TAG, "socket: %d %s", sock, strerror(errno));
		vTaskDelete(NULL);
		return;
	}

	// Bind our server socket to a port.
	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(PORT_NUMBER);
	int rc  = bind(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
	if (rc < 0) {
		ESP_LOGE(LOG_TAG, "bind: %d %s", rc, strerror(errno));
		vTaskDelete(NULL);
		return;
	}

	// Flag the socket as listening for new connections.
	rc = listen(sock, 5);
	if (rc < 0) {
		ESP_LOGE(LOG_TAG, "listen: %d %s", rc, strerror(errno));
		vTaskDelete(NULL);
		return;
	}

	while (1) {
		// Listen for a new client connection.
		struct sockaddr_in clientAddress;
		socklen_t clientAddressLength = sizeof(clientAddress);
		int clientSock = accept(sock, (struct sockaddr *)&clientAddress, &clientAddressLength);
		if (clientSock < 0) {
			ESP_LOGE(LOG_TAG, "accept: %d %s", clientSock, strerror(errno));
		}
		else {
			server_attend_connection(clientSock);
			close(clientSock);
		}
	}
}
