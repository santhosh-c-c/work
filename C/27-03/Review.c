main()
{
	char a=10;
	char * ptr = &a;
	int * p = &a;
	int var = 0xfffddc90;
	printf("%d - %d\n", *ptr, *p);
	printf("Address : %p - %p\n", &ptr, &p);
	printf("Address + 1 : %p - %p\n", &ptr+1, (&p)+1);
	printf("Check : %p - %p\n", var, var+1);
}
