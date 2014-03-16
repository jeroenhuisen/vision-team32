// Week3verbeterCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basetimer.h"
#include "SaltAndPeppah.h"
//#include "MedianFilter.h"
//#include "MaxiumumFilter.h"
//#include "MiniumumFilter.h"

#include "ImageV2.h"
#include "Histogram.h" 
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
		BaseTimer bt;
		Image image(argv[1]);
		image.Data(0, 0, 0);
		bt.start();

		SaltAndPepper sap(image, 5);
		string newFilename = "noise_";
		newFilename += image.GetFilename();
		sap.saveImage(newFilename.c_str());

		Histogram His(image);
		His.MakeAGrayHistogram(256);
		His.SaveHistogram("test");
		/*CImg<unsigned char> noiseImage = sap.getImage();
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
		*/

		bt.stop();
		cout << bt.elapsedSeconds();
	system("pause");
	return 0;
}