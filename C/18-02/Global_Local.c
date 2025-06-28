int a=1;
main()
{
//	int a=10;
	{
		int a = 15;
		printf("%d Inside\n",a);
		{   
                	printf("%d Local\n",a);
		}

	}
	printf("%d Outside\n",a);
	{	
		printf("%d Global\n",a);
	}
}
