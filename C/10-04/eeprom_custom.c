#include <zephyr/kernel.h>
#include <stdlib.h>
#include "eeprom_custom.h"

void * eeprom_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq)
{
	return i2c_setup(sda_port, sda_pin, scl_port, scl_pin, scl_freq);
}

void eeprom_page_write(void * i2c_channel, uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes, uint8_t* data)
{
	i2c_send_frame(void * i2c_channel, uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes, uint8_t* data);
}

void eeprom_page_read(void * i2c_channel, uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes) 
{
	i2c_receive_frame(void * i2c_channel, uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes);
}
