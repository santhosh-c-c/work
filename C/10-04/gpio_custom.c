#include <zephyr/kernel.h>
#include "gpio_custom.h"

void gpio_toggle(volatile uint32_t* port, uint8_t pin)
{
	*port ^= (1 << pin);
}

void gpio_mode_set(uint8_t port,uint8_t pin, bool mode)
{
        volatile uint32_t* add = CALC_GPIO_ADDR(port);
        *add &= MODER_REG_CLEAR(pin);
        if(mode)
        {
                *add |= MODER_REG_OUT(pin);
                return;
        }
}

void gpio_output_type(uint8_t port, uint8_t pin)
{
        volatile uint32_t* add = CALC_GPIO_ADDR(port);
        add = (uint32_t *)((uint32_t)add + gpio_otyper);
        *add |= (1 << pin);
}

void clock_enable(uint32_t rcc_offset, uint8_t position)
{
        volatile uint32_t* address= (volatile uint32_t*)((uint32_t)RCC_BASE_ADDRESS + rcc_offset);  
        *address |= (1 << position); 
}

/*void gpio_output_pupd(uint8_t port, uint8_t pin)
{
        volatile uint32_t* add = CALC_GPIO_ADDR(port);
        add = (uint32_t*)((uint32_t)add + 0x0C);
        *add &= ~(3 << (pin << 1));
        *add |= (1 << (pin << 1));
}*/


