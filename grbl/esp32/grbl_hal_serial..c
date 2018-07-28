#include "grbl_hal.h"
#include "driver/uart.h"
#include "freertos/queue.h"
#include "soc/soc.h"

#define RECEVICE_QUEUE_LEN	20

static QueueHandle_t receive_queue;

static void IRAM_ATTR _uart_isr(void *arg) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	if ( UART.int_st.txfifo_empty ) {
		uart_tx_isr(NULL);
		UART.int_clr.txfifo_empty = 1;
	}

	if ( UART.int_st.rxfifo_full ) {
		while( UART.status.rxfifo_cnt ) {
			uint8_t c = UART.fifo.rw_byte;
			xQueueSendFromISR(receive_queue, &c, &xHigherPriorityTaskWoken);
		}
		UART.int_clr.rxfifo_full = 1;
	}

	if (xHigherPriorityTaskWoken) {
        portYIELD_FROM_ISR();
    }
}


uint8_t c;

uint8_t hal_serial_recv() {
	return c;
}

static void receive_task(void *pvParameters) {
	for(;;) {
		xQueueReceive(receive_queue, &c, portMAX_DELAY);
		uart_rx_isr(NULL);
	}
}

static intr_handle_t intr_handle;

void setBaudRate( uint32_t baud_rate) {
    uint32_t clk_div = ((UART_CLK_FREQ<<4)/baud_rate);
   	UART.clk_div.div_int = clk_div>>4 ;
	UART.clk_div.div_frag = clk_div & 0xf;
}

void hal_serial_init() {
	receive_queue = xQueueCreate(RECEVICE_QUEUE_LEN, sizeof(uint8_t));

	xTaskCreate( receive_task, "receive_task", 8192, NULL, 1, NULL );

 	DPORT_SET_PERI_REG_MASK(DPORT_PERIP_CLK_EN_REG, DPORT_UART_CLK_EN);
    DPORT_CLEAR_PERI_REG_MASK(DPORT_PERIP_RST_EN_REG, DPORT_UART_RST);
	setBaudRate(115200);
	UART.conf0.val = 0x800001c;

	UART.conf1.val = 0;
	UART.conf1.rxfifo_full_thrhd = 1;
	UART.conf1.txfifo_empty_thrhd = 0;
	UART.int_ena.val = 0;
    UART.int_ena.rxfifo_full = 1;
 	UART.int_clr.val = 0xffffffff;
	
	esp_intr_alloc(ETS_UART0_INTR_SOURCE, (int)ESP_INTR_FLAG_IRAM, _uart_isr, NULL, &intr_handle);
}
