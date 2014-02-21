#include "Cimg.h"

using namespace cimg_library;
class Image{
private:
	CImg<unsigned char> image;
	CImg<unsigned char> editedImage;

public:
	Image(CImg<unsigned char> image);
	void makeGrey();
	void makeRed();
	void makeGreen();
	void makeBlue();
	//void equalize();
	CImg<unsigned char> getImage();
	CImg<unsigned char> getEditedImage();
};