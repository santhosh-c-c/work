#include "ble.h"

ble_device_t *ble_node;
char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"};

#if 0
int node_conn_init(char **dest_node)
{
	int i, error;

	ble_node = (ble_device_t *)calloc(MAX_CLIENTS, sizeof(ble_device_t));
	if(ble_node == NULL) {
		printf("No available memory\n");
		return -ENOMEM;
	}

	for(i = 0; i < MAX_CLIENTS; i++) {
		error = device_ble_connect(&ble_node[i], dest_node[i]);
		if(error < 0) {
			printf("Unable to connect : %s\n", dest_node[i]);
			continue;
		}

		printf("Device Connected : %s\n", dest_node[i]);

		error = pthread_create(&ble_node[i].thread_rx, NULL, device_receiver, (void *)(&(ble_node[i])));
		if(error < 0)
			continue;

		error = pthread_create(&ble_node[i].thread_cm, NULL, device_monitor, (void *)(&(ble_node[i])));
		if(error < 0)
			continue;
	}
	return 0;
}
#endif

#if 0
int node_data_send(char *dest_node, char *node_data)
{
	int i, error;

	for(int i = 0; i < MAX_CLIENTS; i++) {
		error = !(strcasecmp(ble_node[i].mac_addr, dest_node)) && ble_node[i].b_state;
		if(error)
			return device_send_data(&ble_node[i], node_data);
	}
	return -EINVAL;	
}
#endif

#if 0
void node_conn_deinit(void)
{
	int i;

	for(i = 0; i < MAX_CLIENTS; i++) {
		device_disconnect(&ble_node[i]);
	}
	free(ble_node);
}
#endif
