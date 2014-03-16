#ifndef MATRIX
#define MATRIX

#include "ImageV2.h"

#include <fstream>
#include <iomanip>

using namespace std;

class Matrix{
private:
	Image image;
	int a0;
	int b0;
	int a1;
	int b1;

public:
	Matrix(Image image);
	void Verschuif(int dx, int dy);
	void SaveImg(const char* filename);
};
#endif