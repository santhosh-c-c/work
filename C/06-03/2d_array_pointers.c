main()
{
	char *a[2]={65,66,67,68,69,70},**p=a;
	//printf("%p\n",a);
	//printf("%p\n",p);
	//printf("%s\n",&a[1][1]);
	//printf("%c\n",a[1][1]);
	printf("%s\n",a[1]);
	printf("%s\n",a+1);
	//printf("%c\n",*(p+1));
	//printf("%c\n",*((p+1)+2));
}
