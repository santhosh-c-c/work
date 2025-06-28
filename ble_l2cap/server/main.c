#include "ble.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    	int server_sock, client_sock;
    	char client_addr[18] = "C5:86:1A:53:D7:3B";
    	char buffer[MTU + 2] = {0};
    	const char *response = "Response : Sensor Data 2";

    	printf("Init BLE server\n");
    	server_sock = ble_server_init(client_addr);
    	if (server_sock < 0) {
        	return 1;
    	}

        client_sock = ble_server_accept(server_sock, client_addr);
#if 0
        if (client_sock < 0) {
        	continue;
        }
#endif
        //printf("Accepted %s\n", client_addr);
        if(ble_server_receive(server_sock, buffer, sizeof(buffer)) > 0) {
          	printf("%s\n", buffer + 2);
        	if (ble_server_send(server_sock, response) < 0) {
                	perror("Failed to respond");
            	}
		printf("%s\n", response);
        }
       	ble_server_close(client_sock);
       	printf("Connection closed\n");
    	ble_server_close(server_sock);
	return 0;
}
