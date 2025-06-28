#include "ble.h"
#include <sys/socket.h>

static int ble_connect(const char *dest_addr)
{
	int s, level, error;
	struct sockaddr_l2 addr = {0};
	s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
	if (s < 0) {
		return -1;
	}

	addr.l2_family = AF_BLUETOOTH;
	addr.l2_psm = htobs(PSM);
	addr.l2_bdaddr_type = BDADDR_LE_RANDOM;
	str2ba(dest_addr, &addr.l2_bdaddr);

	error = connect(s, (struct sockaddr *)&addr, sizeof(addr));
	if (error < 0) {
		close(s);
		return -1;
	}
	return s;
}

static int ble_send_data(int socket, const char *message)
{
	int sdu_len, status;
	char buffer[MTU + 2] = {0};

	sdu_len = htobs(strlen(message));
	memcpy(buffer, &sdu_len, 2);
	memcpy(buffer + 2, message, strlen(message));
	status = write(socket, buffer, 2 + strlen(message));
	if (status < 0) {
		perror("Failed to write");
		return -1;
	}
	return status;
}

static int ble_receive_data(int socket, char *buffer, size_t buffer_size)
{
	int status;
	memset(buffer, 0, buffer_size);
	status = read(socket, buffer, buffer_size);

	if (status > 0) {
		return status;
	}
	return -1;
}

static int device_recv_data(ble_device_t *ble_node, char *buffer, size_t buffer_size)
{
	if(ble_node->b_state) {
		return ble_receive_data(ble_node->node_socket, buffer, buffer_size);
	}
	return -1;
}

static void ble_disconnect(int socket)
{
	close(socket);
}

int device_ble_connect(ble_device_t *ble_node, char *dest_node)
{
	int socket;
	strncpy(ble_node->mac_addr, dest_node, 18);
	socket = ble_connect(dest_node);
	if(!(socket < 0))
	{
		ble_node->b_state     = ble_dev_connected;
		ble_node->t_state     = thread_running;
		ble_node->node_socket = socket;
	}
	return socket;
}

int device_send_data(ble_device_t *ble_node, char *message)
{
	return ble_send_data(ble_node->node_socket, message);
}

void device_disconnect(ble_device_t *ble_node)
{
	ble_node->b_state = ble_dev_disconnected;
	ble_node->t_state = thread_ready;
	ble_disconnect(ble_node->node_socket);
}

void *device_receiver(void * ble_node_arg)
{
    	char buffer[MTU + 2] = {0};
	ble_device_t * ble_node = (ble_device_t *)ble_node_arg;
	while(ble_node->t_state && ble_node->b_state) {
		if(device_recv_data(ble_node, buffer, sizeof(buffer)) > 0) {
			printf("Data from %.2s     : %.2s\n", ble_node->mac_addr, buffer + 2);
		}
		usleep(1000);
	}
}
