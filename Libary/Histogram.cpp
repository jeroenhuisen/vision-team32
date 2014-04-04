#include "stdafx.h"
#include "Histogram.h"
#include <iostream>

Histogram::Histogram(Image image){
	Histogram::image = image;
	total = image.Height() * image.Width();
	//makeGray();
	//makeAHistogram(256);
	val = 0;
}

void Histogram::MakeAGreyHistogram(int value){
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

void Histogram::MakeAHistogram(int value, int channel){
	if ((value > 0) && (value <= 256)){
		val = value;
		aHistogram = new int[value];

		for (int i = 0; i < value; i++){
			aHistogram[i] = 0;
		}

		for (int r = 0; r < image.Height(); r++){
			for (int c = 0; c < image.Width(); c++){
				aHistogram[(int)((*image.Data(c,r, channel) * value) / 256)]++;
			}
		}
	}
	else{
		std::cerr << "value klopt niet";
	}
}


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


int* Histogram::getHistogramRed(){
	return aHistogramRed;
}
int* Histogram::getHistogramGreen(){
	return aHistogramGreen;
}
int* Histogram::getHistogramBlue(){
	return aHistogramBlue;
}


int* Histogram::getGreyHistogram(){
	return aHistogram;
}

int Histogram::getTotal(){
	return total;
}


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