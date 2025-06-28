l1()
{
	int a;	
	printf("\n---------l1---------\n");
	printf("l1 Var : %d, Add : %p\n",a ,&a);
	a=20;
	printf("l1 Var : %d, Add : %p\n",a ,&a);
	l2();	
	l2();
	l3();
}
l2()
{
	int b;	
	printf("\n---------l2---------\n");
	printf("l2 Var : %d, Add : %p\n",b ,&b);
	b=10;
	printf("l2 Var : %d, Add : %p\n",b ,&b);
	l3();
}
l3()
{ 
	printf("\n---------l3---------\n");
	int a;
	printf("l3 Var : %d, Add : %p\n",a ,&a);
}
void main()
{
	int c;
	printf("m Var : %d, Add : %p\n",c,&c);
	c=25;    
	printf("m Var : %d, Add : %p\n",c,&c);
	l1();
	printf("\n--------m-----------\n");
	l1();
	printf("\n--------m-----------\n");
	l2();
	printf("\n--------m-----------\n");
	l1();
	l3();
}
