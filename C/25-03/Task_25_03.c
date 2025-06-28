#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int N;
void replace_s(char *a[])
{
	char chk;
	printf("\nDo you want to replace String Y/N : ");
	scanf("%c",&chk);
	getchar();
	if(chk == 'Y' || chk == 'y')
	{
		int rep;
		printf("Enter Index to replace : ");
		scanf("%d",&rep);
		getchar();
		free(a[rep]);
		printf("Enter A New String : ");
		a[rep]=malloc(4);
		scanf("%[^\n]s",a[rep]);
		getchar();
		printf("Replaced\n");
	}
}
void remove_s(char *a[])
{
	//remove
	char rm;
	printf("\nDo you want to remove string Y/N : ");
	scanf("%c",&rm);	
	getchar();
	if(rm == 'Y' || rm == 'y')
	{
		int num;
		printf("Specify Index : ");
		scanf("%d",&num);
		getchar();
		free(a[num]);
		a[num]=NULL;
		printf("Removed\n");
	}
}
void list_s(char *a[])
{
	//list
	char c;
	printf("\nDo You Want To Specify Index To List Y/N : ");
	scanf("%c",&c);
	getchar();
	if(c == 'Y' || c == 'y')
	{
		int ind;
		printf("\nEnter Index : ");
		scanf("%d",&ind);
		if(a[ind]==NULL)
                {
			printf("\nRequired String is Null\n");
			return ;
         	}   
               	printf("%d - %s\n",ind,a[ind]);
		return ;
	}
	for(int i=0; i<N;i++)
        {
		if(a[i]==NULL)
		{	
			continue;
		}
                printf("%d - %s\n",i,a[i]);
        }
}
int main()
{
	//Initial
	printf("Enter Num of String : ");
	scanf("%d",&N);
	getchar();
	char *a[N];

	//Input
	for(int i=0; i<N;i++)
	{
		int inx;
		printf("Enter String size of %d index : ",i);
		scanf("%d",&inx);
		getchar();
		printf("Enter string %d : ",i);
		a[i]=malloc(inx);
		scanf("%[^\n]s",a[i]);
		getchar();
	}  
	list_s(a);
	remove_s(a);
	list_s(a);
	replace_s(a);
	list_s(a);
	for(int i=0; i<N;i++)
        {
                if(a[i]==NULL)
                {
                        continue;
                }
		free(a[i]);
        }
	return 0;
}

