#include "stdafx.h"
#include "ColorSpace.h"

ColorSpace::ColorSpace(Image img):Filter(img){
}


int* ColorSpace::RGBtoXYZ(unsigned char R, unsigned char G, unsigned char B)
{
	double var_R = (double)((double)R / (double)255);        //R from 0 to 255
	double var_G = (double)((double)G / (double)255);        //G from 0 to 255
	double var_B = (double)((double)B / (double)255);        //B from 0 to 255

	if (var_R > 0.04045){
		var_R = pow(((var_R + 0.055) / 1.055), 2.4);
	}
	else{
		var_R = var_R / 12.92;
	}
	if (var_G > 0.04045){
		var_G = pow(((var_G + 0.055) / 1.055), 2.4);
	}
	else{
		var_G = var_G / 12.92;
	}
	if (var_B > 0.04045){
		var_B = pow(((var_B + 0.055) / 1.055), 2.4);
	}
	else{
		var_B = var_B / 12.92;
	}

	var_R = var_R * 100;
	var_G = var_G * 100;
	var_B = var_B * 100;

	//Observer. = 2°, Illuminant = D65
	int * returnValue = new int[3];
	returnValue[0] = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
	returnValue[1] = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
	returnValue[2] = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;

 
	return returnValue;
}

void ColorSpace::ToXYZ(){
	for (int y = 0; y < image.Height(); y++){
		for (int x = 0; x < image.Width(); x++){
			int* test = RGBtoXYZ(*image.Data(x, y, 0), *image.Data(x, y, 1), *image.Data(x, y, 2));
			*editedImage.Data(x, y, 0) = test[0];
			*editedImage.Data(x, y, 1) = test[1];
			*editedImage.Data(x, y, 2) = test[2];
		}
	}
	editedImage.SaveImage("testXYZ.bmp");
}

int * ColorSpace::XYZtoLAB(unsigned char x, unsigned char y, unsigned char z)
{
	float ref_X = 95.047;
	float ref_Y = 100.000;
	float ref_Z = 108.883;

	float var_X = (float)x / (float)ref_X;          //ref_X =  95.047   Observer= 2°, Illuminant= D65
	float var_Y = (float)y / (float)ref_Y;          //ref_Y = 100.000
	float var_Z = (float)z / (float)ref_Z;          //ref_Z = 108.883

	if (var_X > 0.008856){
		var_X = pow(var_X,(1.0 / 3.0));
	}
	else{
		var_X = (7.787 * var_X) + (16.0 / 116.0);
	}
	if (var_Y > 0.008856){
		var_Y = pow(var_Y,(1.0 / 3.0));
	}
	else{
		var_Y = (7.787 * var_Y) + (16.0 / 116.0);
	}
	if (var_Z > 0.008856){
		var_Z = pow(var_Z, (1.0 / 3.0));
	}
	else{
		var_Z = (7.787 * var_Z) + (16.0 / 116.0);
	}

	int* returnValue = new int[3];
	returnValue[0] = (116 * var_Y) - 16;
	returnValue[1] = 500 * (var_X - var_Y);
	returnValue[2] = 200 * (var_Y - var_Z);

	return	returnValue;
}

void ColorSpace::ToLAB(){
	for (int y = 0; y < image.Height(); y++){
		for (int x = 0; x < image.Width(); x++){
			int* test = RGBtoXYZ(*image.Data(x, y, 0), *image.Data(x, y, 1), *image.Data(x, y, 2));
			int* test2 = XYZtoLAB(test[0], test[1], test[2]);
			*editedImage.Data(x, y, 0) = test2[0];
			*editedImage.Data(x, y, 1) = test2[1];
			*editedImage.Data(x, y, 2) = test2[2];
		}
	}
	editedImage.SaveImage("testLAB.bmp");
}




