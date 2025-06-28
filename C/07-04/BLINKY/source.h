#define T_ON(X) X 
#define T_OFF(X) X
#define INPUT(X) X 
#define OUTPUT(X) X 

enum gpio_port {port_a, port_b, port_c, port_d};

enum gpio_pin {pin_0, pin_1, pin_2, pin_3, pin_4, pin_5};

enum gpio_mode {input_mode, output_mode};

enum rcc_offset_address {rcc_ahb1enr = 0x30};

extern void blinky(uint8_t output_port, uint8_t output_pin, uint8_t t_on, uint8_t t_off);

