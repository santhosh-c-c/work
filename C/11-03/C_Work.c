#include <stdio.h>
int main() {
    int arr[2][2] = {{1, 2}, {3, 4}};
    int arr1[2][2] = {{5, 6}, {7, 8}};
    int arr2[2][2] = {{9, 10}, {11, 12}};
    int arr3[2][2] = {{13, 14}, {15, 16}};
    int (*p)[3] = {arr,arr1,arr2,arr3};
    
    printf("%d %d\n", p[0][0], p[0][1]);
    printf("%d %d\n", p[1][0], p[1][1]);
    printf("%d %d\n", p[2][0], p[2][1]);
    printf("%d %d\n", p[3][0], p[3][1]);
    printf("%d %d\n", p[4][0], p[4][1]);
    
    
    
    
   // 1 2 3 | 4 5 6 | 7 8 9 | 10 11 12 | 13 14 15 | 16 x x |
    
    
    //printf("%d\n", sizeof(p));
    return 0;
}
