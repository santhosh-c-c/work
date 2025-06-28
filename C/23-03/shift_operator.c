#include <stdio.h>

int main() {
  
    unsigned char a = 1,b=2;

    printf("a << 1 = %d\n", (a << (b-1)));
  
    printf("a >> 2 = %d\n", (a >> 2));

    return 0;
}

