main()
{int a=12,b=22,c=32,d=42,*p=&a;

char *ch =(char*)p+4;
printf("%p\n",c);
printf("%d-%p\n",*ch,ch);
}
