// Week1opdr5.cpp : Defines the entry point for the console application.
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

			Image img(image);
			Histogram h(image);
			h.makeHistogramRGB();
			int total = image.height() * image.width();
			int* luminate10 = h.getHistogramRed10();
			ofstream greyfilecsv;
			greyfilecsv.open("HistogramRed10.csv", ios::out | ios::binary);
			for (int i = 0; i < 10; i++){
				double test = (double)((double)luminate10[i] / ((double)total));
				greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
			}
			greyfilecsv.close();

			luminate10 = h.getHistogramGreen10();
			greyfilecsv.open("HistogramGreen10.csv", ios::out | ios::binary);
			for (int i = 0; i < 10; i++){
				double test = (double)((double)luminate10[i] / ((double)total));
				greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
			}
			greyfilecsv.close();

			luminate10 = h.getHistogramBlue10();
			greyfilecsv.open("HistogramBlue10.csv", ios::out | ios::binary);
			for (int i = 0; i < 10; i++){
				double test = (double)((double)luminate10[i] / ((double)total));
				greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
			}
			greyfilecsv.close();

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