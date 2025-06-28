#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int strncasecmp_own(const char* c, const char* d, size_t n) {

    	while (n-- > 0) {
    
	char a = *c++;
        char b = *d++;

		if(a=='\0' || b== '\0')
		{
			return a-b;

		}
//      printf("%s\n", &a);
//      printf("%s\n", &b);

        if (a >= 65 && a <= 90) {
            a = a + 32;
        //    printf("%c", a);
        }
        if (b >= 65 && b <= 90) {

            b = b + 32;
        }

/*      if (a == b)
        {
                c++;
                d++;
        }*/

        if (a != b) {
            return a - b;
        }
//      n--;
    }
    return 0;
}

void main() {
    char* a = (char*) malloc(100*sizeof(char));
    char* b = (char*) malloc(100*sizeof(char));
        int n;

    if (a == NULL || b == NULL)
    {
            return;
    }

    fgets(a, 100, stdin);
    fgets(b, 100, stdin);
    scanf("%d", &n);
    printf("%d\n", strncasecmp_own(a, b, n));
}
