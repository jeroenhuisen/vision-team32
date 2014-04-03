// Week1Opdr1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basetimer.h"

#include "ImageV2.h"
#include "ColorFilter.h"

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

	bt.start();

	bt.stop();
	cout << "Grijs gemaakt in: " << bt.elapsedSeconds() << " seconden\n";

	bt.start();
	ColorFilter cf(image);
	cf.makeGrey();
	image = cf.getEditedImage();
	string newFilename = "grey_";
	newFilename += image.GetFilename();
	image.SaveImage(newFilename.c_str());

	bt.stop();
	cout << "Bestand opgeslagen in: " << bt.elapsedSeconds() << " seconden\n";

	system("pause");
	return 0;
}