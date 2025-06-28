/*
 * 2147483648 can't be given as an input
 *
 * But can be hardcoded
 *
*/
#include <stdio.h>
void bitwise_rotate(unsigned int *val, unsigned char bits, char dir)
{
    bits = bits - 48; dir = dir - 48;
    for(; bits>0 ; bits--)
    {
        unsigned int save=0xffffffff;
        save=(*val)&save;
        if(dir)
        {
            *val=(*val>>1) | (save<<31);
        }
	else
	{
        *val=(*val<<1) | (save>>31);
	}
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
    printf("Enter Dir : ");
    scanf("%c",&dir);
    printf("Input : %u\n",val);
    bitwise_rotate(&val, bits, dir);
    printf("Output : %u\n",val);

    return 0;
}
