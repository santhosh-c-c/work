#include <stdio.h>
void bitwise_toggle(unsigned int *val, unsigned char pos)
{
    *val=(*val) ^ (1<<(pos-49));
}
int main()
{
    unsigned int val;
    unsigned char pos;
    printf("Enter Value : ");
    scanf("%d",&val);
    getchar();
    printf("Enter Position : ");
    scanf("%c",&pos);
    getchar();
    bitwise_toggle(&val, pos);
    printf("Output : %x -  %d\n",val,val);
    return 0;
}
