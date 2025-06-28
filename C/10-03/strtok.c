#include<string.h>
main()
{
char a[]="Hello World name it";
char * p = strtok(a, "e");
printf("%s\n",p);

p = strtok(a, "d");
printf("%s\n",p);
p = strtok(NULL, "e");
printf("%s\n",p);
}
