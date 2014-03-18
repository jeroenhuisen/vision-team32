#ifndef IMAGE_H
#define IMAGE_H
#include "Cimg.h"

using namespace cimg_library;
class Image{
private:
	unsigned char ** channelsArray;
	
	int channels;

	int height;
	int width;

	const char * filename;

public:
	Image(const char * filename, int channels);
	Image(const char * filename);
	Image(int width, int height, int channels);
	Image(){}

	unsigned char ** GetChannelsArray();
	unsigned char * GetChannelArray(int channel);

	unsigned char * Data(int x, int y, int channel);
	unsigned char GetValue(int x, int y, int channel);

	int GetChannels();
	int Height();
	int Width();

	const char * GetFilename();

	void SaveImage(const char * filename);
};
#endif