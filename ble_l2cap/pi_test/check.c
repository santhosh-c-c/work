#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

#define PSM 0x41
#define MTU 2048

int main(int argc, char **argv)
{
	int s, status, level, error, mode, sdu_len;
	char dest[18]           = "C5:86:1A:53:D7:3B";
	char dest2[18]          = "EE:31:AA:D9:23:CB";
	char buffer[MTU + 2]    = {0};
	struct sockaddr_l2 addr = {0}, addr = {0}, rem_addr = {0}, rem_addr2 = {0};
	char message[]          = "Response : Sensor 2 Data";
	//strncpy(dest, argv[1], 18);
	socklen_t opt = sizeof(rem_addr);

	s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
	addr.l2_family      = AF_BLUETOOTH;
	addr.l2_psm         = htobs(PSM);
	addr.l2_bdaddr_type = BDADDR_LE_RANDOM;
	str2ba(dest, &addr.l2_bdaddr);

	error = connect(s, (struct sockaddr *)&addr, sizeof(addr));
	if( error < 0 ) {
		perror("Error in Connect");
		return 1;
	}
	if (listen(s, 5) < 0) {
		perror("Listen socket");
		//close(server_sock);
		//return -1;
	}

	status = accept(s, (struct sockaddr *)&rem_addr, &opt);
	printf("Address : %s\n", dest);
	ba2str(&rem_addr.l2_bdaddr, buffer);
	/* Process Request */
	memset(buffer, 0, sizeof(buffer));
	status = read(s, buffer, sizeof(buffer));
	//printf("Received Size : %d\n", status);
	if (status > 0) {
		printf("\n%s\n\n", buffer + 2);
		memset(buffer, 0, sizeof(buffer));
		/* Give Response */
		sdu_len = htobs(strlen(message));
		memcpy(buffer, &sdu_len, 2);
		memcpy(buffer + 2, message, strlen(message));
		status = write(s, buffer, 2 + strlen(message));
		if (status < 0) {
			perror("Failed to write");
			close(s);
			return 0;
		}
		printf("%s\n\n", buffer + 2);
	}
	memset(buffer, 0, sizeof(buffer));
	status = read(s, buffer, sizeof(buffer));
	if (status > 0) {
		printf("Received : %s\n\n", buffer + 2);
	}
	close(s);
	return 0;
}
#if 0
addr.l2_bdaddr = *BDADDR_ANY;
//error = bind(s, (struct sockaddr *)&addr, sizeof(addr));
if (error == -1) {
	perror("bind");
	return 1;
}
#endif
