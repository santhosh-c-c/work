#include <zephyr/kernel.h>
#include <stdlib.h>
#include "eeprom_custom.h"

int main(void)
{
	eeprom_setup(SDA(port_c), pin_0, SCL(port_c), pin_1, F_KHZ(100));

	eeprom_page_write(TARGET_ADDRESS(0xfe), DATA_WORD_ADDRESS(0xaa), NUM_BYTES(4), EEPROM_DATA("ABCD"));

//	eeprom_page_read(TARGET_ADDRESS(0xfe), DATA_WORD_ADDRESS(0xaa), NUM_BYTES(4));
	
	return 0;
}
