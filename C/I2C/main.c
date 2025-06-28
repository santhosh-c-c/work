#include <zephyr/kernel.h>
#include <stdlib.h>
#include "eeprom_custom.h"

int main(void)
{
	void * eeprom_1 = eeprom_setup(SDA(port_c), pin_0, SCL(port_c), pin_1, F_KHZ(400), TARGET_ADDRESS(0x50));

	eeprom_page_write(eeprom_1, DATA_WORD_ADDRESS(0x50), 6, "HELLOO");

	eeprom_page_read(eeprom_1, DATA_WORD_ADDRESS(0x50), 6);
     
       	eeprom_deactivate(eeprom_1);
	return 0;
}
