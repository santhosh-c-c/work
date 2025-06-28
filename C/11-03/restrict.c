main()
{
        char  b=20;
        char  c=25;
        char * restrict p= &b;
        b = 20;
	p=&c;
	*p=100;
        char * alt = &b;
        printf("a %d\n",b);
        printf("a %p\n",&b);
        printf("p %d\n",*p);
        printf("p %p\n",p);
        printf("alt %d\n",*alt);
        printf("alt %p\n",alt);
}
