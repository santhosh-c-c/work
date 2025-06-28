#include <string.h>
#include <stdio.h>

main()
{
	/*char a[]="abc173def";
	char b[]="abc1lll3ldef";

        printf("%s\n",strtok(a,"123"));
        printf("%s\n",strtok(NULL,"123"));
        //printf("%s\n",strtok(NULL,"l"));
        printf("%s\n",strtok(b,"lll"));
        printf("%s\n",strtok(NULL,"l"));
*/
	char z[]="aaaaabc173daef";
        printf("%s\n",strtok(z,NULL));
        printf("%s\n",strtok(z,"a"));
	printf("%s\n",z);


}
