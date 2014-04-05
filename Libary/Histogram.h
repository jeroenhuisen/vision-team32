#ifndef HISTOGRAM
#define HISTOGRAM
#include "ImageV2.h"
#include <fstream>
#include <iomanip>

using namespace std;

class Histogram{
private:
	Image image;
	int val;
	int* aHistogram;
	int total;

public:
	Histogram(Image image);
	void MakeAHistogram(int value, int channel);
	int * getHistogram();
	int getTotal();
	void SaveHistogram(const char * filename);
};
#endif