#include "stdafx.h"
#include "EqualizeFilter.h"

EqualizeFilter::EqualizeFilter(Image img) :Filter(img){

}

void EqualizeFilter::EqualizeImage(int * histogram, int total){
	// histogram[0..#grey_values] is normalized histogram 

	int * equalizedHistogram256 = new int[256];

	double alpha = (double)255 / (double)total;
	equalizedHistogram256[0] = alpha*histogram[0];

	for (int i = 1; i < 255; i++){
		equalizedHistogram256[i] = equalizedHistogram256[i - 1] + alpha*histogram[i];
	}

	for (int r = 0; r < image.Height(); r++){
		for (int c = 0; c < image.Width(); c++){
			*editedImage.Data(c, r, 0) = equalizedHistogram256[(int)*image.Data(c, r, 0)];
			*editedImage.Data(c, r, 1) = equalizedHistogram256[(int)*image.Data(c, r, 1)];
			*editedImage.Data(c, r, 2) = equalizedHistogram256[(int)*
				image.Data(c, r, 2)];
		}
	}
}

void EqualizeFilter::Equalize(int value){
	Histogram h(image);
	h.MakeAHistogram(value,0);
	EqualizeImage(h.getHistogram(), h.getTotal());
}