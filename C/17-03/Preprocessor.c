#include <stdio.h>
#define XSTR(s) STR(s)
#define HI 132
#define XT(s) #s
#define STR(s) XT(s)
#define TEST 123
int main() {
    printf("%s ", XSTR(TEST));
    printf("%s ", XT(TEST));
    printf("%s", STR(TEST));
    return 0;
}
