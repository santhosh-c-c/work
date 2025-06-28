#include <stddef.h>  
#include <pthread.h>  

static void *func(void *)
{
	while(1) {
		printf("San1234567890\n");
		sleep(1);
	}
}

static void *func_2(void *)
{
	while(1) {
		printf("Giri1234567890\n");
		sleep(1);
	}
}


int main()
{
pthread_t thread_id;
pthread_t thread_id_2;
	pthread_create(&thread_id, NULL, func, NULL);
	pthread_create(&thread_id_2, NULL, func_2, NULL);
	printf("Alex\n");
	sleep(2);
	//pthread_join(thread_id, NULL);
	pthread_detach(thread_id);
	return 0;
}
