// Week3verbeterCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CImg.h"
#include "basetimer.h"
#include "SaltAndPeppah.h"
#include "MedianFilter.h"
#include "MaxiumumFilter.h"
#include "MiniumumFilter.h"

#include "ImageV2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace cimg_library;

int main(int argc, char* argv[])
{
		BaseTimer bt;
		Image image(argv[1]);
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

	system("pause");
	return 0;
}