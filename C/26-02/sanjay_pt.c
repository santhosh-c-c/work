main()
{
	int a=0x12345678;
	int* p=&a;
	char* cp = p;
       printf("%x - %p\n", *p, p);	
       printf("%x - %p\n", *(p+1), p+1);	
       printf("%x - %p\n", *cp, cp);	
       printf("%x - %p\n", *(cp+1), cp+1);	
       printf("%x - %p\n", *(cp+2), cp+2);	
       printf("%x - %p\n", *(cp+3), cp+3);	



}
