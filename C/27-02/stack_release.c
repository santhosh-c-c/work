int * fn()
{
//static int a=10;
int a=11;
printf("%d\n",a);
return &a;

}

main()
{
int *a;
a = fn();
printf("Hello");
//*a=20;
//printf("%d\n",*a);
}
