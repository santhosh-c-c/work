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

struct i2c_init
{
        volatile uint32_t* i2c_sda_port;
        volatile uint32_t* i2c_scl_port;
        volatile uint32_t* i2c_idr;
        uint8_t i2c_sda_pin;
        uint8_t i2c_scl_pin;
        uint32_t i2c_clock_cycle_period;
};

extern volatile uint32_t* i2c_sda_port;
extern volatile uint32_t* i2c_scl_port;
extern volatile uint32_t* i2c_idr;
extern uint8_t i2c_sda_pin;
extern uint8_t i2c_scl_pin;
extern uint32_t i2c_clock_cycle_period;

void i2c_start();
void i2c_stop();

bool i2c_read_ack();
void i2c_send_ack();
void i2c_send_nack();

void i2c_setup(uint8_t sda_port, uint8_t sda_pin, uint8_t scl_port, uint8_t scl_pin, uint32_t scl_freq);
void i2c_byte_write(uint8_t data);
uint8_t i2c_byte_read();

#endif
