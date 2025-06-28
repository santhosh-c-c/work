static int a=10;
static int fn(int a)
{
static int b=10;
b=a;
return b;
}
main()
{
	printf("%d\n%d\n",fn(5),fn(6));
}
