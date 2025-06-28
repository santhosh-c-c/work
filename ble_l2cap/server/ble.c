#include "ble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>

int ble_server_init(char *client_addr)
{
	int server_sock;
    	struct sockaddr_l2 addr = {0};

    	server_sock = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
    	if (server_sock < 0) {
        	perror("Create socket");
        	return -1;
    	}

    	addr.l2_family = AF_BLUETOOTH;
    	addr.l2_psm = htobs(PSM);
    	addr.l2_bdaddr_type = BDADDR_LE_RANDOM;
	addr.l2_bdaddr = *BDADDR_ANY;
	//addr.l2_bdaddr = *BDADDR_DEVICE;
	//str2ba(client_addr, &addr.l2_bdaddr);

#if 0
        if(connect(server_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
                perror("Error in Connect");
                return 1;
        }
#endif
	//bind(server_sock, (struct sockaddr *)&addr, sizeof(addr));
	
#if 1
	if(bind(server_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Bind");
		return -1;
	}
#endif
    	if (listen(server_sock, 5) < 0) {
#if 0
        	perror("Listen socket");
        	close(server_sock);
        	return -1;
#endif    
	}
    	return server_sock;
}

int ble_server_accept(int server_socket, char *client_addr)
{
	struct sockaddr_l2 rem_addr = {0};
    	socklen_t opt = sizeof(rem_addr);
    	int client_sock;

    	client_sock = accept(server_socket, (struct sockaddr *)&rem_addr, &opt);
#if 0
    	if (client_sock < 0) {
        	perror("Accept connection");
        	return -1;
    	}
#endif
    	ba2str(&rem_addr.l2_bdaddr, client_addr);
    	return client_sock;
}

int ble_server_receive(int client_socket, char *buffer, size_t buffer_size)
{
    	int status;
    	memset(buffer, 0, buffer_size);
    	status = read(client_socket, buffer, buffer_size);
    	return status;
}

int ble_server_send(int client_socket, const char *message)
{
    	char buffer[MTU + 2] = {0};
    	int status, sdu_len;
	sdu_len = htobs(strlen(message));
    	memcpy(buffer, &sdu_len, 2);
    	memcpy(buffer + 2, message, strlen(message));
    	status = write(client_socket, buffer, 2 + strlen(message));
    	return status;
}

void ble_server_close(int socket)
{
    	close(socket);
}
