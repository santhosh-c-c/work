
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

#define BUFFER_SIZE 2048

int main() {
    struct sockaddr_l2 addr = { 0 }, client_addr = { 0 };
    socklen_t optlen;
    int sk, nsk;
    char buf[BUFFER_SIZE] = { 0 };

    sk = socket(PF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
    if (sk < 0) {
        perror("socket");
        exit(1);
    }

    addr.l2_family = AF_BLUETOOTH;
    addr.l2_psm = htobs(0x1001); 
    //printf("Addr %s\n", "A8:93:4A:DB:EA:10");
    bacpy(&addr.l2_bdaddr, "A8:93:4A:DB:EA:10");
    addr.l2_bdaddr = *BDADDR_ANY;

    if (bind(sk, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sk);
        exit(1);
    }

    if (listen(sk, 5) < 0) {
        perror("listen");
        close(sk);
        exit(1);
    }

    printf("Waiting for connection!\n");

    optlen = sizeof(client_addr);
    nsk = accept(sk, (struct sockaddr *)&client_addr, &optlen);
    if (nsk < 0) {
        perror("accept");
        close(sk);
        exit(1);
    }

    char client_addr_str[18];
    //ba2str(&client_addr.l2_bdaddr, "A8:93:4A:DB:EA:54");
    ba2str(&client_addr.l2_bdaddr, client_addr_str);
    printf("Accepted connection from %s\n", client_addr_str);

    int n = read(nsk, buf, sizeof(buf) - 1);
    if (n > 0) {
         buf[n] = '\0';
         printf("Received: %s\n", buf);
    }
    else {
         perror("read");
    }

    close(nsk);
    close(sk);
    return 0;
}
