#include "ble.h"

int main(void)
{
	int error;

	/* From Upper Layer */
	char *data[] 	     	     = {"mesg_EE", "mesg_C5", "data_EE", "data_C5"};
	char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"};

	/* Initialization */
	error = node_conn_init(dest_node);
	if(error < 0) {
		printf("Device init failed\n");
		return 1;
	}

	error = node_data_send(dest_node[0], data[0]);
	if(error < 0)
		printf("Data send failed : %.2s\n", dest_node[0]);

	printf("Data sent %.2s : %s\n", dest_node[0], data[0]);
	usleep(1000000);

	error = node_data_send(dest_node[1], data[1]); 
	if(error < 0)
		printf("Data send failed : %.2s\n", dest_node[1]);

	printf("Data sent %.2s : %s\n", dest_node[1], data[1]);
	usleep(1000000);

	node_conn_deinit();
	return 0;
}
