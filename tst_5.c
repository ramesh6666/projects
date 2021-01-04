#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int fib(n)
{
  if (n == 0)
      return 0;
  if (n == 1)
      return 1;
  return fib(n-1) + fib(n-2);
}


int
main()
{
  int n, i;

  printf("enter number: ");
  scanf("%d", &i);
  n = fib(i);
  printf("%d\n", n);
}
