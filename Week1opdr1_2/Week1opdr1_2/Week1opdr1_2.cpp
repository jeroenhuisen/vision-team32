// Week1opdr1_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int *luminate;
int arraylength = 0;
int total = 0;

char* editImage(char imagedata[], int size){
	unsigned char lum;
	unsigned char lum2;
	luminate = new int[256];
	for (int i = 0; i < 256; i++){
		luminate[i] = 0;
	}
	for (int i = 1078; i < size; i += 3){
		//lum2 = (unsigned char)((0.3086 *imagedata[i]) + (0.6094 * imagedata[i + 1]) + (0.0820 * imagedata[i + 2]));
		lum = (unsigned char)(((unsigned char)imagedata[i] * 0.30) + ((unsigned char)imagedata[i + 1] * 0.59) + ((unsigned char)imagedata[i + 2] * 0.11));

		imagedata[i] = lum;
		imagedata[i + 1] = lum;
		imagedata[i + 2] = lum;
		luminate[lum]++;
		arraylength++;
		total += lum;
		//imagedata[i] = 200;
	}
	cout << luminate[0];
	ofstream greyfile;
	greyfile.open("henk.csv", ios::out | ios::binary);
	for (int i = 0; i < 256; i++){
		float test = (float)luminate[i] / total;
		greyfile <<"\""<< i<<"\","<< test<< "\n";
	}
	greyfile.close();

	return imagedata;
}

int main()
{
	string filename;
	bool filefound = false;
	while (filefound != true){
		cout << "Please give the filename of bmp file: ";
		cin >> filename;
		ifstream file;
		if (filename[filename.length() - 4] == '.' && filename[filename.length() - 3] == 'b' && filename[filename.length() - 2] == 'm' && filename[filename.length() - 1] == 'p'){
			file.open(filename, ios::in | ios::binary | ios::ate);
			if (file.is_open()){
				filefound = true;
				int size = file.tellg();
				cout << size << " groot is het bestand\n";
				char* memblock = new char[size];
				file.seekg(0, ios::beg);
				file.read(memblock, size);
				file.close();
				editImage(memblock, size);
				ofstream greyfile;
				greyfile.open("grey_" + filename, ios::out | ios::binary);
				greyfile.write(memblock, size);
				greyfile.close();
				delete[] memblock;
			}
			else cout << "Unable to open file\n";
		}
		else cout << "not a .bmp file\n";

	}
	system("pause");
	return 0;
}
