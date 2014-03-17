#include "stdafx.h"
#include "BaseTimer.h"
#include "ImageV2.h"
#include "Matrix.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	BaseTimer bt;
	Image image(argv[1]);
	bt.start();

	Matrix Mx(image);
	string newFname = "Mx_";
	newFname += image.GetFilename();
	Mx.Transformatie(1, 0, 25, 0, 1, 0);
	Mx.SaveImg(newFname.c_str());

	bt.stop();
	std::cout << bt.elapsedSeconds();

	system("pause");
	return 0;
}

