// Median.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int *luminate;
int arraylength = 0;
int total = 0;

char* editImage(char imagedata[], int size){
	/*for (int i = 1078; i < size; i += 3){
		imagedata[i] = lum;
		imagedata[i + 1] = lum;
		imagedata[i + 2] = lum;

	}*/
	int * arrayRed = new int[9];
	int * arrayGreen = new int[9];
	int * arrayBlue = new int[9];
	int amount=0;
	for (int i = 0; i < size; i++){
		for (int y = 0; y < 9; y += 685 * 3){
			for (int x = 0; x < 9; x += 3){
				arrayRed[amount] = imagedata[i];
				arrayGreen[amount] = imagedata[i+1];
				arrayRed[amount] = imagedata[i+2];
				amount++;
			}
		}
	}
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
