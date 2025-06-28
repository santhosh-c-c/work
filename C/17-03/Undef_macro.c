#define A 1
#define ISEQUAL(X, Y) X == Y
int main()
{
    #if ISEQUAL(bcX, 0)
        printf("True\n");
    #else
        printf("False\n");
    #endif
    #if ISEQUAL(A, 0)
        printf("True\n");
    #else
        printf("False\n");
    #endif

    #if B
	printf("Yes\n");
    #else
	printf("No\n");
    #endif
    return 0;
}

