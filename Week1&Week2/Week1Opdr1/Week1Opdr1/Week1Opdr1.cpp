// Week1Opdr1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basetimer.h"

#include "ImageV2.h"
#include "ColorFilter.h"
#include "Histogram.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc <= 1){
		cerr << "Missing argument, use image path";
		system("pause");
		return 0;
	}
	BaseTimer bt;
	bt.start();

	Image image(argv[1]);

	bt.stop();
	cout << "Bestand ingelezen in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();
	bt.start();
	
	ColorFilter cf(image);
	cf.makeGrey();
	image = cf.getEditedImage();

	bt.stop();
	cout << "Grijs gemaakt in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();
	bt.start();

	string newFilename = "grey_";
	newFilename += image.GetFilename();
	image.SaveImage(newFilename.c_str());

	bt.stop();
	cout << "Bestand opgeslagen in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();
	bt.start();

	Histogram h(image);
	h.MakeAGrayHistogram(256);
	string histogramFilename256 = "Histogram256_";
	histogramFilename256 += image.GetFilename();
	h.SaveHistogram(histogramFilename256.c_str());

	h.MakeAGrayHistogram(10);
	string histogramFilename10 = "Histogram10_";
	histogramFilename10 += image.GetFilename();
	h.SaveHistogram(histogramFilename10.c_str());

	bt.stop();
	cout << "Grijs gemaakt in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();
	system("pause");
	return 0;
}