#ifndef BLE_H
#define BLE_H

#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

#define PSM 0x41
#define MTU 2048

int ble_connect(const char *dest_addr);
int ble_send_data(int socket, const char *message);
int ble_receive_data(int socket, char *buffer, size_t buffer_size);
void ble_disconnect(int socket);

#endif
