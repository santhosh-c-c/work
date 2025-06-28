#include <stdbool.h>
main()
{
	int a = 7;
	//bool b = (a & (1 << 2));
	bool b = (a >> 3) & 1;
	printf("%d\n",b);
	//printf("%d\n",sizeof(b));
}
