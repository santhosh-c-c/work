#include <zephyr/kernel.h>
#include <stdlib.h>
#include "eeprom_custom.h"

void eeprom_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq)
{
	i2c_setup(sda_port, sda_pin, scl_port, scl_pin, scl_freq);
}

void eeprom_page_write(uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes, uint8_t* data)
{
	i2c_start();
        target_address <<= 1;

        i2c_byte_write(target_address);
        if(i2c_read_ack())
        {
       //         i2c_stop();
       //         return;
        }

        i2c_byte_write(data_word_address);
        if(i2c_read_ack())
        {
         //       i2c_stop();
         //       return;
        }

        for(uint8_t i = 0; i < num_of_bytes; i++)
        {
                i2c_byte_write(*(data+i));
                if(!i2c_read_ack())
                {
                        continue;
                }
        }
	i2c_stop();
}

void eeprom_page_read(uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes) 
{
        uint8_t read_buffer[num_of_bytes];
        i2c_start();
        target_address <<= 1;

        i2c_byte_write(target_address);
        if(i2c_read_ack())
        {
                i2c_stop();
                return;
        }

        i2c_byte_write(data_word_address);
        if(i2c_read_ack())
        {
                i2c_stop();
                return;
        }

        i2c_start();
        target_address |= 1;

        i2c_byte_write(target_address);
        if(i2c_read_ack())
        {
                i2c_stop();
                return;
        }

	for(uint8_t i = 0; i < num_of_bytes; i++)
        {
                read_buffer[i] = i2c_byte_read();
		printf("\nBUFFER DATA %d : %d\n", i, read_buffer[i]);
                if(i == num_of_bytes-1)
                {
                        i2c_send_nack();    
                        return;
                }
                i2c_send_ack();     
        }
        i2c_stop();
}
