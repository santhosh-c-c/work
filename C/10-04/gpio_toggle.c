#include <stdint.h>
high(uint8_t * b)
{
	gpio_toggle(b);
}

low(uint8_t * b)
{
	gpio_toggle(b);
}

gpio_toggle(uint8_t * b)
{
	*b ^= 1 << 0; 

}

main()
{
	uint8_t a=1, *b;
	printf("High : %d\n", a);
	b = &a;
	low(b);
	printf("Low : %d\n",*b);
	high(b);
	printf("High : %d\n",*b);
	low(b);
	printf("Low : %d\n",*b);
	high(b);
	printf("High : %d\n",*b);
}

