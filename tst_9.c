#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* insert value into tree using recursion */

int
insert(int *arr, int value, int start, int end, int totallen)
{
  int middle = (start + end) /2;
  int ret = 0;
  
  printf("start = %d, end = %d\n", start, end);
  if (start + 1 == end && value >= arr[start] && value <= arr[end]) {
      memcpy(arr + end + 1, arr + end, (totallen - end) * sizeof(int));
      arr[end] = value;
      return 1;
  }
  if (start == end) {
    if (value <= arr[start]) {
      memcpy(arr + start + 1, arr + start, (totallen - start) * sizeof(int));
      arr[start] = value;
      return 1;
    } else {
      arr[end + 1] = value;
      return 1;
    }
  }
  if (value >= arr[start] && value <= arr[middle] || value < arr[start])
    ret = insert(arr, value, start, middle, totallen);
  else
    ret = insert(arr, value, middle + 1, end, totallen);
  return 0;
}

int
main()
{
  int *arr = malloc(sizeof(int) * 9);
  int array[] = {2, 5, 7, 9, 11, 15, 30, 40};
  int i;
  
  memcpy((int*)arr, (int *)array, sizeof(int) * 8);
  insert(arr, 50, 0, 7, 8);
  for (i = 0; i < 9; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
