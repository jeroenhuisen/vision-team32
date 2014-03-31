#include "Mask.h"

Mask::Mask(Image img, int s){
	size = s;
	mask = new unsigned char[s*s];
	image = img;
}

Mask::~Mask(){
	delete mask;
}

unsigned char * Mask::getMask(int x, int y, int channel){
	int filterNumber = 0;
	for (int filterY = -(size - 1) / 2; filterY <= (size - 1) / 2; filterY++){
		for (int filterX = -(size - 1) / 2; filterX <= (size - 1) / 2; filterX++){
			mask[filterNumber] = *image.Data(x + filterX, y + filterY, channel);
			filterNumber++;
		}
	}
	return mask;
}