// Week1Opdr2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basetimer.h"

#include "ImageV2.h"
#include "SaltAndPeppah.h"

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
	

	bt.stop();
	cout << "Noise toegevoegd en opgeslagen in: " << bt.elapsedSeconds() << " seconden\n";
	bt.reset();
	
	btTotal.stop();
	cout << "Totaal duurde alles: " << btTotal.elapsedSeconds() << " seconden\n";

	system("pause");
	return 0;
}