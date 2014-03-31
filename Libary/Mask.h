#include "ImageV2.h"

class Mask{
private:
	Image image;
	int size;
	unsigned char * mask;
public:
	Mask(Image img, int s);
	~Mask();
	unsigned char * getMask(int x, int y, int channel);
};