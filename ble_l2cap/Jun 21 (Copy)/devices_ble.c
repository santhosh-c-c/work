#include "ble.h"

char *dest_node[MAX_CLIENTS]       = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"}; 
ble_device_t ble_node[MAX_CLIENTS] = {0};

void node_conn_init(char **dest_node)
{
	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		if(device_ble_connect(&ble_node[i], dest_node[i]) < 0) {
			printf("Unable to connect : %s\n", dest_node[i]);
			continue;
		}
		printf("Device Connected : %s\n", dest_node[i]);
		if(pthread_create(&ble_node[i].thread_id, NULL, device_receiver, (void *)(&(ble_node[i]))) < 0) {
			continue;
		}
	}
}

int node_data_send(char *dest_node, char *node_data)
{
	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		if(!(strcasecmp(ble_node[i].mac_addr, dest_node)) && ble_node[i].b_state) {
			return device_send_data(&ble_node[i], node_data);
		}
	}
	return -1;	
}
