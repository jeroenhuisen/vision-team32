#ifndef HISTOGRAM
#define HISTOGRAM
#include "ImageV2.h"
#include <fstream>
#include <iomanip>

using namespace std;

class Histogram{
private:
	Image image;
	//void makeGray();
	int val;
	int* aHistogram;
	//int* histogram256;
	//int* histogram10;
	int* aHistogramRed;
	int* aHistogramGreen;
	int* aHistogramBlue;
	int total;

public:
	Histogram(Image image);
	void MakeAGreyHistogram(int value);
	void MakeARGBHistogram(int value);
	void MakeAHistogram(int value, int channel);
	/*int* getGreyHistogram();
	int* getHistogramRed();
	int* getHistogramGreen();
	int* getHistogramBlue();*/
	int * getHistogram();
	int getTotal();
	void SaveHistogram(const char * filename);
};
#endif