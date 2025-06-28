#ifndef BLE_H
#define BLE_H

#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

#define PSM 0x41
#define MTU 2048
#define BDADDR_DEVICE (&(bdaddr_t) {{0xa8, 0x93, 0x4a, 0xdb, 0xea, 0x10}})

int ble_server_init(char *client_addr);
int ble_server_accept(int server_socket, char *client_addr);
int ble_server_receive(int client_socket, char *buffer, size_t buffer_size);
int ble_server_send(int client_socket, const char *message);
void ble_server_close(int socket);

#endif
