main()
{
        char ptr[100];
   	printf("Plz Enter a string : ");
        scanf("%[^\n]s",ptr);
	char *count=ptr;
	while(*count!= '\0')
	{
		count++;
	}
	while(count != ptr)
	{
		if(*count == ' ')
		{
			printf("%s", count+1);
			*count = '\0';
			printf(" ");
		}
		count--;
	}
			printf("%s",count);
printf("\n");	
}
