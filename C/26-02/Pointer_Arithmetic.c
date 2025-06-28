main()
{
int a=12,b=33,c=64;

int *p1=&a, *p2=&b, *p3=&c;
printf("%p\n",p1);
//printf("%d-%p\n",*p1++,p1);
//printf("%d-%p\n",*++p1,*p1);
//printf("%d-%p\n",++*p1,*p1);

printf("%p\n",p2);
//printf("%d-%p\n",*p2++,*p2);
printf("%d-%p\n",*++p2,p2);
//printf("%d-%p\n",++*p2,*p2);


printf("%p\n",p1);
printf("%d-%p\n",++*++p1++,p1);
}

