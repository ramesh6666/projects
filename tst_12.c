#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main()
{
  char y[] = {'a', 'b', 'c'};
  int  x[3][2] = {{1,2}, {2,3}, {3,4}};
  int i, j;

  for (i = 0; i < 3; i++)
    for (j = 0; j<2; j++)
      printf("%d\n", x[i][j]);
}
