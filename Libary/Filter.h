#ifndef FILTER_H
#define FILTER_H
#include "ImageV2.h"

class Filter{
protected:
	Image image;
	Image editedImage;
public:
	Filter(Image img){
		image = img;
		editedImage = Image(img.Width(), img.Height(), img.GetChannels());
	}
	Image getImage(){
		return image;
	}
	Image getEditedImage(){
		return editedImage;
	}
};
#endif