#include <stdio.h>
#include <stddef.h>

struct pwm 
{
	void *next;
	int duty;
	char b[4];	
};

void * head;

static void push(unsigned int duty , unsigned char *a)
{
	struct pwm * ptr = malloc(sizeof(struct pwm));
	if(ptr == NULL)
	{
		printf("Memory not allocated\n");
		return ;
	}
	ptr->next = head;
	ptr->duty = duty;
	for(int i=0; i<4;i++)
	{
		ptr->b[i] = a[i];
	}
	head = ptr;
}

static void pop()
{
	if(head == NULL)
	{
		return ;
	}
	struct pwm *temp = head;
	temp = temp->next;
	free(head);
	head = temp;
}

int main()
{
	pop();
	push(43,"aa");
	push(12,"bb");
	pop();
	push(23,"cc");
	push(32,"dd");
	pop();
	struct pwm * temp = head;
	while(temp != NULL)
	{
		printf("%d , %s\n", temp->duty, temp->b);
		temp = temp->next;
	}
}
