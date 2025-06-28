#include <zephyr/kernel.h>
#include "i2c_custom.h"

static void scl_low(i2c_init * i2c_config)
{
	gpio_toggle(i2c_config -> i2c_scl_port, i2c_config -> i2c_scl_pin);
}

static void scl_high(i2c_init * i2c_config)
{
	gpio_toggle(i2c_config -> i2c_scl_port, i2c_config -> i2c_scl_pin);
}

static void sda_low(i2c_init * i2c_config)
{
	gpio_toggle(i2c_config -> i2c_sda_port, i2c_config -> i2c_sda_pin);
}

static void sda_high(i2c_init * i2c_config)
{
	gpio_toggle(i2c_config -> i2c_sda_port, i2c_config -> i2c_sda_pin);
}

static void i2c_start(i2c_init * i2c_config)
{
	sda_low(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_low(i2c_config);
}

static void i2c_repeated_start(i2c_init * i2c_config)
{
        scl_high(i2c_config);
	sda_high(i2c_config);
	sda_low(i2c_config);
        k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_low(i2c_config);
}

static void i2c_stop(i2c_init * i2c_config)
{
        sda_low(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_high(i2c_config);
        sda_high(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
}

static bool i2c_read_ack(i2c_init * i2c_config)
{
        sda_high(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_high(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_low(i2c_config);
        return ((*(i2c_config -> i2c_idr) << (i2c_config -> i2c_sda_pin)) & 1);
}

static void i2c_send_nack(i2c_init * i2c_config)
{
        sda_high(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_high(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_low(i2c_config);
}

static void i2c_send_ack(i2c_init * i2c_config)
{
        sda_low(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_high(i2c_config);
	k_busy_wait(i2c_config -> i2c_clock_cycle_period);
        scl_low(i2c_config);
	sda_high(i2c_config);
}

static void i2c_byte_write(i2c_init * i2c_config, uint8_t data)
{
        for(uint8_t i = 0; i<8; i++)
        {
                if(data & (1 << (7 - i)))
                {
                        sda_high(i2c_config);
                }
                else
                {
                        sda_low(i2c_config);
                }
		k_busy_wait(i2c_config -> i2c_clock_cycle_period);
                scl_high(i2c_config);
		k_busy_wait(i2c_config -> i2c_clock_cycle_period);
                scl_low(i2c_config);
        }
}

static uint8_t i2c_byte_read(i2c_init * i2c_config)
{
        uint8_t read_buffer = 0;

	for(uint8_t i = 0; i<8; i++)
        {
		k_busy_wait(i2c_config -> i2c_clock_cycle_period);
                scl_high(i2c_config);
                if(*(i2c_config -> i2c_idr) & (1 << i2c_config -> i2c_sda_pin))
		{
                	read_buffer |= (1 << (7 - i));
		}
		else
		{
                	read_buffer &= ~(1 << (7 - i));
		}
		k_busy_wait(i2c_config -> i2c_clock_cycle_period);
                scl_low(i2c_config);
        }
        return read_buffer;
}

static void i2c_set_clock_freq(i2c_init * i2c_config, uint32_t freq_in_hz)
{
	i2c_config -> i2c_clock_cycle_period = (1000000*(((float)1/(2*freq_in_hz)))); 
}

static volatile uint32_t* i2c_line_setup(uint8_t port, uint8_t pin)
{
        clock_enable(rcc_ahb1enr, port);
	volatile uint32_t* address = (uint32_t *)((uint32_t)GPIO_BASE_ADDRESS + ((uint32_t)GPIO_OFFSET * port));
        gpio_mode_set(port, pin, output_mode);
        gpio_output_type(port, pin);
        return (uint32_t *)((uint32_t)address + gpio_odr);
}

void i2c_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq)
{
	i2c_init * i2c_config = (i2c_init *)calloc(1, sizeof(i2c_init);
	if(i2c_config == NULL);
	i2c_config -> i2c_sda_port = i2c_line_setup(sda_port, sda_pin);
	i2c_config -> i2c_scl_port = i2c_line_setup(scl_port, scl_pin);
	i2c_config -> i2c_sda_pin = sda_pin;
	i2c_config -> i2c_scl_pin = scl_pin;
	i2c_set_clock_freq(i2c_config, scl_freq);
	i2c_config -> i2c_idr = ((volatile uint32_t *)(GPIO_BASE_ADDRESS + (sda_port * GPIO_OFFSET) + 0x10)); //0x04
	return i2c_config;
}

void i2c_send_frame(void * i2c_channel, uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes, uint8_t* data)
{
	i2c_init * i2c_config = (i2c_init *)i2c_channel; 
        i2c_start(i2c_config);
        target_address <<= 1;

        i2c_byte_write(i2c_config, target_address);
        if(i2c_read_ack(i2c_config))
        {
                i2c_stop(i2c_config);
                return;
        }

        i2c_byte_write(i2c_config, data_word_address);
        if(i2c_read_ack(i2c_config))
        {
                i2c_stop(i2c_config);
                return;
        }

        for(uint8_t i = 0; i < num_of_bytes; i++)
        {
                i2c_byte_write(i2c_config, *(data+i));
                if(!i2c_read_ack(i2c_config))
                {
                        continue;
                }
        }
        i2c_stop(i2c_config);
        k_msleep(5);
}

void i2c_receive_frame(void * i2c_channel, uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes)
{
	i2c_init * i2c_config = (i2c_init *)i2c_channel;
        uint8_t read_buffer[num_of_bytes];
        i2c_start(i2c_config);
        target_address <<= 1;

        i2c_byte_write(i2c_configtarget_address);
        if(i2c_read_ack(i2c_config))
        {
                i2c_stop(i2c_config);
                return;
        }

        i2c_byte_write(i2c_config, data_word_address);
        if(i2c_read_ack(i2c_config))
        {
                i2c_stop(i2c_config);
                return;
        }

        i2c_repeated_start(i2c_config);
        target_address |= 1;

        i2c_byte_write(i2c_config, target_address);
        if(i2c_read_ack(i2c_config))
        {
                i2c_stop(i2c_config);
                return;
        }

        for(uint8_t i = 0; i < num_of_bytes; i++)
        {
                read_buffer[i] = i2c_byte_read(i2c_config);
                //printf("Read Buffer %d : %c\n", i, read_buffer[i]);
                printf("%c", read_buffer[i]);
                if(i == num_of_bytes-1)
                {
                        i2c_send_nack(i2c_config);    
                        return;
                }
                i2c_send_ack(i2c_config);     
        }
        i2c_stop(i2c_config);
}
