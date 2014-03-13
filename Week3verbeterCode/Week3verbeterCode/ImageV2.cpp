#include "stdafx.h"
#include "ImageV2.h"
#include <iostream>
#include <string>

char * FilenameConvert(char * argv){
	std::string filename1 = argv;
	int filelength = 0;
	for (int i = filename1.length() - 1; i > 0; i--){
		filelength++;
		if (filename1[i] == '\\'){
			filelength--;
			break;
		}
	}
	const char * p = filename1.c_str();
	char * p2 = new char[filelength + 1];
	int x = 0;
	for (int i = filename1.length() - filelength; i < filename1.length(); i++){
		p2[x] = p[i];
		x++;
	}	
	p2[filelength] = '\0';

	return p2;
}
Image::Image(char * filename, int channels){
	/*if (channels > image.getChannelsAmount blabla{
	std::cerr << "Requested channels is bigger than input image has.";
	}*/
	CImg<unsigned char> image;
	try{
		cimg::exception_mode(0);
		image.load(filename);
	}
	catch (CImgIOException cioe){
		std::cerr << "Image not found\n";
	}
	filename = FilenameConvert(filename);

	Image::channels = channels;

	channelsArray = new unsigned char*[channels];
	for (int i = 0; i < channels; i++){
		channelsArray[i] = image.data(0, 0, 0, i);
	}
}

Image::Image(char * filename){
	/*if (channels > image.getChannelsAmount blabla{
	std::cerr << "Requested channels is bigger than input image has.";
	}*/
	CImg<unsigned char> image;
	filename = FilenameConvert(filename);
	try{
		cimg::exception_mode(0);
		image.load(filename);
	}
	catch (CImgIOException cioe){
		std::cerr << "Image not found\n";
	}

	Image::channels = channels;

	channelsArray = new unsigned char*[channels];
	for (int i = 0; i < channels; i++){
		channelsArray[i] = image.data(0, 0, 0, i);
	}
}


unsigned char ** Image::GetChannelsArray(){
	return channelsArray;
}

unsigned char * Image::GetChannelArray(int channel){
	return channelsArray[channel];
}

unsigned char * Image::Data(int x, int y, int channel){
	return channelsArray[channel];
}

unsigned char Image::GetValue(int x, int y, int channel){
	//return *channelsArray[channel[x + width * y]];
}

void Image::SaveImage(char * filename){
	CImg<unsigned char> image;
	// copy channels to output image
	image.save(filename);
}

