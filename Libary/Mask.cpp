#include "Mask.h"

Mask::Mask(Image img, int s){
	size = s;
	image = img;
	mask = new unsigned char[s*s];
}

Mask::~Mask(){
	delete mask;
}

unsigned char * Mask::getMask(int x, int y, int channel){
	int filterNumber = 0;//used for saving the mask from left to right in mask.
	for (int filterY = -(size - 1) / 2; filterY <= (size - 1) / 2; filterY++){//Controls y starts from the top of the mask ends at the bottom
		for (int filterX = -(size - 1) / 2; filterX <= (size - 1) / 2; filterX++){//Controls x starts from the left of the mask ends at the right
			mask[filterNumber] = *image.Data(x + filterX, y + filterY, channel);
			filterNumber++;
		}
	}
	return mask;
}