// Week1opdr4.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "CImg.h"
#include "basetimer.h"
#include "Histogram.h"
#include "Image.h"
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
			/*Histogram h(image);
			h.makeRed();
			image = h.getImage();
			string newfilename = "R_" + filename;
			image.save(newfilename.c_str());*/

			Image img(image);
			img.makeRed();
			image = img.getEditedImage();
			image.save(("R_" + filename).c_str());
			img.makeGreen();
			image = img.getEditedImage();
			image.save(("G_" + filename).c_str());
			img.makeBlue();
			image = img.getEditedImage();
			image.save(("B_" + filename).c_str());


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