// Week1Opdr2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basetimer.h"

#include "ImageV2.h"
#include "SaltAndPeppah.h"
#include "MedianFilter.h"
#include "MiniumumFilter.h"
#include "MaxiumumFilter.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc <= 1){
		cerr << "Missing argument, use image path\n";
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

	SaltAndPepper sap(image, 50);
	string noiseFilename = "noise_";
	noiseFilename += image.GetFilename();
	sap.getEditedImage().SaveImage(noiseFilename.c_str());

	Image noiseImage = sap.getEditedImage();

	bt.stop();
	cout << "Noise toegevoegd en opgeslagen in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();
	bt.start();

	MedianFilter medF(noiseImage, 5);
	string medianFilename = "median_";
	medianFilename += noiseImage.GetFilename();
	medF.getEditedImage().SaveImage(medianFilename.c_str());


	bt.stop();
	cout << "MedianFilter gebruikt en image opgeslagen in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();
	bt.start();

	MinFilter minF(noiseImage, 3);
	string minFilename = "min_";
	minFilename += noiseImage.GetFilename();
	minF.getEditedImage().SaveImage(minFilename.c_str());

	MaxFilter maxF(noiseImage, 3);
	string maxFilename = "max_";
	maxFilename += noiseImage.GetFilename();
	maxF.getEditedImage().SaveImage(maxFilename.c_str());

	bt.stop();
	cout << "MaxFilter + MinFilter gebruikt en image opgeslagen in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();

	btTotal.stop();
	cout << "Totaal duurde alles: " << btTotal.elapsedSeconds() << " seconden\n";

	system("pause");
	return 0;
}