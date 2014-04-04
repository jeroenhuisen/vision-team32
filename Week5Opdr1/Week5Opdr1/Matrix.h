#ifndef MATRIX
#define MATRIX

#include "ImageV2.h"

#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Matrix{
private:
	Image image;
	Image editedImage;
	Image iksloophetImage;
	Image ikhebhetalgeslooptImage;
	int a0;
	int a1;
	int a2;
	int b0;
	int b1;
	int b2;

public:
	Matrix(Image image);
	void Verschuif(int dx, int dy);
	void Transformatie(float a0, float a1, int a2, float b0, float b1, int b2);
	void Translatie(int dx, int dy);
	void Rotatie(float f);
	void Scaling(float s);
	void Shear(float s);
	void RotatieAA(float f);
	void SaveImg(const char* filename);
	void Three_Way_Shear(float s);
};
#endif