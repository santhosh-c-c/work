main()
{
	char * a=malloc(5*sizeof(char));
	char * b=malloc(5*sizeof(char));
	*a=10;
	printf("A : %d\n",*a);
	b=a;
	printf("A : %p\n",a);
	free(a);
	printf("FREED\n");
	printf("A : %p\n",a);
	printf("A : %d\n",*a);
	*a=20;
	printf("A : %d\n",*a);
	printf("B : %d\n",*b);

}
