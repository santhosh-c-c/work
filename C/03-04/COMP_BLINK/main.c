#include <zephyr/kernel.h>
#include "source.h"

int main(void)
{
	complementry_blink(INPUT(port_a), INPUT(pin_3), OUTPUT(port_b), OUTPUT(pin_1));
        return 0;
}
