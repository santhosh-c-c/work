#include <stddef.h>
//#define sq(a) a*a
//#define sq(a) (a)*(a)
//#define merge(a,b) a##b
//#define str(x) #x
//#define a 1
//#define b 1
//#define c 1
//#undef c

//#define empty(x) printf("%d\n",x)
//#define empty1() printf("Test\n")


/*
 #define SUM(A,B) (\
		A+B\
		)
		*/
#define MACROO 3
//#define str(x,y) x##y
//#define str(x,y) x y

//#define fn(a,b,c) a+b+c
//#define fn(a,b) a+b

main()
{
	//printf("%d\n",sq(2+2));
	//char ab=10;
	//printf("%d\n",merge(a,b));
	//printf("%s\n",str(Sample Text));
	//#if a+b == 2
	//printf("True\n");
	//#else
	//printf("False\n");
	//#endif
int a =1;	
#define a 1
	//#ifdef MACROO==1
//	#if (MACROO+a == 3)
//	printf("True\n");
//	#else
//	printf("False\n");
//	#endif
	
	//#if c
	//printf("Defined\n");
	//#endif
	

	//printf("%d\n",__LINE__);
	//printf("%s\n",__FILE__);
	
	//empty(NULL);
	//empty('\0');
	//empty(0);
	//empty1();
	
	//printf("%d\n",SUM(10,5));
	//printf("%s\n",str("Hello","World"));
	
	
	//printf("%d\n",fn(2,8));
	//printf("%d\n",fn(2,5,3));
#ifdef __LINE__	
	printf("%d\n",__STDC_VERSION__);
#endif
}


