#include "Cimg.h"

using namespace cimg_library;
class Image{
private:
	unsigned char ** channelsArray;
	int channels;

	int height;
	int width;

public:
	Image(char * filename, int channels);
	Image(char * filename);

	unsigned char ** GetChannelsArray();
	unsigned char * GetChannelArray(int channel);

	unsigned char * Data(int x, int y, int channel);
	unsigned char GetValue(int x, int y, int channel);

	void SaveImage(char * filename);
};