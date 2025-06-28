#include <zephyr/kernel.h>

#define GPIO_BASE 0x40020000
#define RST_CLK_BASE 0x40023800
#define GPIO_OFFSET 0x400
#define ODR_OFFSET 0x14
#define IDR_OFFSET 0x10
#define LOW(x) ~(3<<(x<<1))
#define CLEAR_ODR(x) ~(1<<x)
#define HIGH(x) (1<<(x<<1)) 
#define SET_ODR(x) (1<<x) 

void gpio_set(uint8_t port , uint8_t pin)
{
	uint32_t * gpio_odr = (uint32_t *)(GPIO_BASE + (port * GPIO_OFFSET) + ODR_OFFSET);
	*gpio_odr |= SET_ODR(pin);

}

void gpio_clear(uint8_t port, uint8_t pin)
{
	uint32_t * gpio_odr = (uint32_t *)(GPIO_BASE + (port * GPIO_OFFSET) + ODR_OFFSET);
	*gpio_odr &= CLEAR_ODR(pin);
}

void pin_mode_clear(uint8_t port, uint8_t pin)
{
	uint32_t * mode_reg_x = (uint32_t *)(GPIO_BASE + (port * GPIO_OFFSET));
	*mode_reg_x &= LOW(pin);
}

void pin_outmode_set(uint8_t port, uint8_t pin)
{
	uint32_t * mode_reg_x = (uint32_t *)(GPIO_BASE + (port * GPIO_OFFSET));
	*mode_reg_x |= HIGH(pin);
}

void gpio_mode_set(uint8_t port, uint8_t pin, bool mode)
{
	pin_mode_clear(port, pin);
	if(mode)
		pin_outmode_set(port, pin);
}

void clock_enable(uint32_t rst_offset , uint8_t position)
{
	uint32_t * clk = ((uint32_t *)(RST_CLK_BASE + rst_offset));
	*clk |= (1<<position);
}
uint8_t gpio_read(uint8_t port , uint8_t pin)
{
        volatile uint32_t * gpio_idr = (volatile uint32_t *)(GPIO_BASE + (port * GPIO_OFFSET) + IDR_OFFSET);
        return (*gpio_idr & (1<<pin));

}
