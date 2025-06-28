const a=10;
b=12;
main()
{
	int c=1;
	const int d=2;
	const static int e=3;
	printf("%d\n",a);
	printf("%p\n",&a);
	printf("%p\n",&b);
	printf("%p\n",&c);
	printf("%p\n",&d);
	printf("%p\n",&e);
	int * ptr = &e;
	*ptr = 2;
	printf("%p\n",&e);
}
f(int * a)
{
	printf("%p\n",a);
	*a=12;
}
