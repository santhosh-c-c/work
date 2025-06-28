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
#include <stdint.h>

#define PSM 0x0081
#define MTU 2048
#define MAX_CLIENTS 3

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
	enum thread_state t_state;
	enum thread_state m_state;
	pthread_t thread_rx;
	pthread_t thread_cm;
	
} ble_device_t;

#endif
