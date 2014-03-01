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

int main(int argc, char* argv[])
{
	string filename1 = argv[1];
	int filelength = 0;
	for (int i = filename1.length() - 1; i > 0; i--){
		filelength++;
		if (filename1[i] == '\\'){
			filelength--;
			break;
		}
	}
	const char * p = filename1.c_str();
	char * p2 = new char[filelength + 1];
	int x = 0;
	for (int i = filename1.length() - filelength; i < filename1.length(); i++){
		p2[x] = p[i];
		x++;
	}
	p2[filelength] = '\0';
	string filename((const char *)p2);
		CImg<unsigned char> image;
		//cimg::exception_mode(0);
		try{
			image.load(filename.c_str());
			BaseTimer bt;
			bt.start();

			Image img(image);
			Histogram h(image);
			h.makeHistogramRGB();
			/*int total = image.height() * image.width();
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
			greyfilecsv.close();*/


			h.saveHistogram(filename.c_str());

			bt.stop();
			cout << bt.elapsedSeconds();
		}
		catch (CImgIOException cioe){
			cerr << "Image not found\n";
		}
	system("pause");
	return 0;
}