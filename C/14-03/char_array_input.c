main()
{
	char *p=malloc(10);
	p="./,!@#$%^&*(";
	//char a[]={*p};
	char a[]="!@#?";
	printf("%d\n",sizeof(a));
	printf("%c\n",a[0]);

}

