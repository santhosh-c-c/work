int funcx(int x)
{
        int a;
        printf("\n%d, %p",a,&a);
        a=x+29;
        printf("\n%d, %p", a,&a);
        para();
}
int func(int x)
{   
           int a;
           printf("\n%d, %p",a,&a);
           funcx(0);
           a=x+29;
           printf("\n%d, %p",a,&a);
           funcx(0);
}   
void para()
{
int b;
printf("\n%d ,%p", b ,&b);
}
int main()
{
        int a;
        printf("\n%d, %p",a,&a);
        func(3);
        funcx(5);
        para();
}
