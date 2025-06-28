void fn(int *p)
{
	*p=malloc(8);
}
main()
{
	void **a;
	fn(&a);

 	a[0] =  malloc(5*sizeof(char));
        a[1] =  malloc(5*sizeof(char));

        printf("Plx Enter String 1 of 10 char : ");
        scanf("%d", a[0]);
        printf("Plx Enter String 2 of 10 char : ");
        scanf("%s", a[1]);

	printf("%c\n",*((char *)*(a+1)+2));
}

