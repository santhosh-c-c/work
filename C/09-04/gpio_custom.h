#ifndef GPIO_CUSTOM_H
#define GPIO_CUSTOM_H

#define T_ON(X) X 
#define T_OFF(X) X
#define INPUT(X) X 
#define OUTPUT(X) X

#define GPIO_BASE_ADDRESS 0x40020000
#define GPIO_OFFSET 0x400

#define RCC_BASE_ADDRESS 0x40023800
#define OPEN_DRAIN true
#define PULL_UP true

#define PIN_HIGH(PIN) (1 << PIN)
#define PIN_LOW(PIN) (~(1 << PIN))
#define MODER_REG_OUT(PIN) (1 << (PIN<<1))
#define MODER_REG_CLEAR(PIN) (~(3 << (PIN<<1)))
#define CALC_GPIO_ADDR(PORT) (uint32_t*)((uint32_t)GPIO_BASE_ADDRESS + ((uint32_t)GPIO_OFFSET * (uint8_t)PORT))
#define CALC_RCC_ADDR(BLOCK) ((volatile uint32_t*)((uint32_t)RCC_BASE_ADDRESS + BLOCK))

enum gpio_port {port_a, port_b, port_c, port_d};
enum gpio_pin {pin_0, pin_1, pin_2, pin_3, pin_4, pin_5};
enum gpio_mode {input_mode, output_mode};
enum gpio_register_offset {gpio_otyper = 0x04, gpio_pupdr = 0x0C, gpio_idr = 0x10, gpio_odr = 0x14};
enum rcc_offset_address {rcc_ahb1enr = 0x30};

void gpio_mode_set(uint8_t port,uint8_t pin, bool mode);
void gpio_output_type(uint8_t port, uint8_t pin);
//void gpio_output_pupdr(uint8_t port, uint8_t pin);
void clock_enable(uint32_t rcc_offset, uint8_t position);

#endif
