#include "Cimg.h"
#include <fstream>
#include <iomanip>
using namespace std;

using namespace cimg_library;
class Histogram{
private:
	CImg<unsigned char> image;
	CImg<unsigned char> equalizedImage;
	void makeGray();
	int* histogram256;
	int* histogram10;
	int* histogramRed10;
	int* histogramGreen10;
	int* histogramBlue10;
	int* equalizedHistogram256;
	int* equalizedHistogram10;
	int total;

public:
	Histogram(CImg<unsigned char> image);
	//void makeRed();
	void equalize();
	int* getHistogram256();
	int* getHistogram10();
	int* getHistogramRed10();
	int* getHistogramGreen10();
	int* getHistogramBlue10();
	int* getEqualizedHistogram256();
	int getTotal();
	void makeHistogramRGB();
	void saveHistogram(const char * filename);
	CImg<unsigned char> getImage();
	CImg<unsigned char> getEqualizedImage();
};