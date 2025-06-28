#include <stdio.h>
#include <stdlib.h>

struct pwm 
{
	void *next;
	int duty;
	char b[4];	
};

struct pwm * top;

static void push(int duty, char *a)
{
	struct pwm * ptr = malloc(sizeof(struct pwm));
	if(ptr == NULL)
	{
		printf("Memory not allocated\n");
		return ;
	}
	ptr->next = top;
	ptr->duty = duty;
	for(int i=0; i<4; i++)
	{
		ptr->b[i] = a[i];
	}
	top = ptr;
}

static void pop()
{
	if(top == NULL)
	{
		printf("Nothing To POP\n");
		return ;
	}
	void * save = top -> next;
	free(top);
	top = save;
}

int main()
{
	pop();
	push(43,"aa");
	pop();
	pop();
	push(22,"bb");
	push(11,"aa");
	pop();
	push(11,"aa");
	struct pwm * loop = top;
	while(loop != NULL)
	{
		printf("%d , %s\n", loop->duty, loop->b);
		loop = loop->next;
	}
}
