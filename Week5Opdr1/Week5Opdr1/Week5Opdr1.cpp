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
	//Mx.Transformatie(1.5, 0, 0, 0, 1.5, 0);
	//Mx.Rotatie(0.2);
	//Mx.Scaling(-0.25);
	//Mx.Translatie(-50, 25);
	//Mx.Shear(0.5);
	//Mx.AA1();
	Mx.RotatieAA(0.2);
	//Mx.Three_Way_Shear(0.2);
	//Mx.Scaling_And_Rotation(3.5, 0.2);
	Mx.SaveImg(newFname.c_str());

	bt.stop();
	cout << bt.elapsedSeconds() << '\n';

	system("pause");
	return 0;
}

