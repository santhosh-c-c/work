#include "Global_Static.c"
void main()
{
	printf("%d %p\n",a,&a);
{
	extern a;
	printf("%d %p\n",a,&a);
}
}
