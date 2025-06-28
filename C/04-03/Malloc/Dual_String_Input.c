main()
{
	printf("Enter String - 1 Size: ");
	//scanf(""); 
     	char**str=malloc(2*5*sizeof(char));
       	scanf("%s",*str);
       	scanf("%s",*str+1);
       	//char *str[]={"World", "Hello"};
       	//char ** a=str;
	printf("%s\n",str[0]);
	printf("%s\n",(str[1]));

}

