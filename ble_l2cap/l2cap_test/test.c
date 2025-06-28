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
	struct sockaddr_l2 addr = { 0 };
	int s, status, level, error, mode, sdu_len;
	char buffer[MTU + 2] = {0};
	char message[] = "Hello From Linux to Zephyr";
	char dest[18] = "EE:31:AA:D9:23:CB";
	strncpy(dest, argv[1], 18);
	printf("Address : %s\n", dest);

	s = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
	addr.l2_family = AF_BLUETOOTH;
	addr.l2_psm = htobs(PSM);
	addr.l2_bdaddr_type = BDADDR_LE_RANDOM;
	str2ba(dest, &addr.l2_bdaddr);

        level = BT_SECURITY_LOW;
        error = setsockopt(s, SOL_BLUETOOTH, BT_SECURITY, &level, sizeof(level));
        
        if (error == -1) {
            	perror(" 2 setsockopt");
            	return 1;
        }
	
	status = connect(s, (struct sockaddr *)&addr, sizeof(addr));
	if (status < 0) {
		perror("Failed to connect");
	    	close(s);
	    	exit(1);
	}
	printf("Connected & Sending Data : %s\n", message);
/* SDU */
	sdu_len = htobs(strlen(message));
	memcpy(buffer, &sdu_len, 2);
	memcpy(buffer + 2, message, strlen(message));
	status = write(s, buffer, 2 + strlen(message));
	if (status < 0) {
    		perror("Failed to write");
	}

 	memset(buffer, 0, sizeof(buffer));
	status = read(s, buffer, sizeof(buffer));
	printf("Received Size : %d\n", status);
	if (status > 0) {
	    	printf("Received Data : %s\n", buffer + 2);
		close(s);
		return 0;
	}

        printf("NACK\n");
	close(s);
	return 0;
}
