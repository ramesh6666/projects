#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* quicksort with pivot */

void
swap(int *arr, int left, int right)
{
  int tmp;

  tmp = arr[left];
  arr[left] = arr[right];
  arr[right] = tmp;
}

int
partition(int *arr, int left, int right, int pivot)
{
  while (left <= right) {
    while (arr[left] < pivot)
      left++;
    while (arr[right] > pivot)
      right--;
    if (left <= right) {
      swap(arr, left, right);
      left++;
      right--;
    }
  }
  return left;
}

int count = 0;

void
qusort(int *arr, int left, int right)
{
  int index;
  int pivot;
  
  count++;
  if (left >= right)
    return;
  pivot =  (arr[left] + arr[right]) / 2;
  index = partition(arr, left, right, pivot);
  qusort(arr, left, index - 1);
  qusort(arr,  index, right);
  return;
}

/*int array[] = {1, 13, 11, 9, 7, 5, 30, 15, 21};*/
int array[] = {1, 2, 3, 4, 5};

int
main()
{
  int i, right;

  right = sizeof(array) / sizeof(int);;
  for (i = 0; i< right; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  qusort(array, 0, right - 1);
  for (i = 0; i< right; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  printf("count = %d\n", count);
}
