main()
{
	//char a[][2]={65,66,67,68,69,70}, **b=a;
	char a='q',*p=&a;
	char **b={p,66,67,68,0};
	//char b[2][]={69,70,71,72,69,70};
	//**a="a";
	printf("%c\n",*b);
	//printf("%p\n",b+1);
	//printf("%p\n",a);
	//printf("%s\n",(a+2));
	//printf("%p\n",a[1]);
	//printf("%p\n",a[2]);
	//printf("%p\n",a[3]);
	//printf("%p \n",a);
	//printf("%p \n",&a);
	//printf("%c \n",((b+1)+1));
	//printf("%s \n",(a+1));
//
//
/*        2 3 4 5 6 7       30 40 50 60 70 80 90 100 110 120
        -------------      ---------------------------------
       0:   0 @ P ` p     0:    (  2  <  F  P  Z  d   n   x
       1: ! 1 A Q a q     1:    )  3  =  G  Q  [  e   o   y
       2: " 2 B R b r     2:    *  4  >  H  R    f   p   z
       3: # 3 C S c s     3: !  +  5  ?  I  S  ]  g   q   {
       4: $ 4 D T d t     4: "  ,  6  @  J  T  ^  h   r   |
       5: % 5 E U e u     5: #  -  7  A  K  U  _  i   s   }
       6: & 6 F V f v     6: $  .  8  B  L  V  `  j   t   ~
       7: ' 7 G W g w     7: %  /  9  C  M  W  a  k   u  DEL
       8: ( 8 H X h x     8: &  0  :  D  N  X  b  l   v
       9: ) 9 I Y i y     9: '  1  ;  E  O  Y  c  m   w
       A: * : J Z j z
       B: + ; K [ k {
       C: , < L \ l |
       D: - = M ] m }
       E: . > N ^ n ~
       F: / ? O _ o DEL
*/
}
