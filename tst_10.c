#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*  int array[] = {2, 9, 7, 5, 15, 13, 1};*/

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    int tmp;

    printf("heapify i = %d l = %d r = %d largest = %d n = %d\n", i, l, r, largest, n);
    printf("heapify parent = %d left = %d, right = %d\n", arr[i], arr[l], arr[r]); 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
      printf("swap %d %d value %d %d\n", i, largest, arr[i], arr[largest]);
        tmp = arr[i];
	arr[i] = arr[largest];
	arr[largest] = tmp;
	// Recursively heapify the affected sub-tree
	heapify(arr, n, largest);
    }
}

/*  int array[] = {2, 9, 7, 5, 15, 13, 1};*/
void
hsort(int arr[], int n)
{
int i, cnt;
int tmp;
 
// Build heap (rearrange array)
    for (i = (n / 2) - 1; i >= 0; i--) {
        printf("calling heapify\n");
        heapify(arr, n, i);
    }
    printf("Extraction\n");
 // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
      // Move current root to end
      tmp = arr[0];
      arr[0] = arr[i];
      arr[i] = tmp;
      for (cnt = 0; cnt < i; cnt++)
	printf("%d ", arr[cnt]);
      printf("\n");
      
      // call max heapify on the reduced heap
      printf("calling extraction heapify\n");
      heapify(arr, i, 0);
      printf("after heapify\n");      
      for (cnt = 0; cnt < i; cnt++)
	printf("%d ", arr[cnt]);
      printf("\n");      
    }
}

int
main()
{
  int array[] = {2, 9, 7, 5, 15, 13, 1, 30};
  int i;
  
  hsort(array, 8);
  for (i = 0; i < 8; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
