#include<stdio.h>
#include<string.h>
main()
{
	char *p=malloc(100),r;
        printf("\nPlz Enter A String : ");
        fgets(p,100,stdin);
	
	char * token =strtok(p, " " );
                printf("%s ",token);

}
