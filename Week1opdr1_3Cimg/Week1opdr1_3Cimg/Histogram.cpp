
#include "stdafx.h"
#include "Histogram.h"
#include <iostream>

Histogram::Histogram(CImg<unsigned char> image){
	Histogram::image = image;
	total = image.height() * image.width();
	makeGray();
}

void Histogram::makeGray(){
	histogram10 = new int[10];
	histogram256 = new int[256];
	for (int i = 0; i < 10; i++){
		histogram10[i] = 0;
	}
	for (int i = 0; i < 256; i++){
		histogram256[i] = 0;
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
CImg<unsigned char> Histogram::getImage(){
	return image;
}

int* Histogram::getHistogram256(){
	return histogram256;
}

int* Histogram::getHistogram10(){
	return histogram10;
}

int Histogram::getTotal(){
	return total;
}