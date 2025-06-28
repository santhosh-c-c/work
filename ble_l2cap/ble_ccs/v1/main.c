#include "ble.h"

int main(void)
{
	int ret;

	char *data[] 	     = {"1211_CD", "1917_CD"};
	//char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"};
	char *dest_node[MAX_CLIENTS] = {"CD:4F:83:20:86:40"};
	//char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB"};
	//char *dest_node[MAX_CLIENTS] = {"C5:86:1A:53:D7:3B"};

	if(node_conn_init(dest_node) < 0) {
		printf("Device init failed\n");
		return 1;
	}

	if(node_data_send(dest_node[0], data[0]) < 0) {
		printf("Data send failed : %.2s\n", dest_node[0]);
	}
	printf("Data sent %.2s     : %s\n", dest_node[0], data[0]);
	usleep(1000000);

	return 0;
}
