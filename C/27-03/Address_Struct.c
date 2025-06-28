main()
{
	struct p
	{
		unsigned int a,b;
		char c[1];
	}*ptr, z;
	ptr=&z;
	ptr -> a = 0x0000ff41;
	printf("%c - %x\n", *ptr, *ptr);
	printf("%c - %d\n", *ptr, ptr -> a);
	printf("%d - %d\n",sizeof(ptr), sizeof(*ptr));
	printf("%p - %p\n", &ptr, &ptr + 1);
	printf("%p - %p\n", ptr, ptr + 1);
}
//Use Assembly to Decode, each address is of 4 bytes, so when incremented by 1 it moves to next unit
