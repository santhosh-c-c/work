#include<stdio.h>
main()
{
	char *p=malloc(5);
	fgets(p,50,stdin);
	//char *a[1]={p};
	char *a=p;
	//printf("%c\n%c\n%c\n",**a,*(*a+1),*(*a+2));
	//printf("%c\n%c\n%c\n",*a,*(a+1),*(a+2));
	printf("%c\n%c\n%c\n",*p,*(p+1),*(p+3));
	if(*(p+3)=='\0')
	{
		printf("NULL");
	}
}
