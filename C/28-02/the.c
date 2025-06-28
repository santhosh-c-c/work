main()
{
char string[]=" Write a Bash script that is is is creates a directory named documents and navigates into it. Inside this directory, create three text files with different names and add sample text to each. List all files in long format and search for a specific word inside all the text files. Find files that are larger than 500 bytes and check their file types. Copy one of the files to another name and move the copied file to a new directory named backup. Modify the permissions of a file to allow only the owner to read and write. Display the contents of one of the files, dump it in hexadecimal format, and delete one of the files. Finally, show the most recent commands executed in the terminal.";
        char is[]={' ','i','s',' ','\0'};
        char the[]={' ','t','h','e',' ','\0'};
        char *ptr = string,a=0,b=0,is_ctr=0,the_ctr=0;
        while(*ptr !='\0')
        {
                //printf("*ptr - %c\n",*ptr);
                if(*ptr == is[a])
                {
                       //printf("*ptr - %c == is[a] - %c, a-%d\n",*ptr,is[a],a);
                        a++;
                        if(is[a]=='\0')
                        {
                                is_ctr++;
                                //printf("is_ctr - %d\n",is_ctr);
                                a=1;
                        }
                }
                else
                {
                        a=0;
                }
                if(*ptr == the[b])
                {
                        //printf("*ptr - %c == is[a] - %c, a-%d\n",*ptr,is[a],a);
                        b++;
                        if(the[b]=='\0')
                        {
                                the_ctr++;
                          	//printf("is_ctr - %d\n",is_ctr);
                                b=1;
                        }
                }
                else
                {
                        b=0;
                }
                ptr++;
        }
printf("is Count : %d\n",is_ctr);
printf("the Count : %d\n",the_ctr);
}

