#include "Cimg.h"

using namespace cimg_library;
class Histogram{
private:
	CImg<unsigned char> image;
	void makeGray();
	int* histogram256;
	int* histogram10;
	int total;

public:
	Histogram(CImg<unsigned char> image);
	int* getHistogram256();
	int* getHistogram10();
	int getTotal();
	CImg<unsigned char> getImage();
};