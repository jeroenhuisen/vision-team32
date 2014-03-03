// Week1opdr1CImg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CImg.h"
#include "basetimer.h"
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
		bt.start();
		Image img(image);
		img.makeGrey();
		image = img.getEditedImage();
		string newfilename = "grey_" + filename;
		image.save(newfilename.c_str());

		bt.stop();
		cout << bt.elapsedSeconds();
	}
	catch (CImgIOException cioe){
		cerr << "Image not found\n";
	}
	system("pause");
	return 0;
}