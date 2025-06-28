#include <stdio.h>
#include <strings.h>

int main(void)
{
  char *str1 = "aelo";
  char *str2 = "aELO";
  int result;

  result = strncasecmp(str1, str2, -4294967295);
	printf("%d\n",result);
  if (result == 0)
    printf("Strings compared equal.\n");
  else if (result < 0)
    printf("\"%s\" is less than \"%s\".\n", str1, str2);
  else
    printf("\"%s\" is greater than \"%s\".\n", str1, str2);

  return 0;
}

