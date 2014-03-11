#include "stdafx.h"
#include "Histogram.h"
#include <iostream>

Histogram::Histogram(CImg<unsigned char> image){
	Histogram::image = image;
	total = image.height() * image.width();
	makeGray();
	equalizedImage = Histogram::image;
}

void Histogram::makeGray(){
	histogram10 = new int[10];
	histogram256 = new int[256];
	for (int i = 0; i < 10; i++){
		histogram10[i] = 0;
	}
	for (int i = 0; i < 256; i++){
		histogram256	[i] = 0;
	}
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			unsigned char lum = (unsigned char)(((unsigned char)image(c, r, 0, 0) * 0.30) + ((unsigned char)image(c, r, 0, 1) * 0.59) + ((unsigned char)image(c, r, 0, 2) * 0.11));
			image(c, r, 0, 0) = lum;
			image(c, r, 0, 1) = lum;
			image(c, r, 0, 2) = lum;
			histogram256[lum]++;
			histogram10[(int)((lum * 10) / 256)]++;
		}
	}
}

void Histogram::makeRed(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			//unsigned char lum = (unsigned char)(((unsigned char)image(c, r, 0, 0) * 0.30) + ((unsigned char)image(c, r, 0, 1) * 0.59) + ((unsigned char)image(c, r, 0, 2) * 0.11));
			//image(c, r, 0, 0) = lum;
			image(c, r, 0, 1) = 0;
			image(c, r, 0, 2) = 0;
		}
	}
}

void Histogram::equalize(){
	// histogram[0..#grey_values] is normalized histogram 
	
	cumulativeHistogram256 = new int[256];

	double alpha = (double)255 / (double)total;
	cumulativeHistogram256[0] = alpha*histogram256[0];

	for (int i = 1; i < 255; i++){
		cumulativeHistogram256[i] = cumulativeHistogram256[i - 1] + alpha*histogram256[i];
	}

	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			equalizedImage(c, r, 0, 0) = cumulativeHistogram256[image(c, r, 0, 0)];
			equalizedImage(c, r, 0, 1) = cumulativeHistogram256[image(c, r, 0, 1)];
			equalizedImage(c, r, 0, 2) = cumulativeHistogram256[image(c, r, 0, 2)];
		}
	}
	makeHistogramEqualized();
}
void Histogram::makeHistogramEqualized(){
	equalizedHistogram256 = new int[256];
	for (int i = 0; i < 256; i++){
		equalizedHistogram256[i] = 0;
	}
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			equalizedHistogram256[(int)equalizedImage(c, r, 0, 0)]++;
		}
	}
}

CImg<unsigned char> Histogram::getImage(){
	return image;
}

CImg<unsigned char> Histogram::getEqualizedImage(){
	return equalizedImage;
}

int* Histogram::getHistogram256(){
	return histogram256;
}

int* Histogram::getHistogram10(){
	return histogram10;
}

int* Histogram::getCumulativeHistogram256(){
	return cumulativeHistogram256;
}

int* Histogram::getEqualizedHistogram256(){
	return equalizedHistogram256;
}

int Histogram::getTotal(){
	return total;
}