#ifndef COLORSPACE_H
#define COLORSPACE_H
#include "ImageV2.h"
#include "Filter.h"
#include <math.h>
#include <iostream>

class ColorSpace : public Filter{
private:
	double* RGBtoXYZ(unsigned char R, unsigned char G, unsigned char B);
	float* XYZtoLAB(float x, float y, float z);

	char * A;
	char * B;
public:
	ColorSpace(Image img);
	void ToXYZ();
	void ToLAB();
	void ToRGB();
	
	char * getA(){
		return A;
	}
	char * getB(){
		return B;
	}

	void setA(char * Ab){
		A = Ab;
	}
	void setB(char * Bb){
		B = Bb;
	}
	void Test();
};
#endif