#include "stdafx.h"
#include "Image.h"
#include "Alg.h"
#include "BaseTimer.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	BaseTimer bt;
	Image image(argv[1]);
	bt.start();

	Alg Ag(image);
	string newFname = "Beter_";
	newFname += image.GetFilename();
	//Ag.Laplacian();
	Ag.Gradiant(50, 145, 145, 605, 235);
	Ag.SaveImg(newFname.c_str());
	

	bt.stop();
	cout << bt.elapsedSeconds() << '\n';

	system("pause");
	return 0;
}

