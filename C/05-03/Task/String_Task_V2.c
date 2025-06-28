main()
{
	//char a[]="This is a Sample String Input",*p=a,*q=a;	      	     
	char *p=malloc(100),*q=p;	      	     
	printf("Plz Enter A String : ");
	scanf("%[^\n]s",p);
	printf("%s\n",p);
	printf("%s\n",q);
	while(*p!='\0')
	{
		if(*p==' ')
		{
			*p='\0';
			printf("%s\n",q);
			q=p+1;
		}
		p++;
	}
			printf("%s\n",q);

}
