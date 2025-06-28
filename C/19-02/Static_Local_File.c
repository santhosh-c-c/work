#include"Local_File.c"
int a=50;
void main()
{
//	static char c;
	fn();
	printf("From main : %d\n",c);
	c++;
	printf("From main after update : %d\n",c);
	fn();
}
