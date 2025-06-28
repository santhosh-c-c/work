#ifndef EEPROM_CUSTOM_H
#define EEPROM_CUSTOM_H

#include "i2c_custom.h"

#define TARGET_ADDRESS(X) X
#define DATA_WORD_ADDRESS(X) X
#define SDA(X) X
#define SCL(X) X

void* eeprom_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq, uint8_t target_address);
void eeprom_page_write(void * i2c_device, uint8_t data_word_address, uint8_t num_of_bytes, uint8_t* data);
void eeprom_page_read(void * i2c_device, uint8_t data_word_address, uint8_t num_of_bytes);
void eeprom_deactivate(void* i2c_device);

#endif

