#include<stdio.h>
#include<stdlib.h>

//struct
struct str
{
	char * string;
	struct str * next;
};

//global
int a=1;
int size;
struct str * start,  * temp;

//list
static void list_s()
{
	char chk;
	struct str * loc = start;
	printf("\nDo You Want To Specify Position Y/N : ");
	scanf("%c",&chk);
	getchar();
	if(chk == 'Y' || chk == 'y')
	{
		int pos;
		printf("Enter String Position : ");
		scanf("%d",&pos);
		getchar();
		if(pos < 1)
		{
			printf("\nEnter A Valid String Position");
			return ;
		}
		for(int i=1 ; i <  pos ; i++)
		{
			loc = loc -> next;
			if(loc == NULL)
			{
				printf("\nPosition Out Of Range");
				return ;
			}
		}
		printf("Output : %s\n", loc -> string );
		return ;
	}
	while(loc != NULL)
	{
		printf("%s\n", loc -> string);
		loc = loc -> next;
	}
}

//remove
static void remove_s()
{
	struct str * rm, * save; 
	int ind;
	rm = start;
	printf("\nEnter A String Position To Remove : ");
	scanf("%d",&ind);
	getchar();
	if(ind < 1)
	{
		printf("\nEnter A Valid String Position");
		return ;
	}
	if(ind == 1)
	{
		//Removing Start Of List
		save = start -> next;
		free(start);
		start = save;
		printf("Removed\n");
		return ;
	}
	for(int i = 1 ; i<(ind-1) ; i++ )
	{
		rm = rm -> next;
		if(rm == NULL)
		{
			printf("Position Out Of Range");
			return ;
		}
	}
	save = rm -> next;
	rm -> next = save -> next;
	//rm = ((struct str *)(rm -> next)) -> next;
	free(save);
	printf("Removed\n");
}

//replace
static void replace_s()
{
	struct str * rep = start;
	int index, sz;
	printf("\nEnter A String Postion To Replace : ");	
	scanf("%d",&index);
	getchar();
	if(index < 1)
	{
		printf("\nEnter Valid A String Position");
		return ;
	}
	for(int i = 1 ; i < index ; i++ )
	{
		rep = rep -> next;
		if( rep == NULL )
		{
			printf("\nPosition Out Of Range");
			return ;
		}
	}
	printf("Enter String Size : ");
	scanf("%d",&sz);
	getchar();
	rep -> string = realloc(rep -> string, sz);
	printf("Enter String : ");
	scanf("%[^\n]s", rep->string);
	getchar();
	printf("Replaced\n");

}

//string_input
static void string_input()
{
	struct str * ptr = malloc(sizeof(struct str));
	if(ptr == NULL)
	{
		printf("No Memory Allocated\n");
		return ;
	}
	if(!start)
	{
		//To save start of list - 1 time only
		start = ptr;
		temp = ptr;
	}
	else
	{
		temp->next=ptr;
		temp=ptr;
	}
	printf("Enter String Size : ");
	scanf("%d",&size);
	getchar();
	ptr->string = malloc(size);
	if(ptr -> string == NULL)
	{
		printf("No Memory Allocated\n");
		return ;
	}
	printf("Enter a String : ");
	scanf("%[^\n]s", ptr->string);
	getchar();
	ptr->next=NULL;		//Always End Points To NULL
}

int main()
{
	while(a)
	{
		string_input();
		printf("Enter 1 to continue, 0 to stop : ");
		scanf("%d",&a);
		getchar();
	}
	list_s();
	//replace_s();
	//list_s();
	//remove_s();
	//list_s();
	//printf("%s\n",start->string);
	//printf("%s\n",temp->string);
	return 0;
}
