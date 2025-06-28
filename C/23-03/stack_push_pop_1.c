static i, *arr[10];

struct pwm {
        void *next;
        char duty;
        char b;
};

push(char a, char d)
{
	struct pwm * po;
	if(!i)
	{
		arr[i] = malloc(sizeof(struct pwm));
	}
	po = arr[i];
	po -> duty=a;
	po -> b=d;
	
	arr[i+1]=malloc(sizeof(struct pwm));

	po -> next = arr[i+1];
	i++;	
}


pop()
{
	free(arr[i]);
	i--;
}

main()
{
	push(1,2);
	struct pwm * po=arr[i-1];
	printf("%d\n",po -> duty);
	printf("%d\n",po -> b);
	pop();
	po=arr[i];
	printf("%d\n",po -> duty);
	printf("%d\n",po -> b);
	push(5,8);
}
