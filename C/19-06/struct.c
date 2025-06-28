#include <stdio.h>
#include<string.h>
	typedef struct ble_device {
        int  node_socket;
        char mac_addr[18];
	}ble_device;
 
int device_ble_connect(ble_device *ble_node, char *dest_node)
{
        strncpy(ble_node->mac_addr, dest_node, 18);
        ble_node->node_socket = 3;
	return(ble_node->node_socket);
}
int device_send_data(ble_device *ble_node, char *dest_addr, char *message)
{
        for(int i = 0; i < 2; i++) {
                if(!strcasecmp(ble_node[i].mac_addr, dest_addr)) {
			printf("match for %s\n", ble_node[i].mac_addr);
			return 5;
                }  
	       return -1;	
        }   
        
}


main()
{
char *dest_node[2] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"};

	ble_device ble_node[2] = {0};
        
	for(int i = 0; i < 2; i++)
        {
                if(device_ble_connect(&ble_node[i], dest_node[i]) < 0) {
                        printf("Unable to connect to device : %s\n", dest_node[i]);
                        continue;
                }
                printf("Device Connected : %s\n", ble_node[i].mac_addr);
        }


    for(int i = 0; i < 2; i++)
        {
                if(device_send_data(ble_node, dest_node[0], "hello") < 0) {
                        printf("Unable to send to device : %s\n", dest_node[i]);
                        continue;
                }
                printf("Data sent to device : %s\n", dest_node[i]);
        }
	  if(device_send_data(ble_node, dest_node[0], "hello") < 0) {    
                        printf("Unable to send to device : %s\n", dest_node[0]);                                     
                }
	  else printf("Send");

}
