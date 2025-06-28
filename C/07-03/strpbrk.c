char * strpbrk_(char * str, char* sub)
{
char * base = sub;
while(*str != '\0')
{
sub = base;
while(*sub != '\0' && *sub != *str)
{
sub++;
}
if(*str == *sub)
{
return str;
}
str++;
}
return 0;
}

main()
{
char *p = "hellot wooll";
char *j = "Sandy @Linumiz";

char *ans = strpbrk_(p, j);
if(ans != '\0'){
printf("%c\n", *ans);
}
else
printf("%d\n", ans);
}

