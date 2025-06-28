#include "ble.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
#if 0
	if (argc < 2) {
		printf("Usage: %s <bluetooth_address>\n", argv[0]);
		return 1;
	}     
#endif
     	int socket;	
	char *message[] 	     = {"message_1", "message_2", "message_3"};
	char buffer[MTU + 2] 	     = {0};
	//char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B", "00:00:00:00:00:00"}; 
	char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"}; 

 	ble_device_t ble_node[MAX_CLIENTS] = {0};
	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		if(device_ble_connect(&ble_node[i], dest_node[i]) < 0) {
			printf("Unable to connect to device : %s\n", dest_node[i]);
			continue;
		}
		printf("Device Connected : %s\n", dest_node[i]);
	}

	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		if(device_send_data(&ble_node[i], dest_node[i], message[i]) < 0) {
			printf("Unable to send to device : %s\n", dest_node[i]);
			continue;
		}
		printf("Data sent to %.2s  : %s\n", dest_node[i], message[i]);

		if(device_recv_data(&ble_node[i], buffer, sizeof(buffer)) < 0) {
			printf("NACK from %s\n", dest_node[i]);
			device_disconnect(&ble_node[i]);
		}
		printf("Data from %.2s     : %s\n", dest_node[i], buffer + 2);
		device_disconnect(&ble_node[i]);
	}
	return 0;
}
#if 0
	socket = ble_connect(dest);
	if (socket < 0) {
		return 1;
	}
	printf("Connected\n");
#endif

#if 0
	if (ble_send_data(socket, message) < 0) {
		printf("Data Tx Failed\n");
		ble_disconnect(socket);
		return 1;
	}
	printf("Data Tx\n");
#endif

#if 0
	if (ble_receive_data(socket, buffer, sizeof(buffer)) > 0) {
		printf("Received Data : %s\n", buffer + 2);
		ble_disconnect(socket);
		return 0;
	}
	printf("NACK\n");
	ble_disconnect(socket);
	return 0;
#endif
