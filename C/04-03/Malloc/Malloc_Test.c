main()
{
	//char *p=(char *)malloc(10*(sizeof(char)));
	char *p=malloc(10*(sizeof(char)));
	//p="Hello World Sample Text";
	scanf("%10[^\n]s\n",p);
	char *d=malloc(10*(sizeof(char)));
	printf("%p\n",p);
	//*p="q";
	printf("%s\n",p);
	printf("%s\n",d);
	free(p);
}
