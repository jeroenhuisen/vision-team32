#ifndef SALTANDPEPPER_H
#define SALTANDPEPPER_H
#include "ImageV2.h"
#include "Filter.h"
#include <fstream>
#include <iomanip>
using namespace std;

class SaltAndPepper: public Filter{
private:
	int percentage;
public:
	SaltAndPepper(Image img, int per);
	void setNoise(int per);
	int getPercentage();
};
#endif