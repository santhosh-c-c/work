#define MAX_CLIENTS 2

void device_conn_init(char **dest_node)
{
        for(int i = 0; i < MAX_CLIENTS; i++) 
        {
		printf("%s\n", dest_node[i]);
        }
}

void main()
{
	char *dest_node[MAX_CLIENTS] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"};
        device_conn_init(dest_node);
}
