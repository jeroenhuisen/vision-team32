// Week1opdr1_3Cimg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CImg.h"
#include "basetimer.h"
#include "Histogram.h"
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
			Histogram h(image);
			image = h.getImage();
			string newfilename = "grey_" + filename;
			image.save(newfilename.c_str());

			int total = h.getTotal();
			cout << total << "\n"
			<< image.height()<<"\n"
			<< image.width();
			unsigned char * luminate256 = h.getHistogram256();
			ofstream greyfilecsv;
			greyfilecsv.open("gray256.csv", ios::out | ios::binary);
			for (int i = 0; i < 256; i++){
				double test = (double)((double)luminate256[i] / ((double)total));
				greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
			}
			greyfilecsv.close();

			unsigned char * luminate10 = h.getHistogram10();
			ofstream greyfilecsv1;
			greyfilecsv1.open("gray10.csv", ios::out | ios::binary);
			for (int i = 0; i < 10; i++){
				cout << (int)luminate10[i] << "\n";
				double test = (double)((double)luminate10[i] / ((double)total));
				cout << i << "," << test << "\n";
				greyfilecsv1 << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
			}
			greyfilecsv1.close();
			

			//CImgDisplay main_disp(image, filename.c_str());
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