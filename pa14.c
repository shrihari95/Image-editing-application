#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "filterParallel.h"
#include "bmp.h"

int main(int argc, char * * argv)
{
  if (argc != 4) {
    fprintf(stderr, "Lol\n");
    return EXIT_FAILURE;
  }
  BoxFilter f;
  f.filter[0][0] = 1;
	f.filter[0][1] = 1;
	f.filter[0][2] = 1;
	f.filter[1][0] = 1;
	f.filter[1][1] = 1;
	f.filter[1][2] = 1;
	f.filter[2][0] = 1;
	f.filter[2][1] = 1;
	f.filter[2][2] = 1;
	f.norm = 9;
  FILE * r1 = fopen(argv[1], "r");
  BMPImage * img = readImage(r1);
  fseek(r1,0, SEEK_SET);
BMPImage *wri = readImage(r1);
 // FILE * r2 = fopen(argv[2], "r");
  //wri = readImage(r2);
apply(img, wri, f, atof(argv[3]));
FILE * fp = fopen(argv[2], "w");
writeImage(wri, fp);
fclose(r1);
fclose(fp);
return EXIT_SUCCESS;
}