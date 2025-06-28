main()
{
	char **a=malloc(2*(sizeof(char *)));
	//char *a[2];

	
	//*a = (char*) malloc(11*sizeof(char));
	//*(a+1) = (char*) malloc(11*sizeof(char));

	a[0] = (int*) malloc(5*sizeof(char));
	a[1] = (int*) malloc(5*sizeof(char));

	printf("Plx Enter String 1 of 10 char : ");
	scanf("%d", a[0]);
	//scanf("%d",&q);
	printf("Plx Enter String 2 of 10 char : ");
	scanf("%s", a[1]);
//printf("%s\n",a[1]);
printf("%p\n",*a+4);
//printf("%d-%p\n",a[1],a[1]);
































	//	printf("First String - %s\n", a[0]);
//	printf("Second String - %d\n", *(*(a+1)+6));
//	printf("A[0] - %p\n", a[0]);
//	printf("A[1] - %p\n", a[1]); 
/*char *a="Hello";
printf("%c\n",*a+1);
printf("%c\n",*(a+1));

*/
free(a);
}
