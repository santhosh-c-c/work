main()
{
	char a[]="Sample Text Hello World Code";
	char *p=(char *)malloc(5*sizeof(char));
	char *t=(char *)malloc(5*sizeof(char));
	char *y=(char *)malloc(5*sizeof(char));
	char *o=(char *)malloc(5*sizeof(char));
//	p="Sample Text Hello World";
	p=a;
	printf("%s\n",p);
	*(p+1)='i';
	printf("%s\n",p);
	printf("Ptr : %d - String : %d\n",sizeof(p),sizeof(a));
	printf("\np : %p - t : %p - y : %p - o : %p\n\n",p,t,y,o);
}
