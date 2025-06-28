#define a(x) b(#x)
#define b(y) #y
main()
{
	printf("1 - %s\n",a(HELLO));
	printf("2 - %s\n",a("HELLO"));
}
