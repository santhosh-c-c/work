main()
{
	int a=65;
	//char * ptr = "Hello";
	int * p=0xfffdd63c;
	//printf("%p\n",ptr);
	printf("%p\n",&a);
	printf("%d\n",*(int *)(0xaaafffdd63c));
	printf("%d\n",*p);
}
