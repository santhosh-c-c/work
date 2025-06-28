a;
a=10;
//a=20;
//b=a;
b;
main()
{
	char c[]="hello";
	//char *e ="hello";
	//char d[]=*e;
	//c="world";
	printf("%s\n",c);
	
	int * p=malloc(100);
	free(p);
	*p=10;	
	printf("%d\n",*p);
	//free(p);

}
