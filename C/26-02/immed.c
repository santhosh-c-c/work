main()
{
	int a=12;
	printf("%p\n",&a);
	int* b=0xfffdd63c;
*b=13;
printf("%d\n",a);

}
