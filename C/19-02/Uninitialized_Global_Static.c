char a;
char b=10;
void main()
{

	printf("Unitialized Global : %d\n",a);
	printf("Initialized Global : %d\n",b);
f();
}
f()
{
//	static char a=0;
	printf("From Fn : %d\n",a);
	a++;
	printf("After Upd : %d\n",a);
}
g()
{
	static char b;
	printf("Uninitialized : %d\n",b);
}
