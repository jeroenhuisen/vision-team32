// Week1opdr1_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string filename;
	bool filefound = false;
	while (filefound != true){
		cout << "Please give the filename: ";
		cin >> filename;
		ifstream file;
		file.open(filename, ios::in | ios::binary | ios::ate);
		if (file.is_open()){
			filefound = true;
			int size = file.tellg();
			cout << size << " groot is het bestand\n";
			char* memblock = new char[size];
			file.seekg(0, ios::beg);
			file.read(memblock, size);
			file.close();
			cout << memblock;
			ofstream greyfile;
			greyfile.open("grey_" + filename, ios::out | ios::binary);
			greyfile.write(memblock,size);
			greyfile.close();
			delete[] memblock;
		}
		else cout << "Unable to open file\n";
		
	}
	system("pause");
	return 0;
}

