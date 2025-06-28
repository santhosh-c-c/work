int main()
{
    char str1[] = "abcd";
    char str2[] = "123456789";
    printf("str 1 - %p\n",str1);
    printf("str 2 - %p\n",str2);
    puts("str1 before memcpy ");
    puts(str1);

    memmove(str1, str2, 4);


    printf("str 1 - %p\n",str1);
    printf("str 2 - %p\n",str2);

    puts("\nstr1 after memcpy ");
    puts(str1);
    puts("\nstr2 after memcpy ");
    puts(str2);

    return 0;
}
