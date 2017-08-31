#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
//typedef int make_iso_compilers_happy;
#ifndef READIMAGE_OFF
BMPImage * readImage(FILE * fp) {

// FILL IN

	BMPImage *a = malloc(sizeof(BMPImage));
	int i = 0;
	Pixel * * new_pixels;
	fread(&(a->header), sizeof(a->header), 1, fp);
	 int32_t width = (a->header).width_px;
	 int32_t height = (a->header).height_px;
	 a->norm_height = abs((a->header).height_px);
	 new_pixels = malloc(abs(height) * sizeof(Pixel *));
	for (i = 0; i < abs(height); i++)
	{
 		new_pixels[i] = malloc(width * sizeof(Pixel));
	}
	for(int j = 0;j< abs(height); j++)
	{
		for(int k =0;k<abs(width);k++)
		{
			fread(&new_pixels[j][k], sizeof(new_pixels[j][k]), 1, fp);
		}
	}
	a->pixels = new_pixels;
	return a;
}

void freeImage(BMPImage * image) {
	
// FILL IN
	for (int i = 0; i < abs(image->header.height_px); i++) {
		free(image->pixels[i]);
	}
	
	//2. Free the "spine" of the array
	free(image->pixels);

	free(image);


}
#endif

#ifndef WRITEIMAGE_OFF
void writeImage(BMPImage * image, FILE * fp) {

// FILL IN
	fwrite(&(image->header), sizeof(image->header), 1, fp);
	for (int j=0;j<abs(image->header.height_px);j++)
	{
		for (int k = 0; k<abs(image->header.width_px);k++)
		{
			fwrite(&image->pixels[j][k], sizeof(image->pixels[j][k]), 1, fp);

		}
	}
}
#endif