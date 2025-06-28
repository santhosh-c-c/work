static int b=256;
extern int a=50;
static char fn( int a)
{	printf("%d\n",a);
	return b;
}
main()
{
fn1();
a = 12;
printf("%d\n",fn(4));
fn(5);
fn(6);
fn(7);
}
fn1()
{
	printf("%d\n",a);
}

