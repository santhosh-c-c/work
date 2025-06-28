#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include<stddef.h>
int main()
{
	/*char a[]="abc173def";
	char b[]="abc1lll3ldef";
*/
	  char *str=(char *)malloc(500), *del=(char *)malloc(500);
        if(str==NULL || del == NULL)
        {
                printf("No Memory Allocated\n");
                return 0;
        }
        printf("Enter a String : ");
        fgets(str,500,stdin);
        printf("Enter a Delimiter : ");
        fgets(del,500,stdin);


	printf("%s\n",strtok(str,del));
        printf("%s\n",strtok(NULL,"T"));
return 0;
}
