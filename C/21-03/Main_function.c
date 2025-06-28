main()
{
	static a =5;
	printf("%d\n",a);
	a--;
	if(a)
	{
		main();
	}
}
