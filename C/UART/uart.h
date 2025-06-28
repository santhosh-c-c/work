#ifndef UART
#define UART

#include "gpio.h"
#include <zephyr/kernel.h>
#include <stdlib.h>

#define INMODE 0
#define OUTMODE 1

#define BAUD_RATE 9600 
#define RST_GPIO_OFFSET 0x30

#define UART_STACK_SIZE 500
#define UART_PRIORITY_LOW 5
#define UART_PRIORITY_HIGH 0

/*
void uart_tx(uint8_t, uint8_t, uint8_t *);
void uart_rx(uint8_t, uint8_t);
*/
void uart_setup(uint8_t port, uint8_t pin, uint8_t mode);
void uart_initiate(uint8_t, uint8_t, uint8_t, uint8_t *);

union frame
{
        uint16_t data_frame;
        struct
        {
                uint16_t start: 1;
                uint16_t data : 8;
                uint16_t stop : 1;
        }bits;
};

struct uart_args
{
	uint8_t port;
	uint8_t pin;
	uint8_t * data;
};

#endif
