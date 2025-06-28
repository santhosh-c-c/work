main()
{
	struct test
	{
		int a,b,c;
	}*ptr;
	char * p;
	int *p_i;
	printf("%d\n", sizeof(ptr));
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p_i));
	printf("%d\n", sizeof(*ptr));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(*p_i));
}
