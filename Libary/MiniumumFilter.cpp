#include "stdafx.h"
#include "MiniumumFilter.h"

//#include <iostream>



MiniumumFilter::MiniumumFilter(CImg<unsigned char> img, int value){
	image = img;
	editedImage = img;
	filterHistogram(value);
}
int MiniumumFilter::compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
void MiniumumFilter::filter(int value){//size of filter
	unsigned char* filterRed = new unsigned char[value * value];
	unsigned char* filterGreen = new unsigned char[value * value];
	unsigned char* filterBlue = new unsigned char[value * value];

	int filterNumber = 0;
	for (int y = (value - 1) / 2; y < image.height() - (value - 1) / 2; y++){
		for (int x = (value - 1) / 2; x < image.width() - (value - 1) / 2; x++){
			filterNumber = 0;
			for (int filterY = -(value - 1) / 2; filterY <= (value - 1) / 2; filterY++){
				for (int filterX = -(value - 1) / 2; filterX <= (value - 1) / 2; filterX++){
					filterRed[filterNumber] = image(x + filterX, y + filterY, 0, 0);
					filterGreen[filterNumber] = image(x + filterX, y + filterY, 0, 1);
					filterBlue[filterNumber] = image(x + filterX, y + filterY, 0, 2);
					filterNumber++;
					//std::cout << filterNumber<<"\n";
				}
				//filterNumber += value;
			}
			//sort should use histogram...
			//qsort(filterRed, value*value, sizeof(int), compare);
			//qsort(filterGreen, value*value, sizeof(int), compare);
			//qsort(filterBlue, value*value, sizeof(int), compare);
			image(x, y, 0, 0) = filterRed[(value*value - 1) / 2];
			image(x, y, 0, 1) = filterGreen[(value*value - 1) / 2];
			image(x, y, 0, 2) = filterBlue[(value*value - 1) / 2];
		}
	}

	image.save("Miniumum.bmp");

	//Histogram
}

void MiniumumFilter::filterHistogram(int value){//size of filter
	unsigned char* filterRed = new unsigned char[value * value];
	unsigned char* filterGreen = new unsigned char[value * value];
	unsigned char* filterBlue = new unsigned char[value * value];

	unsigned char* filterRedHistogram = new unsigned char[256];
	unsigned char* filterGreenHistogram = new unsigned char[256];
	unsigned char* filterBlueHistogram = new unsigned char[256];

	for (int i = 0; i < 256; i++){
		filterRedHistogram[i] = 0;
		filterGreenHistogram[i] = 0;
		filterBlueHistogram[i] = 0;
	}

	int filterNumber = 0;
	int total = 0;
	for (int y = (value - 1) / 2; y < image.height() - (value - 1) / 2; y++){
		total++;
		for (int x = (value - 1) / 2; x < image.width() - (value - 1) / 2; x++){
			total++;
			filterNumber = 0;
			for (int filterY = -(value - 1) / 2; filterY <= (value - 1) / 2; filterY++){
				for (int filterX = -(value - 1) / 2; filterX <= (value - 1) / 2; filterX++){
					//filterRed[filterNumber] = image(x + filterX, y + filterY, 0, 0);
					//filterGreen[filterNumber] = image(x + filterX, y + filterY, 0, 1);
					//filterBlue[filterNumber] = image(x + filterX, y + filterY, 0, 2);
					//filterNumber++;
					filterRedHistogram[image(x + filterX, y + filterY, 0, 0)] ++;
					filterGreenHistogram[image(x + filterX, y + filterY, 0, 1)] ++;
					filterBlueHistogram[image(x + filterX, y + filterY, 0, 2)] ++;
					//std::cout << filterNumber<<"\n";
				}
				//filterNumber += value;
			}
			//Histogram
			int foundRed = 0;
			int foundGreen = 0;
			int foundBlue = 0;
			int searchRed = 0;
			int searchGreen = 0;
			int searchBlue = 0;
			for (int i = 0; i < 256; i++){
				if (foundRed <= 0){
					foundRed += filterRedHistogram[i];
					searchRed++;
				}
				if (foundGreen <= 0){
					foundGreen += filterGreenHistogram[i];
					searchGreen++;
				}
				if (foundBlue <= 0){
					foundBlue += filterBlueHistogram[i];
					searchBlue++;
				}
				filterRedHistogram[i] = 0;
				filterGreenHistogram[i] = 0;
				filterBlueHistogram[i] = 0;
			}
			editedImage(x, y, 0, 0) = searchRed;
			editedImage(x, y, 0, 1) = searchGreen;
			editedImage(x, y, 0, 2) = searchBlue;
			//test
		}
	}
}

void MiniumumFilter::saveImage(const char * filename){
	editedImage.save(filename);
}