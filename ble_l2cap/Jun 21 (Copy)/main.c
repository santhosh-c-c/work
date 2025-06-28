#include "ble.h"

int main(void)
{
/* From Upper Layer */
	char *data[] 	     = {"message_1_EE", "message_2_C5", "data_1_EE", "data_2_C5"};
	char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"};
	
	node_conn_init(dest_node);

	if(node_data_send(dest_node[0], data[0]) < 0) {
		printf("Data send failed : %.2s", dest_node[0]);
	}
	printf("Data sent %.2s     : %s\n", dest_node[0], data[0]);
	usleep(100000);
	
	if(node_data_send(dest_node[1], data[1]) < 0) {
                printf("Data send failed : %.2s", dest_node[1]);
        }
	printf("Data sent %.2s     : %s\n", dest_node[1], data[1]);
	usleep(100000);

 	if(node_data_send(dest_node[0], data[2]) < 0) {
		printf("Data send failed : %.2s", dest_node[0]);
	}
	printf("Data sent %.2s     : %s\n", dest_node[0], data[2]);
	usleep(100000);
	
	if(node_data_send(dest_node[1], data[3]) < 0) {
                printf("Data send failed : %.2s", dest_node[1]);
        }
	printf("Data sent %.2s     : %s\n", dest_node[1], data[3]);
	usleep(100000);
	
	return 0;
}
