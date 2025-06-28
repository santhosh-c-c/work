#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *arg);
void *bhread_function(void *arg);
pthread_t a_thread;  //thread declaration  
	pthread_t b_thread;  //thread declaration  


int main()
{		pthread_create(&a_thread, NULL, thread_function, NULL); 
	pthread_create(&b_thread, NULL, bhread_function, NULL); 
#if 0
	printf("Inside Main Program\n");
	for(int j=20;j<25;j++)
	{
		printf("%d\n",j);
		sleep(1);
	}
#endif
	return 0;
}
void *thread_function(void *arg) 
{// the work to be done by the thread is defined in this function
	printf("Inside Thread\n");
	for(int i=0;i<5;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
	return NULL;
}
void *bhread_function(void *arg) 
{// the work to be done by the thread is defined in this function
	printf("Inside Bhread\n");
	for(int i=100;i<105;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
	return NULL;
}
