#ifndef AUTOTHRESHOLD_H
#define AUTOTHRESHOLD_H

#include "ImageV2.h"
#include "Filter.h"

class AutoThreshold : public Filter{
private:
	Image image;
	Image editedImage;

public:
	AutoThreshold(Image img);
	void ThresholdCalc();
	void Threshold(int threshold);
};
#endif