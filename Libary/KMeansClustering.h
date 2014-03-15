#ifndef KMEANSCLUSTERING_H
#define KMEANSCLUSTERING_H

#include "ImageV2.h"
#include "Filter.h"

class KMeansClustering : public Filter{
private:
	Image image;
	Image editedImage;

	int kValue;
	unsigned char ** cluster;
public:
	KMeansClustering(Image img, int k);
	void clusterRGB();
};
#endif