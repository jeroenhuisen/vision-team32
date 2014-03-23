// THO7OverExposure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ImageV2.h"
#include "ColorSpace.h"
#include "OverExposure.h"


int main(int argc, char* argv[])
{
	Image img(argv[1]);

	ColorSpace cs(img);
	cs.ToXYZ();
	cs.ToLAB();
	OverExposure oe(img);
	oe.M();
	oe.Threshold(250);
	oe.ThresholdRepair(250);
	system("pause");
	return 0;
}

