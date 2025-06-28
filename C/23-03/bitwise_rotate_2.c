#include <stdio.h>
void bitwise_rotate(unsigned int *val, unsigned char bits, char dir)
{
	bits-=48;
	if(dir == '0')
	{
		*val=(*val << bits) | (*val >> (32-bits)); // Left rotate
	}
	else
	{
		*val=(*val >> bits) | (*val << (32-bits)); // Right rotate
	}

}
int main()
{
    unsigned int val;
    unsigned char bits;
    char dir;
    
    printf("Enter Num : ");
    scanf("%d", &val);
    getchar();
    printf("Enter Bits : ");
    scanf("%c",&bits);
    getchar();
    printf("Enter Dir - 1 for right rotate : ");
    scanf("%c",&dir);
    printf("Input : %u\n",val);
    bitwise_rotate(&val, bits, dir);
    printf("Output : %u\n",val);

    return 0;
}
