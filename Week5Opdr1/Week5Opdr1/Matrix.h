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
	int a0;
	int a1;
	int a2;
	int b0;
	int b1;
	int b2;

public:
	Matrix(Image image);
	void Verschuif(int dx, int dy);
	void Transformatie(int a0, int a1, int a2, int b0, int b1, int b2);
	void Transformatie1(int a0, int a1, int a2, int b0, int b1, int b2);
	void Rotatie(float f);
	void SaveImg(const char* filename);
};
#endif