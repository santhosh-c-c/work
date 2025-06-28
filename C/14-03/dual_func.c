/*
 *
 * Can only check for 4 char from delim
 *
 * Logic to ignore if delim & start of string is same
 *
 * Try to use %sizeof(del)
 *
 * Use Flag method from earlier version
*/

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
static int func(char a, const char *d)
{
	for(char i=0;*(d+i)!=0;i++)
	{
		if(a==*(d+i))
		{
			return 1;
		}
	}
	return 0;

}
static char * strtoken(char * s_str, const char * del)
{
	static char * save=NULL;
	if(del==NULL || (save==NULL && s_str==NULL))
	{
		return (char *)1;
	}
	if(s_str==NULL)
	{
		s_str=save;
	}
	for(char i=0;*(s_str+i)!=0;i++)
	{
		if(func(*(s_str+i),del))
		{
			*(s_str+i)='\0';
			save=(s_str+i+1);
			return s_str;
		}
	}
	return NULL;
}
int main()
{
	char *str=malloc(100);
	if(str==NULL)
	{
		printf("Memory not Allocated\n");
		return 0;
	}	
	char *del=malloc(100);
	if(del==NULL)
	{
		free(str);
		printf("Memory not Allocated\n");
		return 0;
	}
	printf("1 - Enter A String : ");
	scanf("%[^\n]s",str);
	getchar();
	printf("1 - Enter A Delim : ");
	scanf("%[^\n]s",del);
	getchar();
	char * result=strtoken(str,del);	
	if(result==(char *)1)
	{
		printf("Invalid String Input\n");
		return 0;
	}
	else if(result==NULL)
	{
		printf("Delimiter NOT Found\n");
		return 0;
	}
	printf("\t1 - STRING OUTPUT : %s\n",result);
	printf("Enter A Delim : ");
	scanf("%[^\n]s",del);
	getchar();
	result=strtoken(NULL,del);	
	if(result==NULL)
	{
		printf("2 - Delimiter NOT Found\n");
		return 0;
	}	
	printf("\t2 - STRING OUTPUT : %s\n",result);
	free(str);
	free(del);
	str=NULL;
	del=NULL;
	return 0;
}
