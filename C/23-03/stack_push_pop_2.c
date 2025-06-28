#include <stddef.h>

struct pwm
{
	void *next;
	int duty;
	char b[4];
};

static * sp[100];
static * base;
static index;
static int stack_init()
{
	struct pwm * ptr = malloc(sizeof(struct pwm));
	if(ptr == NULL)
	{
		printf("Memory not allocated");
	return 0;
	}	
	sp[index] = ptr;
	base = sp[index];
	return 0;
}

static int push(unsigned int duty, unsigned char *a)
{
	struct pwm * ptr = malloc(sizeof(struct pwm));
	if(ptr == NULL)
	{
		printf("Memeory not allocated");
		return 0;
	}
	struct pwm * prev = sp[index];
	prev->next = ptr;
	prev->duty = duty;
	for(int i=0;i<4;i++)
	{
		prev->b[i] = a[i];
	}
	index++;
	sp[index] = ptr;
	return 0;
}
static int pop()
{
	index--;
	free(sp[index]);
	struct pwm * ptr = malloc(sizeof(struct pwm));
	if(ptr == NULL)
	{
		printf("Memory not allocated");
		return 0;
	}
	sp[index] = ptr;
	return 0;
}

int main()
{
	stack_init();
	push(11, "ab");
	//pop();
	push(22, "cd");
	//pop();
	push(33, "de");
	//pop();
	struct pwm * ptr = base;
	while(ptr != sp[index])
	{
		printf("\n%d , %s\n", ptr->duty, ptr->b);
		ptr= ptr->next;
	}
}

