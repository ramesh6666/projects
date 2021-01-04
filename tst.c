#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s(char *);

union data {
  float f;
  int i;
  double d;
};

union data datavar;

int
main(int argc, char ** argv)
{
  char x[] = "laser";
  int i, j;
  char *y;
  
  i = s(x);
  printf("%d\n", i);
  y = (char *)malloc(i);
  for (j = 0; j<i; j++) {
    y[j] = x[i - j - 1 ];
  }
  printf("%s\n", x);
  printf("%s\n", y);
  printf("sizeof data %d\n", (int) sizeof(datavar));
  printf("sizeof char* %d\n", (int) sizeof(char *));
  printf("sizeof int %d\n", (int) sizeof(int));
  printf("sizeof ul %d\n", (int) sizeof(unsigned long*));
  printf("sizeof float %d\n", (int) sizeof(float));
  printf("sizeof double %d\n", (int) sizeof(double));
}

int
s(char *y)
{
  return strlen(y);
}
