#include<stdio.h>
char * sandy(char *p,char r)
{
	int base=p;
	while(*p!='\0')
        {
                if(*p==r)
                {
                        *p='\0';
			return p+1;
		}
                p++;
        }
	return NULL;

			}
main()
{
        char *p=malloc(100),r;
        printf("\nPlz Enter A String : ");
        gets(p);
	printf("Plz Enter Spacing Element : ");
        scanf("%c",&r);
        char *pp=sandy(p,r);
	if(pp!=NULL){
	printf("%s\n",p);}
        char *ppp=sandy(pp,'t');
	if(pp!=NULL){
	printf("%s\n",pp);}
}
