#ifndef COLORFILTER_H
#define COLORFILTER_H
#include "ImageV2.h"
#include "Filter.h"

class ColorFilter: public Filter{
private:
	Image image;
	Image editedImage;
public:
	ColorFilter(Image img);
	void makeRed();
	void makeGreen();
	void makeBlue();
	void makeGrey();
};
#endif