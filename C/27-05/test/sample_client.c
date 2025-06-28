#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

#define BUFFER_SIZE 2048
#define PSM 0x0041 

int main(int argc, char **argv) {
    struct sockaddr_l2 addr = { 0 };
    int sk;

    sk = socket(PF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
    if (sk < 0) {
        perror("socket");
        return 1;
    }
	printf("Socket Created\n");

    addr.l2_family = AF_BLUETOOTH;
    addr.l2_psm = htobs(PSM);     
    str2ba(argv[1], &addr.l2_bdaddr);

	printf("ADDRESS : %s\n",argv[1]);
    
	if (connect(sk, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sk);
        return 1;
    }

	printf("Socket Conected\n");

    if (write(sk, "Hello", 5) < 0) {
        perror("write");
        close(sk);
        return 1;
    }

	printf("Socket Written\n");

    close(sk);
    return 0;
}
