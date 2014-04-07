#ifndef ALG
#define ALG

#include "Image.h"

#include <fstream>
#include <iomanip>

using namespace std;

class Alg{
private:
	Image image;
	Image editedImage;

public:
	Alg(Image image);
	void SaveImg(const char* filename);
	void Blue(int maxBlue);
	void Laplacian();
	void Gradiant(int threshold, int l_b_x, int l_b_y, int r_o_x, int l_o_y);
};
#endif