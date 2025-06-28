#include<stdio.h>
sandy(char *p,char r)
{
//	printf("\nLinumiZ\n");
	char *q=p;
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
main()
{
	char *p=malloc(100),r;	      	     
	printf("\nPlz Enter A String : ");
	fgets(p,100,stdin);
	printf("Plz Enter Spacing Element : ");
	scanf("%c",&r);	
	sandy(p,r);
}
