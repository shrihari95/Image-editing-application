// You must modify this file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bmp.h"
#include "filter.h"
// -------------------------------------------------------------
int main(int argc, char * * argv)
{
  if (argc != 4) {
    fprintf(stderr, "Usage ./validate actual.bmp expected.bmp\n");
    return EXIT_FAILURE;
  }
  FILE *x = fopen(argv[1], "r");
  BoxFilter *y =  readFilter(x);
  FILE * r1 = fopen(argv[2], "r");
  BMPImage * img = readImage(r1);
  BMPImage * b = apply(img,* y);
  FILE * w1 = fopen(argv[3], "w");
  writeImage(b,w1);
  fclose(r1);
  fclose(w1);
  freeImage(img);
  freeImage(b);

  return EXIT_SUCCESS;
}