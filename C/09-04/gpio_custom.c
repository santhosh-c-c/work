#include <zephyr/kernel.h>
#include "gpio_custom.h"

void gpio_mode_set(uint8_t port,uint8_t pin, bool mode)
{
        volatile uint32_t* address = CALC_GPIO_ADDR(port);
        *address &= MODER_REG_CLEAR(pin);
        if(mode)
        {
                *address |= MODER_REG_OUT(pin);
                return;
        }
}

void gpio_output_type(uint8_t port, uint8_t pin)
{
        volatile uint32_t* address = CALC_GPIO_ADDR(port);
        address = (uint32_t *)((uint32_t)address + gpio_otyper);
        *address |= (1 << pin);
}

void clock_enable(uint32_t rcc_offset, uint8_t position)
{
        volatile uint32_t* address= (volatile uint32_t*)((uint32_t)RCC_BASE_ADDRESS + rcc_offset);  
        *address |= (1 << position); 
}

/*void gpio_output_pupd(uint8_t port, uint8_t pin)
{
        volatile uint32_t* address = CALC_GPIO_ADDR(port);
        address = (uint32_t*)((uint32_t)address + gpio_pupdr);
        *address &= ~(3 << (pin << 1));
        *address |= (1 << (pin << 1));
}*/
