#include <stdlib.h>
#include <stdio.h>
#include "filter.h"

#ifndef BLUR_OFF
BMPImage * blur(BMPImage * image) {

//FILL IN	
	BMPImage *a = malloc(sizeof(BMPImage));
	a->header = image->header;
	uint32_t val_blue = 0;
	uint32_t val_green = 0;
	uint32_t val_red = 0;
	a->norm_height = abs((image->header).height_px);
	int32_t height = abs(image->header.height_px);
	int32_t width = abs(image->header.width_px);
	a->pixels = malloc(abs(height) * sizeof(Pixel *));
		for (int w = 0; w < abs(height); w++)
		{
 			a->pixels[w] = malloc(width * sizeof(Pixel));
		}
	for (int j=0;j<abs(height);j++)
		{
			for (int k = 0; k<abs(width);k++)
			{
				val_blue = findPixel(image,j,k).blue + findPixel(image,j-1,k-1).blue + findPixel(image,j-1,k).blue + findPixel(image,j-1,k+1).blue + findPixel(image,j,k-1).blue + findPixel(image,j,k+1).blue + findPixel(image,j+1,k-1).blue + findPixel(image,j+1,k).blue + findPixel(image,j+1,k+1).blue;
				val_green = findPixel(image,j,k).green + findPixel(image,j-1,k-1).green + findPixel(image,j-1,k).green + findPixel(image,j-1,k+1).green + findPixel(image,j,k-1).green + findPixel(image,j,k+1).green + findPixel(image,j+1,k-1).green + findPixel(image,j+1,k).green + findPixel(image,j+1,k+1).green;
				val_red = findPixel(image,j,k).red + findPixel(image,j-1,k-1).red + findPixel(image,j-1,k).red + findPixel(image,j-1,k+1).red + findPixel(image,j,k-1).red + findPixel(image,j,k+1).red + findPixel(image,j+1,k-1).red + findPixel(image,j+1,k).red + findPixel(image,j+1,k+1).red;
				val_red = val_red / 9;
				val_green = val_green/9;
				val_blue = val_blue / 9;
				if(val_blue >255) val_blue = 255;
				if(val_green >255) val_green = 255;
				if(val_red >255) val_red = 255;
				a->pixels[j][k].red = (val_red );
				a->pixels[j][k].green = (val_green );
				a->pixels[j][k].blue = (val_blue);
				a->pixels[j][k].alpha = 255;
			}
			
		}
	return a;

}
#endif

// EXTRA CREDIT START
BMPImage * apply(BMPImage * image, BoxFilter f) {

//FILL IN
	BMPImage *a = malloc(sizeof(BMPImage));
	a->header = image->header;
	int32_t  val_blue = 0;
	int32_t   val_green = 0;
	int32_t  val_red = 0;
	int32_t  val_alpha = 0;
	a->norm_height = abs((image->header).height_px);
	int32_t height = abs(image->header.height_px);
	int32_t width = abs(image->header.width_px);
	a->pixels = malloc(abs(height) * sizeof(Pixel *));
		for (int w = 0; w < abs(height); w++)
		{
 			a->pixels[w] = malloc(width * sizeof(Pixel));
		}
	for (int j=0;j<abs(height);j++)
		{
			for (int k = 0; k<abs(width);k++)
			{
				val_blue = (f.filter[1][1]*findPixel(image,j,k).blue) + (f.filter[0][0]*findPixel(image,j-1,k-1).blue) +  (f.filter[0][1]*findPixel(image,j-1,k).blue) +  (f.filter[0][2]*findPixel(image,j-1,k+1).blue) +  (f.filter[1][0]*findPixel(image,j,k-1).blue) +  (f.filter[1][2]*findPixel(image,j,k+1).blue) +  (f.filter[2][0]*findPixel(image,j+1,k-1).blue) +  (f.filter[2][1]*findPixel(image,j+1,k).blue) +  (f.filter[2][2]*findPixel(image,j+1,k+1).blue);
				val_green = (f.filter[1][1]*findPixel(image,j,k).green) + (f.filter[0][0]*findPixel(image,j-1,k-1).green) +  (f.filter[0][1]*findPixel(image,j-1,k).green) +  (f.filter[0][2]*findPixel(image,j-1,k+1).green) +  (f.filter[1][0]*findPixel(image,j,k-1).green) +  (f.filter[1][2]*findPixel(image,j,k+1).green) +  (f.filter[2][0]*findPixel(image,j+1,k-1).green) +  (f.filter[2][1]*findPixel(image,j+1,k).green) +  (f.filter[2][2]*findPixel(image,j+1,k+1).green);
				val_red = (f.filter[1][1]*findPixel(image,j,k).red) + (f.filter[0][0]*findPixel(image,j-1,k-1).red) +  (f.filter[0][1]*findPixel(image,j-1,k).red) +  (f.filter[0][2]*findPixel(image,j-1,k+1).red) +  (f.filter[1][0]*findPixel(image,j,k-1).red) +  (f.filter[1][2]*findPixel(image,j,k+1).red) +  (f.filter[2][0]*findPixel(image,j+1,k-1).red) +  (f.filter[2][1]*findPixel(image,j+1,k).red) +  (f.filter[2][2]*findPixel(image,j+1,k+1).red);
				val_alpha = (f.filter[1][1]*findPixel(image,j,k).alpha) + (f.filter[0][0]*findPixel(image,j-1,k-1).alpha) +  (f.filter[0][1]*findPixel(image,j-1,k).alpha) +  (f.filter[0][2]*findPixel(image,j-1,k+1).alpha) +  (f.filter[1][0]*findPixel(image,j,k-1).alpha) +  (f.filter[1][2]*findPixel(image,j,k+1).alpha) +  (f.filter[2][0]*findPixel(image,j+1,k-1).alpha) +  (f.filter[2][1]*findPixel(image,j+1,k).alpha) +  (f.filter[2][2]*findPixel(image,j+1,k+1).alpha);
		
				val_red = val_red / f.norm;
				val_green = val_green/f.norm;
				val_blue = val_blue / f.norm;
				val_alpha = val_alpha / f.norm;
				if(val_blue <0) val_blue = 0;
				if(val_green<0) val_green = 0;
				if(val_red <0) val_red = 0;
				if(val_alpha <0) val_alpha = 0;
				if(val_blue >255) val_blue = 255;
				if(val_green >255) val_green = 255;
				if(val_red >255) val_red = 255;
				if(val_alpha >255) val_alpha = 255;
				a->pixels[j][k].red = (val_red );
				a->pixels[j][k].green = (val_green );
				a->pixels[j][k].blue = (val_blue);
				a->pixels[j][k].alpha = (val_alpha);
			}
			
		}
	return a;

}

BoxFilter * readFilter(FILE * infile) {
	
//FILL IN
	BoxFilter *fil = malloc(sizeof(BoxFilter));
	int boxfil[3][3];
	float y;
	for(int j = 0;j< 3; j++)
	{
		for(int k =0;k<3;k++)
		{
			fscanf(infile, "%d ",&boxfil[j][k]);
			fil->filter[j][k] = boxfil[j][k];
		}
	}
	fscanf(infile,"%f",&y);
	fil->norm = y;
	

return fil;

}


// EXTRA CREDIT END


Pixel findPixel(BMPImage * image,int j, int k)
{
	if(j<0)
		j = 0;
	if(j>=abs(image->header.height_px))
		j = abs(image->header.height_px) - 1;
	if(k<0)
		k = 0;
	if(k>=abs(image->header.width_px))
		k = abs(image->header.width_px)-1;
	return image->pixels[j][k];
}