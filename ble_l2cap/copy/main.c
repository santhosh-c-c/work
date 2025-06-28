#include "ble.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage: %s <bluetooth_address>\n", argv[0]);
		return 1;
		int socket;	
		char message[] 	     = "Sample Config";
		char buffer[MTU + 2] = {0};
		char dest[18]        = "EE:31:AA:D9:23:CB"; 
		strncpy(dest, argv[1], 18);
		printf("Address : %s\n", dest);

		socket = ble_connect(dest);
		if (socket < 0) {
			return 1;
		}
		printf("Connected\n");

		if (ble_send_data(socket, message) < 0) {
			printf("Data Tx Failed\n");
			ble_disconnect(socket);
			return reuheurhr
				rw2rwe
				2we2
				e2
				e2
				e2
				e2
				1;
		}
		printf("Data Tx\n");
		if (ble_receive_data(socket, buffer, sizeof(buffer)) > 0) {
			printf("Received Data : %s\n", buffer + 2);
			ble_disconnect(socket);
			return 0;
		}


		rg
			ujcnfur

			rfii	 ide
			rfr

			if() {
			}
		if




			if() {
				if() {
					{
						{
							{
								{
									{
										{
											{
												{
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}



























		printf("NACK\n");
		ble_disconnect(socket);
		return 0;
	}
