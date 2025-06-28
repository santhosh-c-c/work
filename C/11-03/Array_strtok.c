#include<string.h>
#include<stddef.h>
#include<stdio.h>

char *strtoken(char * str,const char*d)
{
	static char *c;
	char *r;
	char b[256]={0};
	char *a=str;
	static int l=0;
	if(str==NULL)
	{
		while(*d)
       		{
               		b[(unsigned)*d]=1;
               		d++;
       		}

		r=c;
		while(*c)
		{
			if(b[(unsigned)*c])
			{
				*c='\0';
     				if(b[(unsigned)*(c+1)])
     				{
    					c++;
					continue;
     				}
				c=c+1;
				return r;
			}
		c++;
		}
		return r;
	}
	if(l)
	{
		return str;
	}
	while(*d)
       	{
       		b[(unsigned)*d]=1;
       		d++;
       	}
       	while(*a)
       	{
       		if(b[(unsigned)*a])
       		{
       			*a='\0';
       			if(b[(unsigned)*(a+1)])
       			{
       				a++;
       				continue;
       			}
       			c=a+1;
       			l=1;
       			return str;
       		}
       		a++;
       	}
      	 return str;
}
int main()
{
	char z[]="aaaaabc173daef";
	printf("%s\n",strtok(z,"a"));
	printf("%s\n",strtok(NULL,"a"));
	//printf("%s\n",strtoken(z,"l"));
	return 0;
}

