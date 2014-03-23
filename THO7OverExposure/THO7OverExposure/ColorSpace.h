#ifndef COLORSPACE_H
#define COLORSPACE_H
#include "ImageV2.h"
#include "Filter.h"
#include <math.h>
#include <iostream>

class ColorSpace : public Filter{
private:
	Image image;
	Image editedImage;
	int* RGBtoXYZ(unsigned char R, unsigned char G, unsigned char B);
	int* XYZtoLAB(unsigned char x, unsigned char y, unsigned char z);
public:
	ColorSpace(Image img);
	void ToXYZ();
	void ToLAB();
};
#endif