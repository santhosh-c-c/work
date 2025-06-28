#include <zephyr/kernel.h>
#include "i2c_custom.h"

typedef struct i2c_init i2c_init;

volatile i2c_init * i2c_bus_cfg;

static void scl_low()
{
        *(i2c_bus_cfg -> i2c_scl_port) &= PIN_LOW(i2c_bus_cfg -> i2c_scl_pin);
}

static void scl_high()
{
        *(i2c_bus_cfg -> i2c_scl_port) |= PIN_HIGH(i2c_bus_cfg -> i2c_scl_pin);
}

static void sda_low()
{
        *(i2c_bus_cfg -> i2c_sda_port) &= PIN_LOW(i2c_bus_cfg -> i2c_sda_pin);
}

static void sda_high()
{
        *(i2c_bus_cfg -> i2c_sda_port) |= PIN_HIGH(i2c_bus_cfg -> i2c_sda_pin);
}

static void i2c_set_clock_freq(uint32_t freq_in_hz)
{
	i2c_bus_cfg -> i2c_clock_cycle_period = (1000000*(1/(2*freq_in_hz))); 
	//i2c_clock_cycle_period = 5;
}

void i2c_start()
{
	sda_low();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
        scl_low();
}

void i2c_stop()
{
        sda_low();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
        scl_high();
        sda_high();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
}

bool i2c_read_ack()
{
        sda_high();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
        scl_high();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
        scl_low();
        return ((*(i2c_bus_cfg -> i2c_idr) << (i2c_bus_cfg -> i2c_sda_pin)) & 1);
}

void i2c_send_nack()
{
        sda_high();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
        scl_high();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
        scl_low();
}

void i2c_send_ack()
{
        sda_low();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
        scl_high();
	k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
        scl_low();
}

static volatile uint32_t* i2c_line_setup(uint8_t port, uint8_t pin)
{
        clock_enable(rcc_ahb1enr, port);
	volatile uint32_t* address = (uint32_t *)((uint32_t)GPIO_BASE_ADDRESS + ((uint32_t)GPIO_OFFSET * port));
        gpio_mode_set(port, pin, output_mode);
        gpio_output_type(port, pin);
//      gpio_output_pupd(address, pin, 1);
        return (uint32_t *)((uint32_t)address + gpio_odr);
}

void i2c_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq)
{
	i2c_set_clock_freq(scl_freq);
	i2c_bus_cfg -> i2c_sda_port = i2c_line_setup(sda_port, sda_pin);
	i2c_bus_cfg -> i2c_scl_port = i2c_line_setup(scl_port, scl_pin);
	i2c_bus_cfg -> i2c_sda_pin = sda_pin;
	i2c_bus_cfg -> i2c_scl_pin = scl_pin;
	i2c_bus_cfg -> i2c_idr = (uint32_t*)((int)(i2c_byte_write -> i2c_sda_port) - (gpio_odr - gpio_idr)); //0x04
}

void i2c_byte_write(uint8_t data)
{
        for(uint8_t i = 0; i<8; i++)
        {
                if(data & (1 << (7 - i)))
                {
                        sda_high();
                }
                else
                {
                        sda_low();
                }
		k_busy_wait(i2c_byte_read -> i2c_clock_cycle_period);
                scl_high();
		k_busy_wait(i2c_byte_read -> i2c_clock_cycle_period);
                scl_low();
        }
}

uint8_t i2c_byte_read()
{
        uint8_t read_buffer = 0;
        for(uint8_t i = 0; i<8; i++)
        {
                read_buffer |= (((*(i2c_bus_cfg -> i2c_idr)) << (i2c_bus_cfg -> i2c_sda_pin)) << (7 - i));
		k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
                scl_high();
		k_busy_wait(i2c_bus_cfg -> i2c_clock_cycle_period);
                scl_low();
        }
        return read_buffer;
}
