// Week1Alles.cpp : Defines the entry point for the console application.
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
	cimg::exception_mode(0);
	try{
		image.load(argv[1]);
		BaseTimer bt;

		/////////////////////////////////////////////////
		/*opdr 1*/
		bt.start();
		Image img(image);
		img.makeGrey();
		Histogram h(img.getEditedImage());
		h.makeGray();
		image = img.getEditedImage();
		string newfilename = "grey_" + filename;
		image.save(newfilename.c_str());
		bt.stop();
		cout << "Grey: " << bt.elapsedSeconds() << " seconds\n";

		///////////////////////////////////////////////
		/*opdr 2*/
		bt.start();
		int total = h.getTotal();
		int * luminate256 = h.getHistogram256();
		ofstream greyfilecsv;
		newfilename = "grey256_" + filename;
		newfilename += ".csv";
		greyfilecsv.open(newfilename, ios::out | ios::binary);
		for (int i = 0; i < 256; i++){
			double test = (double)((double)luminate256[i] / ((double)total));
			greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
		}
		greyfilecsv.close();

		int * luminate10 = h.getHistogram10();
		ofstream greyfilecsv1;
		newfilename = "grey10_" + filename;
		newfilename += ".csv";
		greyfilecsv1.open(newfilename, ios::out | ios::binary);
		for (int i = 0; i < 10; i++){
			double test = (double)((double)luminate10[i] / ((double)total));
			greyfilecsv1 << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
		}
		greyfilecsv1.close();
		bt.stop();
		cout << "Histogram: " << bt.elapsedSeconds() << " seconds\n";
		//////////////////////////////////////////////
		/*opdr 3*/
		bt.start();
		h.equalize();
		int * luminateEqualized256 = h.getEqualizedHistogram256();
		ofstream greyfileEqualizedcsv;
		newfilename = "equalized_" + filename;
		newfilename += ".csv";
		greyfileEqualizedcsv.open(filename, ios::out | ios::binary);
		for (int i = 0; i < 256; i++){
			double test = (double)((double)luminateEqualized256[i] / ((double)total));
			greyfileEqualizedcsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
		}
		greyfileEqualizedcsv.close();
		bt.stop();
		cout << "Equalize: " << bt.elapsedSeconds() << " seconds\n";
		/////////////////////////////////////////
		
	}
	catch (CImgIOException cioe){
		cerr << "Image not found\n";
	}
	system("pause");
	return 0;
}