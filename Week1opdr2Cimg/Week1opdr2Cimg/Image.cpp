#include "stdafx.h"
#include "Image.h"
#include <iostream>

Image::Image(CImg<unsigned char> image){
	Image::image = image;
	editedImage = Image::image;
}

void Image::makeRed(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			editedImage(c, r, 0, 0) = image(c, r, 0, 2);
			editedImage(c, r, 0, 1) = 0;
			editedImage(c, r, 0, 2) = 0;
		}
	}
}

void Image::makeGreen(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			editedImage(c, r, 0, 0) = 0;
			editedImage(c, r, 0, 1) = image(c, r, 0, 2);
			editedImage(c, r, 0, 2) = 0;
		}
	}
}

void Image::makeBlue(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			editedImage(c, r, 0, 0) = 0;
			editedImage(c, r, 0, 1) = 0;
			editedImage(c, r, 0, 2) = image(c, r, 0, 2);
		}
	}
}

void Image::makeGrey(){
	for (int r = 0; r < image.height(); r++){
		for (int c = 0; c < image.width(); c++){
			unsigned char lum = (unsigned char)(((unsigned char)image(c, r, 0, 0) * 0.30) + ((unsigned char)image(c, r, 0, 1) * 0.59) + ((unsigned char)image(c, r, 0, 2) * 0.11));
			editedImage(c, r, 0, 0) = lum;
			editedImage(c, r, 0, 1) = lum;
			editedImage(c, r, 0, 2) = lum;
		}
	}
}

CImg<unsigned char> Image::getImage(){
	return image;
}
CImg<unsigned char> Image::getEditedImage(){
	return editedImage;
}