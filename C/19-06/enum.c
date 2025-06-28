#include <stdio.h>
#include <stdlib.h>

enum ble_state {
        BLE_DEV_DISCONNECTED,
        BLE_DEV_CONNECTED,
};

typedef struct ble_device {
        int  node_socket;
        char mac_addr[18];
        enum ble_state state;
} ble_device_t;

void main()
{
	ble_device_t ble_node[2] = {1};
	printf("State : %d\n", ble_node[1].state);
	ble_node[1].state =  BLE_DEV_CONNECTED;
	printf("State : %d\n", ble_node[1].state);
//	ble_node[1].state =  BLE_DEV_DISCONNECTED;
	printf("State : %d\n", ble_node[1].state);
	if(ble_node[1].state)
		printf("yes");

}
