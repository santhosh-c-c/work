//#include<stdio.h>
#include<string.h>
main()
{
	char str[]="It returns the pointer to the first token encountered in the string";
	char * token =strtok(str, " " );
		printf("%s",token);
	while(token != NULL)
	{
		printf("%s",token);
		token = strtok(NULL, " - ");
	}
	printf("%s\n",str);
}
