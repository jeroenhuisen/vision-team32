#ifndef HISTOGRAM
#define HISTOGRAM
#include "ImageV2.h"
#include <fstream>
#include <iomanip>

using namespace std;

class Histogram{
private:
	Image image;
	Image equalizedImage;
	//void makeGray();
	int val;
	int* aHistogram;
	//int* histogram256;
	//int* histogram10;
	int* aHistogramRed;
	int* aHistogramGreen;
	int* aHistogramBlue;
	int* aEqualizedHistogram;
	//int* equalizedHistogram10;
	int total;

public:
	Histogram(Image image);
	void MakeAGrayHistogram(int value);
	void MakeARGBHistogram(int value);
	void MakeAEqualizedHistogram(int value);
	//void equalize();
	//int* getHistogram256();
	//int* getHistogram10();
	//int* getHistogramRed10();
	//int* getHistogramGreen10();
	//int* getHistogramBlue10();
	//int* getEqualizedHistogram256();
	//int getTotal();
	//void makeHistogramRGB();
	//void makeHistogramEqualized();
	void SaveHistogram(const char * filename);
	Image getImage();
	Image getEqualizedImage();
};
#endif