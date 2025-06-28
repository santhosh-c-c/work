#include <zephyr/kernel.h>
#include <stdlib.h>
#include "eeprom_custom.h"

int main(void)
{
	void * i2c_channel = eeprom_setup(SDA(port_c), pin_0, SCL(port_c), pin_1, F_KHZ(400));

	eeprom_page_write(i2c_channel, TARGET_ADDRESS(0x50), DATA_WORD_ADDRESS(0x00), 18, "ABCDEFGHIJKLMNOPQR");

	eeprom_page_read(i2c_channel, TARGET_ADDRESS(0x50), DATA_WORD_ADDRESS(0x00), 18);
      
	return 0;
}
