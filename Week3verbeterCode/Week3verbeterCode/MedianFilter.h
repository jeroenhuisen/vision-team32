#include "CImg.h"

using namespace cimg_library;
class MedianFilter{
private:
	CImg<unsigned char> image;
	CImg<unsigned char> editedImage;
	int compare(const void * a, const void * b);
public:
	MedianFilter(CImg<unsigned char> img, int value);
	void filter(int value);
	void filterHistogram(int value);
	void saveImage(const char * filename);
};