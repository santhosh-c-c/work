 main()
{
  char* a=fn();
  *a=20;
  printf("%d\n",*a);
 
}
fn()
{
        char a=10;
	int *p=&a;
        return p;
}
