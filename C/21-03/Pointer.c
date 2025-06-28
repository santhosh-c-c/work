#include <stdio.h>
int main()
{
        const char a = 100;
//int *p2=&a;
char *p2=&a;
printf("%p\t%p\t%p\n",&p2,p2,&a);
*p2 = 10;
printf("%p\t%p\t%p\n",&p2,p2,&a);
printf("%d", *p2);
return 0;
}
