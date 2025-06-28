static char c=10;
void fn()
{
	extern a;
	printf("From copy : %d\n",c);
	printf("From copy, var frm main : %d\n",a);
}
