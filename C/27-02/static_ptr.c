int * fn()
{
static char a=10;
static char b=11;
static char c=12;
static char d=13;
static char t=13;
        printf("%d-",a);
        printf("%p-a\n",&a);
        printf("%d-",b);
        printf("%p-b\n",&b);
        printf("%d-",c);
        printf("%p-c\n",&c);
        printf("%d-",d);
        printf("%p-d\n",&d);
        return &b;
}

main()
{
/*        int *a=fn();
        *a=0x00000102;
        fn();
        printf("%d\n",*a);
        printf("%p\n",a); */
}
