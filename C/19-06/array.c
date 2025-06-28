#include <stdio.h>

void ble(char **dest_node) {
    printf("%s\n", dest_node[0]);
    printf("%s\n", dest_node[1]);
}

int main() {
    char *dest_node[] = {"EE:31:AA:D9:23:CB", "C5:86:1A:53:D7:3B"};
    ble(dest_node);
    return 0;
}

