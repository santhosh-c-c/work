#include<stdint.h>
#include<stdbool.h>
main()
{
	//uint8_t a = 10;
	uint8_t a = 255;
	for(int i = 0 ; i<8 ; i++)
	{
		if((a & (1 << 7)))
		{
			printf(" %d ", (bool)(a & (1 << 7)));
		}
		else
			printf(" 0 ");
		a <<= 1;
	}
}
