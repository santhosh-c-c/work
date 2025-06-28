#include "ble.h"

int main(int argc, char **argv)
{
     	int socket;	
	char *message[] 	     = {"message_1_EE", "message_2_C5"};
	char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"}; 

 	ble_device_t ble_node[MAX_CLIENTS] = {0};
	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		if(device_ble_connect(&ble_node[i], dest_node[i]) < 0) {
			printf("Unable to connect : %s\n", dest_node[i]);
			continue;
		}
		printf("Device Connected : %s\n", dest_node[i]);
		if(pthread_create(&ble_node[i].thread_id, NULL, device_receiver, (void *)(&(ble_node[i]))) < 0) {
			printf("No thread");
			continue;
		}
	}

	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		if(device_send_data(&ble_node[i], dest_node[i], message[i]) < 0) {
			printf("Unable to send : %s\n", dest_node[i]);
			continue;
		}
		printf("Data sent to %.2s  : %s\n", dest_node[i], message[i]);
	}
	usleep(100000);
	return 0;
}
