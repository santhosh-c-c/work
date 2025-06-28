#include "ble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>

int ble_connect(const char *dest_addr)
{
	int s, status, level, error;
	struct sockaddr_l2 addr = {0};
	s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
	if (s < 0) {
		perror("Failed to create socket");
		return -1;
	}

	addr.l2_family = AF_BLUETOOTH;
	addr.l2_psm = htobs(PSM);
	addr.l2_bdaddr_type = BDADDR_LE_RANDOM;
	str2ba(dest_addr, &addr.l2_bdaddr);

	level = BT_SECURITY_LOW;
	error = setsockopt(s, SOL_BLUETOOTH, BT_SECURITY, &level, sizeof(level));
	if (error == -1) {
		perror("Security setsockopt failed");
		close(s);
		return -1;
	}

	status = connect(s, (struct sockaddr *)&addr, sizeof(addr));
	if (status < 0) {
		perror("Failed to connect");
		close(s);
		return -1;
	}
	return s;
}

int ble_send_data(int socket, const char *message)
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

int ble_receive_data(int socket, char *buffer, size_t buffer_size) {
	int status;
	memset(buffer, 0, buffer_size);
	status = read(socket, buffer, buffer_size);

	if (status > 0) {
		printf("Received Size : %d\n", status);
		return status;
	}
	return -1;
}

void ble_disconnect(int socket) {
	close(socket);
}
