#ifndef I2C_CUSTOM_H
#define I2C_CUSTOM_H

#include "gpio_custom.h"

#define TARGET_ADDRESS(X) X
#define DATA_WORD_ADDRESS(X) X
#define SDA(X) X
#define SCL(X) X
#define F_HZ(X) X
#define F_KHZ(X) (X*1000)
#define F_MHZ(X) (X*1000000)

typedef struct
{
        volatile uint32_t* i2c_sda_port;
        volatile uint32_t* i2c_scl_port;
        volatile uint32_t* i2c_idr;
        uint8_t i2c_sda_pin;
        uint8_t i2c_scl_pin;
        uint32_t i2c_clock_cycle_period;
}i2c_init;

void * i2c_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq);
void i2c_send_frame(void * i2c_channel, uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes, uint8_t* data);
void i2c_receive_frame(void * i2c_channel, uint8_t target_address, uint8_t data_word_address, uint8_t num_of_bytes);

#endif
