extern int a;
a=10;
char b;
static int fn(static int b)
{
static int c=b;
printf("%d\n",a);
return a;
}
main()
{
auto char d=3;
static char e=4;
register char f=5;
fn(5);
fn(6);
}

