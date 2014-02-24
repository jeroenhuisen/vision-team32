// Week1opdr7.cpp : Defines the entry point for the console application.
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

int _tmain(int argc, _TCHAR* argv[])
{
	string filename;
	bool filefound = false;
	while (filefound != true){
		cout << "Please give the filename of bmp file: ";
		cin >> filename;

		ifstream file;
		CImg<unsigned char> image;
		//cimg::exception_mode(0);
		try{
			image.load(filename.c_str());
			BaseTimer bt;
			bt.start();
			filefound = true;

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
		}
		catch (CImgIOException cioe){
			cerr << "Image not found\n";
		}
	}
	system("pause");
	return 0;
}