main(){
	int a=0xaabbccdd;
	int b=0xddcc7baa;
void * ptr=(int*) &a;
void * ptr2 = (char*)&b;
/*
*(ptr++);
*(ptr2++);
*/
printf("%x\n%x\n",*(int *)ptr,*(short *)ptr2);

}
