#include <zephyr/kernel.h>
#include "source.h"

#define GPIO_BASE_ADDRESS 0x40020000
#define GPIO_OFFSET 0x400

#define RCC_BASE_ADDRESS 0x40023800
#define OPEN_DRAIN 1
#define PULL_UP 1

//made these global so that they can be accessed frm anywhere
volatile uint32_t * i2c_sda_line;
volatile uint32_t * i2c_scl_line;

volatile uint8_t sda_pin;
volatile uint8_t scl_pin;

//i2c_write
static void scl_low()
{
	*i2c_scl_line &= ~(1 << scl_pin);
}

static void scl_high()
{
	*i2c_scl_line |= (1 << scl_pin);
}

static void sda_low()
{
	*i2c_sda_line &= ~(1 << sda_pin);
}

static void sda_high()
{
	*i2c_sda_line |= (1 << sda_pin);
}

//i2c start condition, default pull-up, so sda made low
static void i2c_start()
{
	sda_low();
	k_msleep(0.00125);
	scl_low();
	//k_msleep(0.00125);
}

//writing address & data on the sda
static void i2c_target_address(uint8_t target_address)
{
	for(int i = 0; i<8; i++)
	{
		if(target_address & (1 << 7))
		{
			sda_high();
		}
		else
			sda_low();
		k_msleep(0.00125);
		scl_high();
		k_msleep(0.00125);
		scl_low();
	}
}

//receiving ack to proceed further
static bool read_ack()
{
	sda_high();
	k_msleep(0.00125);
	scl_high();
	k_msleep(0.00125);
	scl_low();
	//moving to idr of the sda, to read using input buffer, ip is still active during output mode
	volatile uint32_t * i2c_idr = (uint32_t *)((int)i2c_sda_line - 0x04);
	return ((*i2c_idr >> sda_pin) & 1);
}

//used only when i2c read is used
static void send_nack()
{
	sda_high();
	k_msleep(0.00125);
	scl_high();
	k_msleep(0.00125);
	scl_low();
}

//i2c stop condtion, sda is pulled low at clock low, then transition to high at clock high
static void i2c_stop()
{
	sda_low();
	k_msleep(0.00125);
	scl_high();
	sda_high();
	k_msleep(0.00125);
}

//gpio setup
//
//input mode to clear bits, then use op mode
static void moder_set_input(volatile uint32_t * address, uint8_t pin)
{
        *address &= ~(3 << (pin<<1));
}

static void moder_set_output(volatile uint32_t * address, uint8_t pin)
{
        *address |= (1 << (pin<<1));
}

static void gpio_mode_set(volatile uint32_t * address, uint8_t pin, bool mode)
{
        moder_set_input(address, pin); // Default is input to clear bits
        if(mode)
        {
                moder_set_output(address, pin); // Output mode
        }
}

//gpio output type register, 1 is given to mention Open-Drain config, offset obtained frm enum
static void gpio_output_type(volatile uint32_t * address, uint8_t pin, bool type)
{
	//push-pull config ignored for now
	if(type)
	{
		address = (uint32_t *)address + gpio_otyper;//refer enum
		*address |= (1 << pin);
	}
}

//pull-up used as default
static void gpio_output_pupd(volatile uint32_t *address, uint8_t pin, bool type)
{
	//pull-down ignored
	if(type)
	{
		address = (uint32_t *)address + gpio_pupdr;
		*address &= ~(2 << (pin << 1));
	}
}

//clock enable for sda, scl, base frm macro, offset frm enum
static void clock_enable(uint32_t rcc_offset, uint8_t position)
{
        volatile uint32_t * address= (volatile uint32_t*)RCC_BASE_ADDRESS + rcc_offset; // rcc_offset is obtained from enum 
        *address |= (1 << position); // Set the respective position
}

//setup common for sda, scl but with their resp port & pin
static volatile uint32_t * i2c_setup(uint8_t port, uint8_t pin)
{
	clock_enable(rcc_ahb1enr, port);
	volatile uint32_t * address = (uint32_t *)GPIO_BASE_ADDRESS + ((uint32_t)GPIO_OFFSET * port); // @moder     
        gpio_mode_set(address, pin, output_mode); //moder                           
        gpio_output_type(address, pin, OPEN_DRAIN); //otyper                   
        gpio_output_pupd(address, pin, PULL_UP); //pupdr
	return ((uint32_t *)address + gpio_odr); //used for global access
}

void i2c_sda_pin(uint8_t port, uint8_t pin)
{
	sda_pin = pin;
	i2c_sda_line = i2c_setup(port, pin); //global variable
}

void i2c_scl_pin(uint8_t port, uint8_t pin)
{
	scl_pin = pin;
	i2c_scl_line = i2c_setup(port, pin);
}

void i2c_write(uint8_t target_address, uint8_t data)
{
	i2c_start();
	i2c_target_address(target_address); //address & data on same function since same operation, 7bit addr, 1 bit for W -> made zero on main
	if(!read_ack())
	{
		i2c_target_address(data);
		read_ack(); // ? 
		i2c_stop();
	}
}

void i2c_read(uint8_t target_address)
{
	i2c_start();
	i2c_target_address(target_address);
	if(!read_ack())
	{
		//Read using LED?
		send_nack();
		i2c_stop();
	}
}

/*
 * SCL HANDLING
 *
 * every function starts with any transitions on sda line
 *
 * then proceeds with sleep for scl_low
 *
 * scl_low is made on previous function
 *
 * so sda transition is made on scl_low, & kept ready for scl_high
 *
 * scl made high, so target can read sda for address/data
 *
 * scl held high for mentioned time
 *
 * function ends with scl pulled to low
 *
 * next function can with sda transitions & sleep for scl_low
 *
 * This process is continued
 *
 */

enable
condition
target_address
send_nack
GPIO_BASE_ADDRESS
