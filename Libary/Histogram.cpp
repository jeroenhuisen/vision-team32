#include "stdafx.h"
#include "Histogram.h"
#include <iostream>

Histogram::Histogram(Image image){
	Histogram::image = image;
	total = image.Height() * image.Width();
	//makeGray();
	//makeAHistogram(256);
	equalizedImage = Histogram::image;
	val = 0;
}

void Histogram::MakeAGrayHistogram(int value){
	if ((value > 0) && (value <= 256)){
		val = value;
		aHistogram = new int[value];

		for (int i = 0; i < value; i++){
			aHistogram[i] = 0;
		}

		for (int r = 0; r < image.Height(); r++){
			for (int c = 0; c < image.Width(); c++){
				unsigned char lum = (unsigned char)(((unsigned char)*image.Data(c, r, 0) * 0.30) + ((unsigned char)*image.Data(c, r, 1) * 0.59) + ((unsigned char)*image.Data(c, r, 2) * 0.11));
				*image.Data(c, r, 0) = lum;
				*image.Data(c, r, 1) = lum;
				*image.Data(c, r, 2) = lum;
				aHistogram[(int)((lum * value) / 256)]++;
			}
		}
	}
	else{
		std::cerr << "value klopt niet";
	}
}

/*void Histogram::makeGray(){
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
}*/

void Histogram::MakeARGBHistogram(int value){
	if ((value > 0) && (value <= 256)){
		val = value;
		aHistogramRed = new int[value];
		aHistogramGreen = new int[value];
		aHistogramBlue = new int[value];

		for (int i = 0; i < value; i++){
			aHistogramRed[i] = 0;
			aHistogramGreen[i] = 0;
			aHistogramBlue[i] = 0;
		}

		for (int r = 0; r < image.Height(); r++){
			for (int c = 0; c < image.Width(); c++){
				aHistogramRed[(int)((*image.Data(c, r, 0) * value) / 256)]++;
				aHistogramGreen[(int)((*image.Data(c, r, 0) * value) / 256)]++;
				aHistogramBlue[(int)((*image.Data(c, r, 0) * value) / 256)]++;
			}
		}
	}
}

/*
void Histogram::makeHistogramRGB(){
	histogramRed10 = new int[10];
	histogramGreen10 = new int[10];
	histogramBlue10 = new int[10];
	for (int i = 0; i < 10; i++){
		histogramRed10[i] = 0;
		histogramGreen10[i] = 0;
		histogramBlue10[i] = 0;
	}
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			histogramRed10[(int)((image(c, r, 0, 0) * 10) / 256)]++;
			histogramGreen10[(int)((image(c, r, 0, 1) * 10) / 256)]++;
			histogramBlue10[(int)((image(c, r, 0, 2) * 10) / 256)]++;
		}
	}
}*/

void Histogram::MakeAEqualizedHistogram(int value){
	if ((value > 0) && (value <= 256)){
		val = value;

		for (int i = 0; i < value; i++){
			aEqualizedHistogram[i] = 0;
		}

		for (int r = 0; r < image.Height(); r++){
			for (int c = 0; c < image.Width(); c++){
				aEqualizedHistogram[(int)image.Data(c, r, 0)]++;
			}
		}
	}
}



/*
void Histogram::makeHistogramEqualized(){
	for (int i = 0; i < 256; i++){
		equalizedHistogram256[i] = 0;
	}
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			equalizedHistogram256[(int)image(c, r, 0, 0)]++;
		}
	}
}

int* Histogram::getHistogramRed10(){
	return histogramRed10;
}
int* Histogram::getHistogramGreen10(){
	return histogramGreen10;
}
int* Histogram::getHistogramBlue10(){
	return histogramBlue10;
}


void Histogram::equalize(){
	// histogram[0..#grey_values] is normalized histogram 

	equalizedHistogram256 = new int[256];

	double alpha = (double)255 / (double)total;
	equalizedHistogram256[0] = alpha*histogram256[0];

	for (int i = 1; i < 255; i++){
		equalizedHistogram256[i] = equalizedHistogram256[i - 1] + alpha*histogram256[i];
	}

	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			equalizedImage(c, r, 0, 0) = equalizedHistogram256[image(c, r, 0, 0)];
			equalizedImage(c, r, 0, 1) = equalizedHistogram256[image(c, r, 0, 1)];
			equalizedImage(c, r, 0, 2) = equalizedHistogram256[image(c, r, 0, 2)];
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

int* Histogram::getEqualizedHistogram256(){
	return equalizedHistogram256;
}

int Histogram::getTotal(){
	return total;
}

void Histogram::saveHistogram(const char * filename){
	ofstream greyfilecsv;
	string redcsv = "HistogramRed10_";
	redcsv += filename;
	redcsv += ".csv";
	greyfilecsv.open(redcsv, ios::out | ios::binary);
	for (int i = 0; i < 10; i++){
		double test = (double)((double)histogramRed10[i] / ((double)total));
		greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
	}
	greyfilecsv.close();

	string greencsv = "HistogramGreen10_";
	greencsv += filename;
	greencsv += ".csv";

	greyfilecsv.open(greencsv, ios::out | ios::binary);
	for (int i = 0; i < 10; i++){
		double test = (double)((double)histogramGreen10[i] / ((double)total));
		greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
	}
	greyfilecsv.close();

	string bluecsv = "HistogramBlue10_";
	bluecsv += filename;
	bluecsv += ".csv";

	greyfilecsv.open(bluecsv, ios::out | ios::binary);
	for (int i = 0; i < 10; i++){
		double test = (double)((double)histogramBlue10[i] / ((double)total));
		greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
	}
	greyfilecsv.close();
}*/

void Histogram::SaveHistogram(const char * filename){
	ofstream greyfilecsv;
	string redcsv = "Histogram_";
	redcsv += filename;
	redcsv += ".csv";
	greyfilecsv.open(redcsv, ios::out | ios::binary);
	for (int i = 0; i < val; i++){
		double test = (double)((double)aHistogram[i] / ((double)total));
		greyfilecsv << i << ";" << setprecision(10) << fixed << showpoint << test << "\n";
	}
	greyfilecsv.close();
}