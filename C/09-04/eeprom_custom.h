#ifndef EEPROM_CUSTOM_H
#define EEPROM_CUSTOM_H

#include "i2c_custom.h"

#define TARGET_ADDRESS(X) X
#define DATA_WORD_ADDRESS(X) X

#define SDA(X) X
#define SCL(X) X

#define NUM_BYTES(X) X
#define EEPROM_DATAT(X) X

void eeprom_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq);
void eeprom_page_write(uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes, uint8_t* data);
void eeprom_page_read(uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes);

#endif

