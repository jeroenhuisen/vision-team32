#include "Cimg.h"

using namespace cimg_library;
class Histogram{
private:
	CImg<unsigned char> image;
	void makeGray();
	unsigned char histogram256[256];
	unsigned char histogram10[10];
	int total;

public:
	Histogram(CImg<unsigned char> image);
	unsigned char* getHistogram256();
	unsigned char* getHistogram10();
	int getTotal();
	CImg<unsigned char> getImage();
};