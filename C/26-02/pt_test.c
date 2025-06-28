main()
{
	int a=0x12345678;
	int *p=&a;
	char **pp=&p;
/*printf("%p\n",&a);
printf("%p\n",&p);
printf("%p\n",&pp);
*/

printf("%x\n",**pp);
printf("%x\n",**(pp+1));
printf("%x\n",**(pp+2));
printf("%x\n",**(pp+3));
/*
printf("%x\n",**pp);
printf("%x\n",**pp+1);
printf("%x\n",**pp+2);
printf("%x\n",**pp+3);
*
printf("%p\n",a);
printf("%p\n",p);
printf("%p\n",pp);
*/
//printf("%p,%p,%p,%p",)	
//printf("%d\n",sizeof(p));
//printf("%d\n",sizeof(pp));

}
