main()
{
        char ptr[100];
        printf("Enter a string : ");
        scanf("%[^\n]s",ptr);
        char *count=ptr;
        while(*count!= '\0')
        {
                count++;
        }
	char rev_str[100];char i =0;
	while(count != ptr)
	{
		count--;
		rev_str[i] = *count;
		i++;
	}
	rev_str[i] = '\0';
	printf("%s\n", rev_str);
	count=rev_str;
        while(*count!= '\0')
        {
                count++;
        }
        while(count != rev_str)
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
