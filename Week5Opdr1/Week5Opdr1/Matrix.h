#ifndef MATRIX
#define MATRIX

#include "ImageV2.h"

#include <fstream>
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
	void Matrix::Transformatie(int a0, int a1, int a2, int b0, int b1, int b2);
	void Transformatie1(float a0, float a1, int a2, float b0, float b1, int b2);
	void SaveImg(const char* filename);
};
#endif