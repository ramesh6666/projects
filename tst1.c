#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*int x[] = {1, 0, 2, 0, 4, 0, 3, 0};*/
int x[] = {0, 0, 0, 0};

int
main(int argc, char ** argv)
{
  int j;
  int num_elem =  sizeof(x) / sizeof(int);
  int rindex = 0, windex = num_elem - 1;
  int i;

  for (rindex = num_elem - 1; rindex >= 0; rindex--) {
    if (x[rindex] == 0) {
      continue;
    }
    x[windex] = x[rindex];
    windex--;
  }
  printf("num_elem = %d, windex = %d\n", num_elem, windex);
  memset(x, 0,  sizeof(int) * (windex + 1));
  for (i = 0; i < num_elem; i++) {
      printf("%d ", x[i]);
  }
  printf("\n");
}

