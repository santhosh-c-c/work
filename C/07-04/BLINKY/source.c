#include <zephyr/kernel.h>
#include "source.h"

#define GPIO_BASE_ADDRESS 0x40020000
#define GPIO_OFFSET 0x400

#define ODR_OFFSET 0x14
#define IDR_OFFSET 0x10

#define RCC_BASE_ADDRESS 0x40023800

static void moder_set_output(volatile uint32_t * address, uint8_t pin)
{
        *address |= (1 << (pin<<1));
}

static void gpio_mode_set(uint32_t * address, uint8_t pin, bool mode)
{
        moder_set_input(address, pin); // Default is input to clear bits
        if(mode)
        {
                moder_set_output(address, pin); // Output mode
        }
}

static void clock_enable(uint32_t rcc_offset, uint8_t position)
{
        volatile uint32_t * address= (volatile uint32_t*)RCC_BASE_ADDRESS + rcc_offset; // rcc_offset is obtained from enum 
        *address |= (1 << position); // Set the respective position
}

static void led_pin_toggle(uint32_t * address, uint8_t pin)
{
	*address ^= (1 << pin);
}

void blinky(uint8_t output_port, uint8_t output_pin, uint8_t t_on, uint8_t t_off)
{
	volatile uint32_t * address = (uint32_t)GPIO_BASE_ADDRESS + ((uint32_t)GPIO_OFFSET * output_port);
        clock_enable(rcc_ahb1enr, output_port); // Clock enable for output port
	gpio_mode_set(address, output_pin, output_mode); // Output mode
        address = ((uint32_t*)((int)address + ODR_OFFSET));

	for(int i = 0; i<50; i++)	
	{
		led_pin_toggle(address, output_pin);
		k_msleep(t_on);

		led_pin_toggle(address, output_pin);
		k_msleep(t_off);
	}	
}
