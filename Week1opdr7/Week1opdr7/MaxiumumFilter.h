#include "CImg.h"

using namespace cimg_library;
class MaxiumumFilter{
private:
	CImg<unsigned char> image;
	CImg<unsigned char> editedImage;
	int compare(const void * a, const void * b);
public:
	MaxiumumFilter(CImg<unsigned char> img, int value);
	void filter(int value);
	void filterHistogram(int value);
	void saveImage(const char * filename);
};