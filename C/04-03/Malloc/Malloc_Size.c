main()
{
	char *a=malloc(10*sizeof(char));
	printf("Enter A String : ");
	scanf("%[^\n]s",a);
	printf("%s\n",a+3);
}

