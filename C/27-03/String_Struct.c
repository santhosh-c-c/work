main()
{
	char *a[]={"Hello", "World", "Sample", "Text", "Linux"};
	
	struct pt
	{
		int a, b, c ;
	}*ptr;

	ptr=a+1;
	printf("%s\n", *(ptr+1));
}
