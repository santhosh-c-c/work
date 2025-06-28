#ifndef BLE_H
#define BLE_H

#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

//#define MAX_CLIENTS 2
#define MAX_CLIENTS 1
#define PSM 0x0081
#define MTU 32 

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

int node_conn_init(char **dest_node);
int node_data_send(char *dest_node, char *node_data);
int device_ble_connect(ble_device_t *ble_node, char *dest_node);
int device_send_data(ble_device_t *ble_node, char *message);
void *device_receiver(void * ble_node_arg);
void device_disconnect(ble_device_t *ble_node);
void node_conn_deinit(void);

#endif
