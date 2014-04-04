#include "Filter.h"
#include "Histogram.h"

class EqualizeFilter :public Filter{
public:
	EqualizeFilter(Image img);

	//Equalize the image
	//
	//The image will be equalized when using this function.
	//Therefor is a equalized histogram needed which should be given by param.
	//Total is the total of the values of the histogram.
	void EqualizeImage(int * histogram, int total);


	//Equalize the image
	//
	//The image will be equalized when using this function. 
	//Therefor is not equalized histogram needed this will be created inside this function using the value for the size of the histogram.
	void Equalize(int value);
};