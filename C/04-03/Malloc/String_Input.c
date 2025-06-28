main()
{
	char *a=malloc(15*sizeof(char));
	
	printf("Plx Enter a String : ");
	scanf("%s",a);
	
//	printf("Plx Enter a String : ");
	scanf("%s",a+6);
	
//	printf("Plx Enter a String : ");
	scanf("%s",a+11);
	
	printf("Output : %s\n",a);
	printf("Output : %s\n",a+6);
	printf("Output : %s\n",a+11);
	printf("Output : %s\n",a);
}
