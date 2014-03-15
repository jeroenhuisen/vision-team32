#ifndef AUTOTHRESHOLD_H
#define AUTOTHRESHOLD_H

#include "ImageV2.h"
#include "Filter.h"

class AutoThreshold : public Filter{
private:
	Image image;
	Image editedImage;

public:
	AutoThreshold(Image img, int k);
	void clusterRGB();
};
#endif