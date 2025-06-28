
//#line 2000 "pp.c"
#define MAX 0
#define sq(a) a*a
//#line 2000 "pp.c"
main()


{
#if MAX
	printf("1 HELLO");
#define int char
#else
	printf("2 HELLO");
#define int long
#endif
	printf("\n%d\n",__LINE__);
#line 2000 "pp.c"
	printf("%d\n",__LINE__);
	printf("%d\n",__LINE__);
	printf("%d\n",sq(6+1));
	int b;
	printf("%p\n",&b);
}
