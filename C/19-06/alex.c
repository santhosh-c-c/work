#include<stdio.h>
void fun() 
{
	while(1) {
		printf("func\n");
		sleep(1);
	}
}

void cb(void(*func)(void)) {

	(*func)();
}

int main()
{
	while(1) {
		printf("main\n");
		sleep(1);
	}
	cb(fun);
	return 0;
}

