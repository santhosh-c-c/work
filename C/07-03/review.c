main()
{
/*char *a[3] = {"hell","wr","rwe"};
*/char **b = {"hell","wr","rwe"};
char c[][3] = {"hell","wr","ui"};
/*printf("a %s\n",a);
printf("a %s\n",a[0]);
printf("a %s\n",*(a+1));
printf("a %s\n",a+1);
printf("b %s\n",b);
//printf("%s\n",b[0]);
//printf("%s\n",*(b+1));
//printf("%s\n",b+1); 
*/printf("c %s\n",c);
printf("c %s\n",c[1]);
printf("c %s\n",&(*(*(c+2)+1)));
printf("c %s\n",c+1);
}

