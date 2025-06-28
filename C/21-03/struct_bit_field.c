main()
{
	struct {
unsigned word0bit0: 1;
unsigned word1bit0: 1;
} bitset;
bitset.word0bit0=10;
bitset.word1bit0=5;
int temp;
temp = bitset.word0bit0; //0
printf("%d\n",temp); //0
temp = bitset.word1bit0; //1
printf("%d\n",temp); //1
}
