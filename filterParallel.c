#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "filterParallel.h"
#include "bmp.h"

void applyThread(BMPImage * imageIn, BMPImage * imageOut, BoxFilter f, int tid, int numThreads) {
	
	//FILL IN. This is the work that thread #tid should do
	//You may find it useful to know the number of threads (numThreads) to
	//figure out what to do.
	//imageOut = malloc(sizeof(BMPImage));
	imageOut->header = imageIn->header;
	int32_t  val_blue = 0;
	int32_t   val_green = 0;
	int32_t  val_red = 0;
	int32_t  val_alpha = 0;
	imageOut->norm_height = abs((imageIn->header).height_px);
	int32_t height = abs(imageIn->header.height_px);
	int32_t width = abs(imageIn->header.width_px);
	

	if(tid!=numThreads-1){
	for (int j=0;j<(abs(height));j++)
		{
			for (int k =(abs(width)/numThreads) * tid;k<((abs(width)/numThreads) * tid) + (abs(width)/numThreads);k++)
			{
				val_blue = (f.filter[1][1]*findPixel(imageIn,j,k).blue) + (f.filter[0][0]*findPixel(imageIn,j-1,k-1).blue) +  (f.filter[0][1]*findPixel(imageIn,j-1,k).blue) +  (f.filter[0][2]*findPixel(imageIn,j-1,k+1).blue) +  (f.filter[1][0]*findPixel(imageIn,j,k-1).blue) +  (f.filter[1][2]*findPixel(imageIn,j,k+1).blue) +  (f.filter[2][0]*findPixel(imageIn,j+1,k-1).blue) +  (f.filter[2][1]*findPixel(imageIn,j+1,k).blue) +  (f.filter[2][2]*findPixel(imageIn,j+1,k+1).blue);
				val_green = (f.filter[1][1]*findPixel(imageIn,j,k).green) + (f.filter[0][0]*findPixel(imageIn,j-1,k-1).green) +  (f.filter[0][1]*findPixel(imageIn,j-1,k).green) +  (f.filter[0][2]*findPixel(imageIn,j-1,k+1).green) +  (f.filter[1][0]*findPixel(imageIn,j,k-1).green) +  (f.filter[1][2]*findPixel(imageIn,j,k+1).green) +  (f.filter[2][0]*findPixel(imageIn,j+1,k-1).green) +  (f.filter[2][1]*findPixel(imageIn,j+1,k).green) +  (f.filter[2][2]*findPixel(imageIn,j+1,k+1).green);
				val_red = (f.filter[1][1]*findPixel(imageIn,j,k).red) + (f.filter[0][0]*findPixel(imageIn,j-1,k-1).red) +  (f.filter[0][1]*findPixel(imageIn,j-1,k).red) +  (f.filter[0][2]*findPixel(imageIn,j-1,k+1).red) +  (f.filter[1][0]*findPixel(imageIn,j,k-1).red) +  (f.filter[1][2]*findPixel(imageIn,j,k+1).red) +  (f.filter[2][0]*findPixel(imageIn,j+1,k-1).red) +  (f.filter[2][1]*findPixel(imageIn,j+1,k).red) +  (f.filter[2][2]*findPixel(imageIn,j+1,k+1).red);
				val_alpha = (f.filter[1][1]*findPixel(imageIn,j,k).alpha) + (f.filter[0][0]*findPixel(imageIn,j-1,k-1).alpha) +  (f.filter[0][1]*findPixel(imageIn,j-1,k).alpha) +  (f.filter[0][2]*findPixel(imageIn,j-1,k+1).alpha) +  (f.filter[1][0]*findPixel(imageIn,j,k-1).alpha) +  (f.filter[1][2]*findPixel(imageIn,j,k+1).alpha) +  (f.filter[2][0]*findPixel(imageIn,j+1,k-1).alpha) +  (f.filter[2][1]*findPixel(imageIn,j+1,k).alpha) +  (f.filter[2][2]*findPixel(imageIn,j+1,k+1).alpha);
		
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
				imageOut->pixels[j][k].red = (val_red );
				imageOut->pixels[j][k].green = (val_green );
				imageOut->pixels[j][k].blue = (val_blue); 
				imageOut->pixels[j][k].alpha = (val_alpha);
			}
			
		}
	return;
	}
	else if(tid==numThreads-1){
		for (int j=0;j<(abs(height));j++)
		{
			for (int k =(abs(width)/numThreads) * tid;k<(abs(width));k++)
			{
				val_blue = (f.filter[1][1]*findPixel(imageIn,j,k).blue) + (f.filter[0][0]*findPixel(imageIn,j-1,k-1).blue) +  (f.filter[0][1]*findPixel(imageIn,j-1,k).blue) +  (f.filter[0][2]*findPixel(imageIn,j-1,k+1).blue) +  (f.filter[1][0]*findPixel(imageIn,j,k-1).blue) +  (f.filter[1][2]*findPixel(imageIn,j,k+1).blue) +  (f.filter[2][0]*findPixel(imageIn,j+1,k-1).blue) +  (f.filter[2][1]*findPixel(imageIn,j+1,k).blue) +  (f.filter[2][2]*findPixel(imageIn,j+1,k+1).blue);
				val_green = (f.filter[1][1]*findPixel(imageIn,j,k).green) + (f.filter[0][0]*findPixel(imageIn,j-1,k-1).green) +  (f.filter[0][1]*findPixel(imageIn,j-1,k).green) +  (f.filter[0][2]*findPixel(imageIn,j-1,k+1).green) +  (f.filter[1][0]*findPixel(imageIn,j,k-1).green) +  (f.filter[1][2]*findPixel(imageIn,j,k+1).green) +  (f.filter[2][0]*findPixel(imageIn,j+1,k-1).green) +  (f.filter[2][1]*findPixel(imageIn,j+1,k).green) +  (f.filter[2][2]*findPixel(imageIn,j+1,k+1).green);
				val_red = (f.filter[1][1]*findPixel(imageIn,j,k).red) + (f.filter[0][0]*findPixel(imageIn,j-1,k-1).red) +  (f.filter[0][1]*findPixel(imageIn,j-1,k).red) +  (f.filter[0][2]*findPixel(imageIn,j-1,k+1).red) +  (f.filter[1][0]*findPixel(imageIn,j,k-1).red) +  (f.filter[1][2]*findPixel(imageIn,j,k+1).red) +  (f.filter[2][0]*findPixel(imageIn,j+1,k-1).red) +  (f.filter[2][1]*findPixel(imageIn,j+1,k).red) +  (f.filter[2][2]*findPixel(imageIn,j+1,k+1).red);
				val_alpha = (f.filter[1][1]*findPixel(imageIn,j,k).alpha) + (f.filter[0][0]*findPixel(imageIn,j-1,k-1).alpha) +  (f.filter[0][1]*findPixel(imageIn,j-1,k).alpha) +  (f.filter[0][2]*findPixel(imageIn,j-1,k+1).alpha) +  (f.filter[1][0]*findPixel(imageIn,j,k-1).alpha) +  (f.filter[1][2]*findPixel(imageIn,j,k+1).alpha) +  (f.filter[2][0]*findPixel(imageIn,j+1,k-1).alpha) +  (f.filter[2][1]*findPixel(imageIn,j+1,k).alpha) +  (f.filter[2][2]*findPixel(imageIn,j+1,k+1).alpha);
		
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
				imageOut->pixels[j][k].red = (val_red );
				imageOut->pixels[j][k].green = (val_green );
				imageOut->pixels[j][k].blue = (val_blue); 
				imageOut->pixels[j][k].alpha = (val_alpha);
			}
			
		}
	return;

	}
}

void * applyThreadWrapper(void * args) {
	ApplyArgs * applyArgs = (ApplyArgs *) args;
	fprintf(stdout, "calling thread %d\n", applyArgs->tid);
	
	applyThread(applyArgs->in, applyArgs->out, applyArgs->filter, applyArgs->tid, applyArgs->numThreads);
	
	fprintf(stdout, "finished with thread %d\n", applyArgs->tid);
	
	return NULL;
}

void apply(BMPImage * imageIn, BMPImage * imageOut, BoxFilter f, int numThreads) {

	//FILL IN:
	//numThreads = 2;
	ApplyArgs *x = malloc(sizeof(ApplyArgs)*numThreads);
	pthread_t * threads = malloc(sizeof(pthread_t) * numThreads);

	for (int i = 0; i < numThreads; i++) {
		//x.tid= i;
		x[i].tid = i;
		x[i].in = imageIn;
		x[i].out = imageOut;
		x[i].filter = f;
		x[i].numThreads = numThreads;
	}
	for (int i = 0; i < numThreads; i++) {
		//x.tid= i;
		pthread_create(&threads[i], NULL, applyThreadWrapper, &x[i]);
	}
	for (int i = 0; i < numThreads; i++) {
		pthread_join(threads[i], NULL);
	}
	//1. create numThreads threads, that each call applyThreadWrapper
	//2. wait for all threads to finish
	//3. clean up any memory allocation you did.
	free(x);
	free(threads);
	
} 
Pixel findPixel(BMPImage * imageIn,int j, int k)
{
	if(j<0)
		j = 0;
	if(j>=abs(imageIn->header.height_px))
		j = abs(imageIn->header.height_px) - 1;
	if(k<0)
		k = 0;
	if(k>=abs(imageIn->header.width_px))
		k = abs(imageIn->header.width_px)-1;
	return imageIn->pixels[j][k];
}