#ifndef SALTANDPEPPER_H
#define SALTANDPEPPER_H
#include "ImageV2.h"
#include <fstream>
#include <iomanip>
using namespace std;

class SaltAndPepper{
private:
	Image image;
	int percentage;
public:
	SaltAndPepper(Image img, int per);
	void setNoise(int per);
	int getPercentage();
	void saveImage(const char * filename);
	Image getImage();
};
#endif