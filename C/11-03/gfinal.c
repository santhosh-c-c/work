#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<stdint.h>
static char *sandy(char *string, const char *delim)
{
	static char * save;
	if(string == NULL)
	{
		char * temp_null_str=save;
		while(*temp_null_str != '\0')
                {

	        	const char* temp_null_del=delim;
                        while(*temp_null_del != '\0')
                        {
                                if(*temp_null_str == *temp_null_del)
                                {
                                        *temp_null_str = '\0';
                                        return save;
                                }
                                temp_null_del++;
                        }
                        temp_null_str++;
                }

	return NULL;
	}
	else
	{
		char *temp_str=string;
                while(*temp_str != '\0')
                {

	        	const char *temp_base_del=delim;
                        while(*temp_base_del != '\0')
                        {
                                if(*temp_str == *temp_base_del)
                                {
                                        *temp_str = '\0';
                        		save=temp_str+1;
					return string;
                                }
                                temp_base_del++;
                        }
                        temp_str++;
                }
	return NULL;
	}

}
int main()
{
	char *str=(char *)malloc(500);
	char *del=(char *)malloc(500);
	if(str==NULL || del == NULL)
	{
		printf("No Memory Allocated\n");
		return 0;
	}
	printf("Enter a String : ");
	fgets(str,500,stdin);
	printf("Enter a Delimiter : ");
	fgets(del,500,stdin);
	printf("%s\n",sandy(str,del));
	//printf("%s\n",sandy(NULL,"z"));
	free(str);
	free(del);
	return 0;
}
