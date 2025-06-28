main()
{
	char a[]="This is a Sample String Input",*p=a,*q=a;	      	     while(*p!='\0')
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
