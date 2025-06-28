#ifndef BLE_H
#define BLE_H

#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_CLIENTS 2
#define PSM 0x41
#define MTU 2048

enum ble_state {
	ble_dev_disconnected,
	ble_dev_connected,
};

enum thread_state {
	thread_ready,
	thread_running,
};

typedef struct ble_device {
	int  node_socket;
	char mac_addr[18];
	enum ble_state b_state;
	pthread_t thread_id;
    	enum thread_state t_state;
} ble_device_t;

int device_ble_connect(ble_device_t *ble_node, char *dest_node);
int device_send_data(ble_device_t *ble_node, char *dest_addr, char *message);
void *device_receiver(void * ble_node_arg);
void device_disconnect(ble_device_t *ble_node);

#endif
