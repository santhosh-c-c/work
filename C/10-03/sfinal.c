char * sandy(char * str, char* sub)
{
	static * ptr=0;
	char *base2 = str;
        if(sub=='\0')
        {
                char *l=ptr;
                while(*l!='\0')
                {
               		str = base2;
                	while(*str != '\0' && *str != *l)
                	{
                        	str++;
                	}
                	while(*l == *str)
                	{
                        	*l = '\0';
                        	str ++;
				l++;
                	}
			int test = ptr;
			ptr = l;
			return base;
                	l++;
        	return 0;
       		}
	}
	else{
	char * base = sub;
	while(*sub != '\0')
	{
	str = base2;
		while(*str != '\0' && *str != *sub)
		{
			str++;
		}
		while(*sub == *str)
		{
			*sub = '\0';
			sub++;
			str++;
			ptr = sub+1;
		}
		return base;
		sub++;
	}
	return 0;
}
}

main()
{
char *p = malloc(sizeof(char)*100);
char *j = malloc(sizeof(char)*100);

printf("Enter the string : ");
gets(p);
printf("Enter the spacing element : ");
gets(j);

printf("%s\n",sandy(j,p));
printf("%s\n",sandy("123",'\0'));
}
