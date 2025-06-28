#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

static char * sandy(char * s_str, const char * s_del, char ** save)
{
	for(char i=0;*(s_str+i)!=0;i++)
	{
		if(*(s_str+i)==*s_del || *(s_str+i)==*(s_del+1) || *(s_str+i)==*(s_del+2))
		{
			*(s_str+i)='\0';
			*save=(s_str+i+1);
			return s_str;
		}
	}
	return NULL;
}

static char * strtoken(char * str, const char * del)
{
	static char * save=NULL;
	char * ptr;
	if(str!=NULL)
	{
		ptr=sandy(str,del,&save);
		return ptr;
	}
	ptr=sandy(save,del,&save);
	return ptr;

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
	printf("Enter A String : ");
	scanf("%[^\n]s",str);
	getchar();
	printf("Enter A Delim : ");
	scanf("%[^\n]s",del);
	getchar();
	char * result=strtoken(str,del);	
	if(result==NULL)
	{
		printf("Delimiter NOT Found\n");
		return 0;
	}	
	printf("STRING OUTPUT : %s\n",result);
	free(str);
	free(del);
	str=NULL;
	del=NULL;
	return 0;
}
