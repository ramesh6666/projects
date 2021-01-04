#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*merge sort */

void
mergehalves(int *arr, int *tmparr, int leftstart, int rightend)
{
  int leftend = (leftstart + rightend) / 2;
  int rightstart = leftend + 1;
  int num_elem = rightend - leftstart + 1;
  int size = num_elem * sizeof(int);
  int left = leftstart;
  int right = rightstart;
  int index = leftstart;
  int i;
  
  if (leftstart == 3 && rightend == 4) 
    printf("left = %d leftend = %d right = %d rightstart = %d\n", left, leftend, right, rightstart);
  while (left <= leftend && right <= rightend) {
    if (arr[left] <= arr[right]) {
      tmparr[index] = arr[left];
      left++;
    } else {
      tmparr[index] = arr[right];
      right++;
    }
    index++;
  }
  if (leftstart == 3 && rightend == 4) {
    printf("2nd time left = %d leftend = %d right = %d rightstart = %d\n", left, leftend, right, rightstart);
    printf("copying left %d right %d index = %d\n", leftend - left +1, rightend - right +1, index);
  }
  memcpy(tmparr + index, arr + left, leftend - left + 1);
  if (leftstart == 3 && rightend == 4)
    printf("after copy %d\n", tmparr[index]);    
  memcpy(tmparr + index, arr + right, rightend - right + 1);
  if (leftstart == 3 && rightend == 4) {
    printf("after copy %d\n", tmparr[index]);
    printf("after copy size = %d leftstart = %d\n", size, leftstart);
  }
  memcpy(arr + leftstart, tmparr + leftstart, size);
  if (leftstart == 3 && rightend == 4) {
      for (i = leftstart; i <= rightend; i++) 
          printf("mergehalves: %d ", arr[i]);
      printf("\n");
  }
}

int count = 0;

void
merges(int *arr, int *tmparr, int leftstart, int rightend)
{
  int middle = (leftstart + rightend) / 2;
  int i = 0;
  
  if (leftstart >= rightend)
    return;
  printf("merges A %d %d %d\n", leftstart, rightend, middle);
  merges(arr, tmparr, leftstart, middle);
  merges(arr, tmparr, middle + 1, rightend);
  count++;
  printf("merge halves %d %d \n", leftstart, rightend);  
  mergehalves(arr, tmparr, leftstart, rightend);
  for (i = leftstart; i <= rightend; i++) 
      printf("%d ", arr[i]);
  printf("\n");
}

int array[] = {1, 13, 11, 9, 7, 5, 30, 15, 21};
int tmparray[9] =  {0};

int
main()
{
  int i;

  merges(array, tmparray, 0, 8);
  printf("count = %d\n", count);
  for (i = 0; i< 9; i++)
    printf("%d ", array[i]);
  printf("\n");
}
