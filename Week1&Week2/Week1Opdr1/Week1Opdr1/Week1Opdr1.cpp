// Week1Opdr1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basetimer.h"

#include "ImageV2.h"
#include "ColorFilter.h"
#include "Histogram.h"
#include "EqualizeFilter.h"

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
	BaseTimer btTotal;
	btTotal.start();
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
	h.MakeAGreyHistogram(256);
	string histogramFilename256 = "Histogram256_";
	histogramFilename256 += image.GetFilename();
	h.SaveHistogram(histogramFilename256.c_str());

	h.MakeAGreyHistogram(10);
	string histogramFilename10 = "Histogram10_";
	histogramFilename10 += image.GetFilename();
	h.SaveHistogram(histogramFilename10.c_str());

	bt.stop();
	cout << "Histogrammen gemaakt + opgeslagen in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();
	bt.start();
	
	EqualizeFilter ef(image);
	ef.Equalize(255);

	string equalizedFilename = "equalized_";
	equalizedFilename += image.GetFilename();
	ef.getEditedImage().SaveImage(equalizedFilename.c_str());

	bt.stop();
	bt.reset();

	btTotal.stop();
	cout << "Totaal duurde alles: " << btTotal.elapsedSeconds() << " seconden\n";

	system("pause");
	return 0;
}