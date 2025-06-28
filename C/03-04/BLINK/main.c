#include <zephyr/kernel.h>
#include "source.h"

int main(void)
{
	blinky(OUTPUT(port_b), OUTPUT(pin_1), T_ON(4), T_OFF(1));
        return 0;
}
