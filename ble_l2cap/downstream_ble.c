#include <config.h>
#include <downstream.h>
#include <ble.h>

ble_device_t ble_node[MAX_CLIENTS];

/* Socket */
static int ble_connect(const char *dest_addr)
{
	int s, level, error;
	struct sockaddr_l2 addr = {0};

	s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
	if (s < 0)
		return -ENOSYS;

	addr.l2_family = AF_BLUETOOTH;
	addr.l2_psm = htobs(PSM);
	addr.l2_bdaddr_type = BDADDR_LE_RANDOM;
	str2ba(dest_addr, &addr.l2_bdaddr);

	error = connect(s, (struct sockaddr *)&addr, sizeof(addr));
	if (error < 0) {
		close(s);
		return -ECONNREFUSED;
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
		return -ENOTCONN;
	}
	return status;
}

static int ble_recv_data(int socket, char *buffer, size_t buffer_size)
{
	int status;
	memset(buffer, 0, buffer_size);
	
	status = read(socket, buffer, buffer_size);
	if (status > 0)
		return status;

	return -ENOTCONN;
}

static void ble_disconnect(ble_device_t *ble_node)
{
	ble_node->b_state = ble_dev_disconnected;
	ble_node->t_state = thread_ready;
	ble_node->m_state = thread_ready;
	close(ble_node->node_socket);
}

/* Device */
static int device_ble_connect(ble_device_t *ble_node, char *dest_node)
{
	int socket;
	strncpy(ble_node->mac_addr, dest_node, 18);

	socket = ble_connect(dest_node);
	if(!(socket < 0))
	{
		ble_node->b_state     = ble_dev_connected;
		ble_node->t_state     = thread_running;
		ble_node->m_state     = thread_running;
		ble_node->node_socket = socket;
	}
	return socket;
}

static int device_txr(char *dest_node, char *node_data)
{
	int i, error;

	for(int i = 0; i < MAX_CLIENTS; i++) {
		error = !(strcasecmp(ble_node[i].mac_addr, dest_node)) && ble_node[i].b_state;
		if(error)
			//return device_send_data(&ble_node[i], node_data);
			return ble_send_data(ble_node[i].node_socket, node_data);
	}
	return -EINVAL;	
}

static void *device_rxr(void * ble_node_arg)
{
	int error;
	char buffer[MTU + 2] = {0};
	
	ble_device_t * ble_node = (ble_device_t *)ble_node_arg;
	
	while(ble_node->t_state && ble_node->b_state) {
		//error = device_recv_data(ble_node, buffer, sizeof(buffer));
		error = ble_recv_data(ble_node->node_socket, buffer, sizeof(buffer));
		if(error > 0)
			printf("Resp from %.2s : %.2s\n", ble_node->mac_addr, buffer + 2);

		usleep(1000);
	}
	return NULL;
}


/* Init */
static int ble_conn_init(char **dest_node)
{
	int i;
	int error = 0;
	/* From DS */
	char *data[] = {"mesg_EE", "mesg_C5", "data_EE", "data_C5"};

	for(i = 0; i < MAX_CLIENTS; i++) {
		error = device_ble_connect(&ble_node[i], dest_node[i]);
		if(error < 0) {
			printf("Unable to connect : %s\n", dest_node[i]);
			continue;
		}

		printf("Device Connected : %s\n", dest_node[i]);

		error = pthread_create(&ble_node[i].thread_rx, NULL, device_rxr, (void *)(&(ble_node[i])));
		if(error < 0)
			continue;

		error = device_txr(dest_node[i], data[i]);
		if(error < 0)
			continue;
	}
	return error;
}

static int ld_ble_open(struct ld_config *dev)
{
	int ret = 0;
	struct ld_wireless_config *ble_device = NULL;


	/* Dest node must be from cfg */
	char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"};
#if 0
	ble_device = &dev->ld.wireless;
	ret = node_conn_init(ble_device->dest_node);
#endif
	ret = ble_conn_init(dest_node);
	if(ret != 0)
		goto error;

error:
	return ret;
}

static void ld_ble_close(struct ld_config *dev)
{
	int i;

	for(i = 0; i < MAX_CLIENTS; i++) {
		ble_disconnect(&ble_node[i]);
	}
}

static struct ld_ops ld_ble = {
	.open  = ld_ble_open,
	.close = ld_ble_close,
#if 0
	.read  = /* ? */,
	.write = /* node_data_send */,
#endif
};

struct ld_ops *ld_ble_probe(void)
{
	return &ld_ble;
}
