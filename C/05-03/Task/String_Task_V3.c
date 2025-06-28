#include<stdio.h>
main()
{
	char *p=malloc(100),*q=p,r;	      	     
	printf("\nPlz Enter A String : ");
	fgets(p,100,stdin);
	printf("Plz Enter Spacing Element : ");
	scanf("%c",&r);
	while(*p!='\0')
	{
		if(*p==r)
		{
			*p='\0';
			printf("%s\n",q);
			q=p+1;
		}
		p++;
	}
			printf("%s\n",q);

}
