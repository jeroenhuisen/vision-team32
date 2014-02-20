#include "Cimg.h"

using namespace cimg_library;
class Histogram{
private:
	CImg<unsigned char> image;
	CImg<unsigned char> equalizedImage;
	void makeGray();
	int* histogram256;
	int* histogram10;
	int* equalizedHistogram256;
	int* equalizedHistogram10;
	int total;

public:
	Histogram(CImg<unsigned char> image);
	void makeRed();
	void equalize();
	int* getHistogram256();
	int* getHistogram10();
	int* getEqualizedHistogram256();
	int getTotal();
	CImg<unsigned char> getImage();
	CImg<unsigned char> getEqualizedImage();
};