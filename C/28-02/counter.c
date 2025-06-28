main()
{
        int upper[26]={0};
        //int lower[26]={0};
	//Array of Char Pointer - TM
        
	char* a= "Hello", *b = "World";
	
//	char *c=malloc(100*sizeof(char));
//	char **p;	
//	char *e[2]={c,c+50};
//i	int *f[2];
	char *str[]={a, b};

	printf("%s\n", str[0]);
	printf("%s\n", str[1]);

/*	int a[2]={1,2};
	char *ptr=str,i=0;
        while(*ptr != '\0'){

                if(*ptr>='A' && *ptr <='Z')
                        ++upper[*ptr-65];
                else if(*ptr>='a' && *ptr <='z')
                        ++upper[*ptr-97];
                ptr++;
        }
	while(i<26){
	printf("%c-%d\n",'A'+i,upper[i]);
	i++;}*/

}
