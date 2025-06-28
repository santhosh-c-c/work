#include <stdio.h>

char c = 14;
char d = 15;

void main()
{
	char a = 12;
    	char b = 13;
    	printf("%p\n", &c);
    	printf("%p\n", &d);
	printf("%p\n", &a);
	printf("%p\n", &b);
}
