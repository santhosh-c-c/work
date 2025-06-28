#include "uart.h"

K_THREAD_STACK_DEFINE(tx_stack, UART_STACK_SIZE);
K_THREAD_STACK_DEFINE(rx_stack, UART_STACK_SIZE);

struct k_thread tx_thread_data;
struct k_thread rx_thread_data;

static uint32_t baud()
{
	return (((float)1/BAUD_RATE)*(1000000));	
}

static void data_frame(uint8_t port, uint8_t pin, uint16_t data)
{
	for(uint8_t i=0; i<10; i++)
	{
		if(data & (1<<i))
			gpio_set(port, pin);
		else
			gpio_clear(port, pin);
		k_busy_wait(baud());
	}	
}

static void uart_tx_thread(void * uart_tx_args, void *, void *)
{
	uint8_t port = ((struct uart_args *)uart_tx_args) -> port;
	uint8_t pin =  ((struct uart_args *)uart_tx_args) -> pin;
	uint8_t * data = ((struct uart_args *)uart_tx_args) -> data;
	union frame tx;
	while(*data)
	{
		tx.bits.start = 0;
		tx.bits.stop = 1;
		tx.bits.data = *data;
		data_frame(port, pin, tx.data_frame);
		data++;
	}
}

static void uart_rx_thread(void * uart_rx_args, void *, void *)
{
	uint8_t port = ((struct uart_args *)uart_rx_args) -> port;
	uint8_t pin = ((struct uart_args *)uart_rx_args) -> pin;
	union frame rx;
	uint8_t i=0;
	while(1)
	{
		rx.data_frame = 0;
		while(gpio_read(port, pin));
		k_busy_wait(1);
		for(i=0; i<10; i++)
		{
			rx.data_frame |= (gpio_read(port,pin) << i);
			k_busy_wait(baud());
		}
		if(rx.bits.start == 0 && rx.bits.stop == 1)
		{
			printf("%c", (rx.bits.data));
		}
	}
}

void uart_setup(uint8_t port,uint8_t pin, uint8_t mode)
{
	clock_enable(RST_GPIO_OFFSET, port);
	gpio_mode_set(port, pin, mode);
}

void uart_initiate(uint8_t port, uint8_t uart_tx_pin, uint8_t uart_rx_pin, uint8_t * data)
{
 	struct uart_args * uart_tx_args = malloc(sizeof(struct uart_args));
	struct uart_args * uart_rx_args = malloc(sizeof(struct uart_args));

        uart_tx_args -> port = port;
        uart_tx_args -> pin = uart_tx_pin;
        uart_tx_args -> data = data;

        uart_rx_args -> port = port;
        uart_rx_args -> pin = uart_rx_pin;

        k_thread_create(&tx_thread_data, tx_stack, UART_STACK_SIZE, uart_tx_thread, uart_tx_args, NULL, NULL, UART_PRIORITY_LOW, 0, K_NO_WAIT);
	k_msleep(100);
	k_thread_create(&rx_thread_data, rx_stack, UART_STACK_SIZE, uart_rx_thread, uart_rx_args, NULL, NULL, UART_PRIORITY_LOW, 0, K_NO_WAIT);

        free(uart_tx_args);
        free(uart_rx_args);
}

/*
void uart_tx(uint8_t port, uint8_t pin, uint8_t * data)
{
	struct uart_args * uart_tx_args = malloc(sizeof(struct uart_args));
	uart_tx_args -> port = port;
	uart_tx_args -> pin = pin;
	uart_tx_args -> data = data;
	k_thread_create(&tx_thread_data, tx_stack, UART_STACK_SIZE, uart_tx_thread, uart_tx_args, NULL, NULL, UART_PRIORITY_LOW, 0, K_NO_WAIT);
	free(uart_tx_args);
}

void uart_rx(uint8_t port, uint8_t pin)
{
	struct uart_args * uart_rx_args = malloc(sizeof(struct uart_args));
	uart_rx_args -> port = port;
	uart_rx_args -> pin = pin;
	k_thread_create(&rx_thread_data, rx_stack, UART_STACK_SIZE, uart_rx_thread, uart_rx_args, NULL, NULL, UART_PRIORITY_LOW, 0, K_NO_WAIT);
	free(uart_rx_args);
}
*/
