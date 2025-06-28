main()
{
	int volatile a=0;
	int b=12;
	int *ptr=&a;
//	while(*ptr==0);
printf("%p\n",&a);
printf("%p\n",&b);

}
