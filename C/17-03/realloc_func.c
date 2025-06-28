#include<stddef.h>
main()
{
	char * p=malloc(1);
	printf("1 - %p\n",p);
	p=realloc(p,10);
	printf("2 - %p\n",p);
	p=realloc(p,2000);
        printf("3 - %p\n",p);
	p=realloc(p,10);
        printf("4 - %p\n",p);
	p=realloc(p,10);
        printf("5 - %p\n",p);
	p=realloc(NULL,0);
        printf("6 - %p\n",p);

		
}
