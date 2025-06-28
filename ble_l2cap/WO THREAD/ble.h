#ifndef BLE_H
#define BLE_H

#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

#define MAX_CLIENTS 2
#define PSM 0x41
#define MTU 2048

enum ble_state {
        BLE_DEV_DISCONNECTED,
        BLE_DEV_CONNECTED,
};

typedef struct ble_device {
	int  node_socket;
	char mac_addr[18];
	enum ble_state state;
} ble_device_t;

int device_ble_connect(ble_device_t *ble_node, char *dest_node);
int device_send_data(ble_device_t *ble_node, char *dest_addr, char *message);
int device_recv_data(ble_device_t *ble_node, char *buffer, size_t buffer_size);
void device_disconnect(ble_device_t *ble_node);

#endif
