#include <zephyr/kernel.h>
#include "source.h"

#define GPIO_BASE_ADDRESS 0x40020000
#define GPIO_OFFSET 0x400

#define ODR_OFFSET 0x14
#define IDR_OFFSET 0x10

#define RCC_BASE_ADDRESS 0x40023800

static uint32_t * calculate_address(uint32_t base, uint8_t port)
{
        return (uint32_t *)((uint32_t)base + ((uint32_t)GPIO_OFFSET * port));
}

static void pin_set(volatile uint32_t * address, uint8_t pin)
{
	*address |= (1 << pin);
}

static void pin_clear(volatile uint32_t * address, uint8_t pin)
{
	*address &= ~(1 << pin);
}

static void gpio_set(uint8_t port, uint8_t pin)
{
        volatile uint32_t * address = calculate_address(GPIO_BASE_ADDRESS, port);
        address = ((uint32_t*)((int)address + ODR_OFFSET));
        pin_set(address, pin);
}

static void gpio_clear(uint8_t port, uint8_t pin)
{
        volatile uint32_t * address = calculate_address(GPIO_BASE_ADDRESS, port);
        address = ((uint32_t*)((int)address + ODR_OFFSET));
        pin_clear(address, pin);
}

static void moder_set_output(volatile uint32_t * address, uint8_t pin)
{
        *address |= (1 << (pin<<1));
}

static void moder_set_input(volatile uint32_t * address, uint8_t pin)
{
        *address &= (~(3 << (pin<<1)));
}

static void gpio_mode_set(uint8_t port,uint8_t pin, bool mode)
{
        volatile uint32_t * address = calculate_address(GPIO_BASE_ADDRESS, port); // Address of moder using port
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

void blinky(uint8_t output_port, uint8_t output_pin, uint8_t t_on, uint8_t t_off)
{
        clock_enable(rcc_ahb1enr, output_port); // Clock enable for output port
	gpio_mode_set(output_port, output_pin, output_mode); // Output mode
	for(int i = 0; i<50; i++)	
	{
		gpio_set(output_port, output_pin);
		k_msleep(t_on);
		gpio_clear(output_port, output_pin);
		k_msleep(t_off);
	}	
}
