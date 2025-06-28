#include <zephyr/kernel.h>
#include "i2c_custom.h"
#include "stdlib.h"

static void scl_low(i2c_init* i2c_channel)
{
	gpio_clear(i2c_channel -> i2c_scl_port, i2c_channel -> i2c_scl_pin);
}

static void scl_high(i2c_init* i2c_channel)
{
	gpio_set(i2c_channel -> i2c_scl_port, i2c_channel -> i2c_scl_pin);	
}

static void sda_low(i2c_init* i2c_channel)
{
	gpio_clear(i2c_channel -> i2c_sda_port, i2c_channel -> i2c_sda_pin);
}

static void sda_high(i2c_init* i2c_channel)
{
	gpio_set(i2c_channel -> i2c_sda_port, i2c_channel -> i2c_sda_pin);
}

static void i2c_start(i2c_init* i2c_channel)
{
	sda_low(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_low(i2c_channel);
}

static void i2c_repeated_start(i2c_init* i2c_channel)
{
        scl_high(i2c_channel);
	sda_high(i2c_channel);
	sda_low(i2c_channel);
        k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_low(i2c_channel);
}

static void i2c_stop(i2c_init* i2c_channel)
{
        sda_low(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_high(i2c_channel);
        sda_high(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
}

static bool i2c_read_ack(i2c_init* i2c_channel)
{
        sda_high(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_high(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_low(i2c_channel);
        return ((*(i2c_channel -> i2c_idr) << (i2c_channel -> i2c_sda_pin)) & 1);
}

static void i2c_send_nack(i2c_init* i2c_channel)
{
        sda_high(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_high(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_low(i2c_channel);
}

static void i2c_send_ack(i2c_init* i2c_channel)
{
        sda_low(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_high(i2c_channel);
	k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
        scl_low(i2c_channel);
	sda_high(i2c_channel);
}

static void i2c_byte_write(i2c_init* i2c_channel, uint8_t data)
{
        for(uint8_t i = 0; i<8; i++)
        {
                if(data & (1 << (7 - i)))
                {
                        sda_high(i2c_channel);
                }
                else
                {
                        sda_low(i2c_channel);
                }
		k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
                scl_high(i2c_channel);
		k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
                scl_low(i2c_channel);
        }
}

static uint8_t i2c_byte_read(i2c_init* i2c_channel)
{
        uint8_t read_buffer = 0;

	for(uint8_t i = 0; i<8; i++)
        {
		k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
                scl_high(i2c_channel);
                if(*(i2c_channel -> i2c_idr) & (1 << (i2c_channel -> i2c_sda_pin)))
		{
                	read_buffer |= (1 << (7 - i));
		}
		else
		{
                	read_buffer &= ~(1 << (7 - i));
		}
		k_busy_wait(i2c_channel -> i2c_clock_cycle_period);
                scl_low(i2c_channel);
        }
        return read_buffer;
}

static void i2c_set_clock_freq(i2c_init* i2c_channel, uint32_t freq_in_hz)
{
	i2c_channel -> i2c_clock_cycle_period = (1000000*(((float)1/(2*freq_in_hz)))); 
}

static volatile uint32_t* i2c_line_setup(uint8_t port, uint8_t pin)
{
        clock_enable(rcc_ahb1enr, port);
	volatile uint32_t* address = CALC_GPIO_ADDR(port);
        gpio_mode_set(port, pin, output_mode);
        gpio_output_type(port, pin);
        return (uint32_t *)((uint32_t)address + gpio_odr);
}

void* i2c_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq, uint8_t target_address)
{
	i2c_init* i2c_config = (i2c_init*)calloc(1, sizeof(i2c_init));
	
	if(i2c_config == NULL)
	{
		printf("Memory not allocated");
		return NULL;
	}

	i2c_config -> i2c_sda_port = i2c_line_setup(sda_port, sda_pin);
	i2c_config -> i2c_scl_port = i2c_line_setup(scl_port, scl_pin);
	i2c_config -> i2c_sda_pin = sda_pin;
	i2c_config -> i2c_scl_pin = scl_pin;
	i2c_set_clock_freq(i2c_config, scl_freq);
	i2c_config -> i2c_idr = CALC_IDR_ADDR(sda_port);
        i2c_config -> i2c_device_address = target_address;	
        (i2c_config -> i2c_device_address)  <<= 1;
	return (void*)i2c_config;
}

void i2c_send_frame(void* i2c_device, uint8_t data_word_address, uint8_t num_of_bytes, uint8_t* data)
{
        i2c_start(i2c_device);

        i2c_byte_write(i2c_device, ((i2c_init*)i2c_device) -> i2c_device_address);
        if(i2c_read_ack(i2c_device))
        {
                i2c_stop(i2c_device);
                return;
        }

        i2c_byte_write(i2c_device, data_word_address);
        if(i2c_read_ack(i2c_device))
        {
                i2c_stop(i2c_device);
                return;
        }

        for(uint8_t i = 0; i < num_of_bytes; i++)
        {
                i2c_byte_write(i2c_device, *(data+i));
                if(!i2c_read_ack(i2c_device))
                {
                        continue;
                }
        }
        i2c_stop(i2c_device);
        k_msleep(5);
}

void i2c_receive_frame(void* i2c_device, uint8_t data_word_address, uint8_t num_of_bytes)
{
        uint8_t read_buffer[num_of_bytes];
        i2c_start(i2c_device);

        i2c_byte_write(i2c_device, ((i2c_init*)i2c_device) -> i2c_device_address);
        if(i2c_read_ack(i2c_device))
        {
                i2c_stop(i2c_device);
                return;
        }

        i2c_byte_write(i2c_device, data_word_address);
        if(i2c_read_ack(i2c_device))
        {
                i2c_stop(i2c_device);
                return;
        }

        i2c_repeated_start(i2c_device);
        (((i2c_init*)i2c_device) -> i2c_device_address) |= 1;

        i2c_byte_write(i2c_device, ((i2c_init*)i2c_device) -> i2c_device_address);
        if(i2c_read_ack(i2c_device))
        {
                i2c_stop(i2c_device);
                return;
        }

        for(uint8_t i = 0; i < num_of_bytes; i++)
        {
                read_buffer[i] = i2c_byte_read(i2c_device);
                printf("%c", read_buffer[i]);
                if(i == num_of_bytes-1)
                {
                        i2c_send_nack(i2c_device);    
                        return;
                }
                i2c_send_ack(i2c_device);     
        }
        i2c_stop(i2c_device);
}

void i2c_device_deactivate(void* i2c_device)
{
	free(i2c_device);
}
