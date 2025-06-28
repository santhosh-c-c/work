#ifndef SOURCE_H
#define SOURCE_H

#define TARGET_ADDRESS(X) X
#define DATA(X) X

enum gpio_port {port_a, port_b, port_c, port_d};
enum gpio_pin {pin_0, pin_1, pin_2, pin_3, pin_4, pin_5};
enum gpio_mode {input_mode, output_mode};
enum gpio_register_offset {gpio_otyper = 0x04, gpio_pupdr = 0x0C, gpio_idr = 0x10, gpio_odr = 0x14};
enum rcc_offset_address {rcc_ahb1enr = 0x30};

extern void i2c_sda_pin(uint8_t port, uint8_t pin); 
extern void i2c_scl_pin(uint8_t port, uint8_t pin); 

extern void i2c_write(uint8_t target_address, uint8_t data);
extern void i2c_read(uint8_t target_address);

#endif
