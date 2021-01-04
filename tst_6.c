#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *dictionary[] = {"hell", "hello", "on", "now"};

int
in_dictionary(char *str)
{
  int i;
  
  for (i = 0; i < 4; i++) { 
    if (strcmp(dictionary[i], str) == 0)
          return 1;
  }
  return 0;
}
  
int
split(char *str)
{
  int i;
  char substr[11];

  memset(substr, 0, 11);
  
  for (i = 0; i<strlen(str); i++) {
    memcpy(substr, str, i+1);
    substr[i+1] = 0;
    printf("substr =  %s\n", substr);
    if (in_dictionary(substr)) {
      printf("in_dictionary %s\n", substr);
      if (i + 1 == strlen(str))
	return 1;
      memcpy(substr, str + i + 1, 10 - (i+1));
      if (split(substr))
	return 1;
    }
  }
  return 0;
}

int
main()
{
  int n;
  char str[] = "hellonow";
  
  n = split(str);
  printf("can split = %d\n", n);
}
