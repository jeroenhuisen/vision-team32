// Week3verbeterCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CImg.h"
#include "basetimer.h"
#include "SaltAndPeppah.h"
#include "MedianFilter.h"
#include "MaxiumumFilter.h"
#include "MiniumumFilter.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace cimg_library;

int main(int argc, char* argv[])
{
	string filename1 = argv[1];
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
	string filename((const char *)p2);
	CImg<unsigned char> image;
	//cimg::exception_mode(0);
	try{
		image.load(filename.c_str());
		BaseTimer bt;
		bt.start();

		SaltAndPepper sap(image, 5);
		string newFilename = "noise_";
		newFilename += filename;
		sap.saveImage(newFilename.c_str());
		CImg<unsigned char> noiseImage = sap.getImage();
		MedianFilter mf(noiseImage, 3);
		string newImage = "median_";
		newImage += filename;
		mf.saveImage(newImage.c_str());
		MiniumumFilter minf(noiseImage, 3);
		string newminImage = "min_";
		newminImage += filename;
		minf.saveImage(newminImage.c_str());
		MaxiumumFilter maxf(noiseImage, 3);
		string newmaxImage = "max_";
		newmaxImage += filename;
		maxf.saveImage(newmaxImage.c_str());
		bt.stop();
		cout << bt.elapsedSeconds();

		for (int i = 0; i < 256; i++){
			cout << i;
		}
	}
	catch (CImgIOException cioe){
		cerr << "Image not found\n";
	}

	system("pause");
	return 0;
}