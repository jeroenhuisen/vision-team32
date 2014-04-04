// Week3Opdr1.cpp : Defines the entry point for the console application.
//

// Week3verbeterCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basetimer.h"

#include "ImageV2.h"
#include "KMeansClustering.h"
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

	KMeansClustering kmc(image, atoi(argv[2]));
	kmc.clusterRGB();
	kmc.getEditedImage().SaveImage("henk.bmp");
	bt.stop();
	cout << "KMeansClustering in: " << bt.elapsedSeconds() << " seconden\n";
	system("pause");
	return 0;
}