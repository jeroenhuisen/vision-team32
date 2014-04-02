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
};
#endif