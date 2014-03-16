// Week3Opdr1-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basetimer.h"

#include "ImageV2.h"
#include "ColorFilter.h"
#include "AutoThreshold.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc <= 2){
		cerr << "Missing argument, use image path and value";
		system("pause");
		return 0;
	}
	BaseTimer bt;
	bt.start();

	Image image(argv[1]);

	bt.stop();
	cout << "Bestand ingelezen in: " << bt.elapsedSeconds() << " seconden\n";
	bt.start();
	ColorFilter cf(image);
	cf.makeGrey();
	image = cf.getEditedImage();
	image.SaveImage("grey_watchdogs.bmp");

	AutoThreshold autoT(image);
	autoT.ThresholdCalc();
	autoT.getEditedImage().SaveImage("hoi.bmp");

	bt.stop();
	cout << "Bestand ingelezen in: " << bt.elapsedSeconds() << " seconden\n";
	system("pause");
	return 0;
}