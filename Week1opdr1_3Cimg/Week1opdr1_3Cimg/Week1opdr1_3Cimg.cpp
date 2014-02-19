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
			int * luminate256 = h.getHistogram256();
			ofstream greyfilecsv;
			greyfilecsv.open("gray256.csv", ios::out | ios::binary);
			for (int i = 0; i < 256; i++){
				double test = (double)((double)luminate256[i] / ((double)total));
				greyfilecsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
			}
			greyfilecsv.close();

			int * luminate10 = h.getHistogram10();
			ofstream greyfilecsv1;
			greyfilecsv1.open("gray10.csv", ios::out | ios::binary);
			for (int i = 0; i < 10; i++){
				double test = (double)((double)luminate10[i] / ((double)total));
				greyfilecsv1 << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
			}
			greyfilecsv1.close();
			

			//CImgDisplay main_disp(image, filename.c_str());
			h.equalize();
			int * luminateEqualized256 = h.getEqualizedHistogram256();
			ofstream greyfileEqualizedcsv;
			greyfileEqualizedcsv.open("gray256Equalized.csv", ios::out | ios::binary);
			for (int i = 0; i < 256; i++){
				double test = (double)((double)luminateEqualized256[i] / ((double)total));
				greyfileEqualizedcsv << i << "," << setprecision(10) << fixed << showpoint << test << "\n";
			}
			greyfileEqualizedcsv.close();


			CImg<unsigned char> equalizedImage = h.getEqualizedImage();
			equalizedImage.save(("equalize_" + filename).c_str());

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