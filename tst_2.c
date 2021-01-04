#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct interval {
  int beg;
  int end;
};

struct interval intvl[] =
  {{1, 5}, {3,7}, {4, 6}, {6, 8}};

struct interval out_intvl[4] = {0,0};

int
main(int argc, char ** argv)
{
  int num_elem = (int)sizeof(intvl) / (int)sizeof(struct interval);
  int i;

  out_intvl[0].beg = intvl[0].beg;
  out_intvl[0].end = intvl[0].end;

  for (i = 1; i < num_elem; i++) {
    if (intvl[i].beg >= intvl[i-1].beg && intvl[i].beg <= intvl[i-1].end) {
      out_intvl[0].end = intvl[i].end;
    }
  }
  printf ("%d %d\n", out_intvl[0].beg, out_intvl[0].end);
}

