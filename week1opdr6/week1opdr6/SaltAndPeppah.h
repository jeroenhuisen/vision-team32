#include "CImg.h"
#include <fstream>
#include <iomanip>
using namespace std;

using namespace cimg_library;
class SaltAndPepper{
private:
	CImg<unsigned char> image;
	int percentage;
public:
	SaltAndPepper(CImg<unsigned char> img, int per);
	void setNoise(int per);
	int getPercentage();
	void saveImage(const char * filename);
	CImg<unsigned char> getImage();
};