#ifndef FILTER_H
#define FILTER_H
#include "ImageV2.h"

class Filter{
private:
	Image image;
	Image editedImage;
public:
	Filter(Image img){
		image = img;
		editedImage = img;
	}
	Image getImage(){
		return image;
	}
	Image getEditedImage(){
		return editedImage;
	}
};
#endif