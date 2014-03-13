#include "stdafx.h"
#include "ImageV2.h"
#include <iostream>
#include <string>

char * FilenameConvert(const char * argv){
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
Image::Image(const char * filename, int channels){
	CImg<unsigned char> image;
	try{
		cimg::exception_mode(0);
		image.load(filename);
		if (channels > image.spectrum()){
			std::cerr << "Requested amount of channels is bigger than input image has.";
		}
	}
	catch (CImgIOException cioe){
		std::cerr << "Image not found\n";
	}
	Image::filename = FilenameConvert(filename);

	Image::channels = channels;
	Image::height = image.height();
	Image::width = image.width();

	channelsArray = new unsigned char*[channels];
	for (int i = 0; i < channels; i++){
		channelsArray[i] = image.data(0, 0, 0, i);
	}
}

Image::Image(const char * filename){
	CImg<unsigned char> image;
	Image::filename = FilenameConvert(filename);
	try{
		cimg::exception_mode(0);
		image.load(filename);
	}
	catch (CImgIOException cioe){
		std::cerr << "Image not found\n";
	}

	Image::channels = image.spectrum();
	Image::height = image.height();
	Image::width = image.width();

	Image::channelsArray = new unsigned char*[channels];
	for (int i = 0; i < channels; i++){
		channelsArray[i] = new unsigned char[height*width];
		channelsArray[i] = image.data(0, 0, 0, i);
	}

	std::cout << (int)(channelsArray[0][0]) << "\n";

}


unsigned char ** Image::GetChannelsArray(){
	return channelsArray;
}

unsigned char * Image::GetChannelArray(int channel){
	return channelsArray[channel];
}

unsigned char * Image::Data(int x, int y, int channel){
	//unsigned char * p = &(channelsArray[channel][x]);
	//std::cout << (int)p<<"\n";
	std::cout << (int)(channelsArray[0][0]) << "\n";
	return &channelsArray[0][0];
}

unsigned char Image::GetValue(int x, int y, int channel){
	return channelsArray[channel][x + width * y];
}

int Image::GetChannels(){
	return channels;
}

int Image::Height(){
	return height;
}
int Image::Width(){
	return width;
}



const char * Image::GetFilename(){
	return filename;
}


void Image::SaveImage(const char * filename){
	CImg<unsigned char> image;
	// copy channels to output image
	image.save(filename);
}

