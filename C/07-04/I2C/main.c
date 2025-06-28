#include <zephyr/kernel.h>
#include "source.h"

int main(void)
{
	//scl, sda, port, pin selection
	i2c_sda_pin(port_a, pin_0);
	i2c_scl_pin(port_a, pin_1);

	//write operation using address & data
	i2c_write(TARGET_ADDRESS(0xfe), DATA(0xff));
	i2c_read(TARGET_ADDRESS(0xff));

        return 0;
}
