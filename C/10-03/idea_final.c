#include<stdio.h>
char * sandy(char *p,char *r)
{
	static * ptr=0;
	if(p==NULL)
	{
		char *l=ptr;
	 	while(*l!='\0')
        	{
           	     	if(*l==*r)
                     	{
         	               *l='\0';
                	        return ptr;
                     	}
                	l++;
        	}	
        return NULL;
	}
	char * base=p;
	while(*p!='\0')
        {
                if(*p==*r)
                {
                        *p='\0';
			ptr=p+1;
			return base;
		}
                p++;
        }
	return NULL;
}
main()
{
        char *p=malloc(100);
        char *r=malloc(100);
        printf("\nPlz Enter A String : ");
        gets(p);
	printf("Plz Enter Spacing Element : ");
	gets(r);	
	printf("%s\n",sandy(p,r));
	printf("%s\n",sandy(NULL,"12"));
}
