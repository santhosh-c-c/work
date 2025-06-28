#ifndef NUCLEO_GPIO
#include <zephyr/kernel.h>
#define NUCLEO_GPIO

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4 

#define PIN(x) x
#define PIN_1 1

uint8_t gpio_read(uint8_t port , uint8_t pin);
void gpio_set(uint8_t port , uint8_t pin);
void gpio_clear(uint8_t port, uint8_t pin);
void pin_mode_clear(uint8_t port, uint8_t pin);
void pin_outmode_set(uint8_t port, uint8_t pin);
void gpio_mode_set(uint8_t port, uint8_t pin, bool mode);
void clock_enable(uint32_t rst_offset , uint8_t position);
void blinky(uint8_t port , uint8_t pin);
void complement(uint8_t out_port, uint8_t out_pin, uint8_t in_port, uint8_t in_pin);

#endif


