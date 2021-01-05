#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int x[] = {1, 0, 2, 0, 4, 0, 3, 0};
<<<<<<< HEAD


=======
/* swap */
>>>>>>> 54e8a4ddd36a971f592ce9e1bbef485a6b5e8595
int
main(int argc, char ** argv)
{
  int i, j;
  int num_elem =  sizeof(x) / sizeof(int);
  
  for (i = 0; i<num_elem; i++) {
    if (x[i] != 0)
      continue;
    for (j = i-1; j >=0; j--) {
      if (x[j] != 0) {
	x[j+1] = x[j];
	x[j] = 0;
      } else {
	break;
      }
    }
  }
    for (i = 0; i < num_elem; i++) {
      printf("%d ", x[i]);
    }
}

