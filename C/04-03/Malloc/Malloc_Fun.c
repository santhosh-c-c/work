void fun(int *a)
{
    a = (int*)malloc(sizeof(int));
}
 
int main()
{
    int *p;
    fun(p);
    *p = 6;
    printf("%d",*p);
}
