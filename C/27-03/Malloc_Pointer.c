#include<stdio.h>
main()
{
	//char * ptr = malloc(9999999999999999999999999999999999999999);
	char * ptr = malloc(9);
	if(ptr == NULL)
	{
		printf("No Memory Allocated\n");
	}
	char * pointer = ptr;
	*pointer = 65;
	printf("%c\n", *pointer);
}
