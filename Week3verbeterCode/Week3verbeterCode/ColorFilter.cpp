#include "ColorFilter.h"
void ColorFilter::makeRed(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			editedImage(c, r, 0, 0) = image(c, r, 0, 2);
			editedImage(c, r, 0, 1) = 0;
			editedImage(c, r, 0, 2) = 0;
		}
	}
}

void ColorFilter::makeGreen(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			editedImage(c, r, 0, 0) = 0;
			editedImage(c, r, 0, 1) = image(c, r, 0, 2);
			editedImage(c, r, 0, 2) = 0;
		}
	}
}

void ColorFilter::makeBlue(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			editedImage(c, r, 0, 0) = 0;
			editedImage(c, r, 0, 1) = 0;
			editedImage(c, r, 0, 2) = image(c, r, 0, 2);
		}
	}
}

void ColorFilter::makeGrey(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			unsigned char lum = (unsigned char)(((unsigned char)image(c, r, 0, 0) * 0.30) + ((unsigned char)image(c, r, 0, 1) * 0.59) + ((unsigned char)image(c, r, 0, 2) * 0.11));
			editedImage(c, r, 0, 0) = lum;
			editedImage(c, r, 0, 1) = lum;
			editedImage(c, r, 0, 2) = lum;
		}
	}
}