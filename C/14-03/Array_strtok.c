#include<string.h>
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

static char *strtoken(char * str,const char*d)
{
	static char *c;
	char *r;
	char b[128]={0};
	char *a=str;
	static int l=0;
	if(str==NULL)
	{
		while(*d)
       		{
               		b[*d++]=1;
       		}
		r=c;
		while(*c++)
		{
			if(b[*c])
			{
				*c='\0';
     				if(b[*(c+1)])
     				{
    					c++;
					continue;
     				}
				c=c+1;
				return r;
			}
		}
		return r;
	}
	while(*d)
       	{
       		b[*d++]=1;
       	}
       	while(*a++)
       	{
       		if(b[*a])
       		{
       			*a='\0';
       			if(b[*(a+1)])
       			{
       				a++;
       				continue;
       			}
       			c=a+1;
       			return str;
       		}
       	}
      	 return str;
}
int main()
{
	char *str=(char *)malloc(50), *del=(char *)malloc(50), *out;
        if(str==NULL || del == NULL)
        {
                printf("No Memory Allocated\n");
                return 0;
        }
        printf("Enter a String : ");
        fgets(str,50,stdin);
        printf("Enter a Delimiter : ");
        fgets(del,50,stdin);
	out=strtoken(str,del);
	if(out == NULL)
	{
		printf("Returns Null\n");
		return 0;
	}
	printf("%s\n",out);
	free(str);
	free(del);
	str=NULL;
	del=NULL;
	return 0;
}

