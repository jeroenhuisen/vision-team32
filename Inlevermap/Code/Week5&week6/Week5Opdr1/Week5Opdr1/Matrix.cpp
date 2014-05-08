#include "stdafx.h"
#include "Matrix.h"

#include <iostream>

Matrix::Matrix(Image image){
	Matrix::image = image;
	Matrix::editedImage = Image(image.Width(), image.Height(), image.GetChannels());
	Matrix::editedImage_2 = Image(image.Width(), image.Height(), image.GetChannels());
	Matrix::editedImage_3 = Image(image.Width(), image.Height(), image.GetChannels());
}

void Matrix::Transformatie(float a0, float a1, int a2, float b0, float b1, int b2){
	for (int y = 0; y < image.Height(); y++){
		unsigned char *p = editedImage.Data(0, y, 0);
		unsigned char *p1 = editedImage.Data(0, y, 1);
		unsigned char *p2 = editedImage.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(p + x )= 0;
			*(p1 + x) = 0;
			*(p2 + x) = 0;
		}
	}
	for (int y = 0; y < image.Height(); y++){
		for (int x = 0; x < image.Width(); x++){
			float X = (a0 * x) + (a1 * y) + a2;
			float Y = (b0 * x) + (b1 * y) + b2;
			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = *image.Data(x, y, 0);
				*editedImage.Data(X, Y, 1) = *image.Data(x, y, 1);
				*editedImage.Data(X, Y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}

void Matrix::Translatie(int dx, int dy){
	for (int y = 0; y < image.Height(); y++){
		unsigned char *p = editedImage.Data(0, y, 0);
		unsigned char *p1 = editedImage.Data(0, y, 1);
		unsigned char *p2 = editedImage.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(p + x) = 0;
			*(p1 + x) = 0;
			*(p2 + x) = 0;
		}
	}

	for (int y = 0; y < image.Height(); y++){
		for (int x = image.Width() - 1; x >= 0; x--){
			int X = x + dx;
			int Y = y + dy;
			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = *image.Data(x, y, 0);
				*editedImage.Data(X, Y, 1) = *image.Data(x, y, 1);
				*editedImage.Data(X, Y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}

void Matrix::Rotatie(float f){
	for (int y = 0; y < image.Height(); y++){
		unsigned char *p = editedImage.Data(0, y, 0);
		unsigned char *p1 = editedImage.Data(0, y, 1);
		unsigned char *p2 = editedImage.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(p + x) = 0;
			*(p1 + x) = 0;
			*(p2 + x) = 0;
		}
	}
	for (int y = 0; y < image.Height(); y++){
		for (int x = image.Width() - 1; x >= 0; x--){
			float X = (cos(f) * x) - (sin(f) * y);
			float Y = (sin(f) * x) + (cos(f) * y);
			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = *image.Data(x, y, 0);
				*editedImage.Data(X, Y, 1) = *image.Data(x, y, 1);
				*editedImage.Data(X, Y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}

void Matrix::Scaling(float s){
	for (int y = 0; y < image.Height(); y++){
		unsigned char *p = editedImage.Data(0, y, 0);
		unsigned char *p1 = editedImage.Data(0, y, 1);
		unsigned char *p2 = editedImage.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(p + x) = 0;
			*(p1 + x) = 0;
			*(p2 + x) = 0;
		}
	}
	for (int y = 0; y < image.Height(); y++){
		for (int x = image.Width() - 1; x >= 0; x--){
			float X = s * x;
			float Y = s * y;
			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = *image.Data(x, y, 0);
				*editedImage.Data(X, Y, 1) = *image.Data(x, y, 1);
				*editedImage.Data(X, Y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}

void Matrix::Shear(float s){
	for (int y = 0; y < image.Height(); y++){
		unsigned char *p = editedImage.Data(0, y, 0);
		unsigned char *p1 = editedImage.Data(0, y, 1);
		unsigned char *p2 = editedImage.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(p + x) = 0;
			*(p1 + x) = 0;
			*(p2 + x) = 0;
		}
	}
	for (int y = 0; y < image.Height(); y++){
		for (int x = image.Width() - 1; x >= 0; x--){
			int X =  x + (s * y);
			int Y =  y;
			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = *image.Data(x, y, 0);
				*editedImage.Data(X, Y, 1) = *image.Data(x, y, 1);
				*editedImage.Data(X, Y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}


void Matrix::RotatieAA(float f){
	for (int y = 0; y < image.Height(); y++){
		unsigned char *p = editedImage.Data(0, y, 0);
		unsigned char *p1 = editedImage.Data(0, y, 1);
		unsigned char *p2 = editedImage.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(p + x) = 0;
			*(p1 + x) = 0;
			*(p2 + x) = 0;
		}
	}
	for (int y = 0; y < image.Height(); y++){
		for (int x = 0; x < image.Width(); x++){
			float X = (cos(f) * x) - (sin(f) * y);
			float Y = (sin(f) * x) + (cos(f) * y);
			int a = X;
			int b = Y;
			float dx = X - a;
			float dy = Y - b;

			float pRed = *image.Data(x, y, 0) + (*image.Data(x - 1, y, 0) - *image.Data(x, y, 0)) * dx;
			float qRed = *image.Data(x, y - 1, 0) + (*image.Data(x - 1, y - 1, 0) - *image.Data(x, y - 1, 0)) * dy;
			float fRed = pRed + (qRed - pRed) * dy;

			float pGreen = *image.Data(x, y, 1) + (*image.Data(x - 1, y, 1) - *image.Data(x, y, 1)) * dx;
			float qGreen = *image.Data(x, y - 1, 1) + (*image.Data(x - 1, y - 1, 1) - *image.Data(x, y - 1, 1)) * dy;
			float fGreen = pGreen + (qGreen - pGreen) * dy;

			float pBlue = *image.Data(x, y, 2) + (*image.Data(x - 1, y, 2) - *image.Data(x, y, 2)) * dx;
			float qBlue = *image.Data(x, y - 1, 2) + (*image.Data(x - 1, y - 1, 2) - *image.Data(x, y - 1, 2)) * dy;
			float fBlue = pBlue + (qBlue - pBlue) * dy;

			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = fRed;
				*editedImage.Data(X, Y, 1) = fGreen;
				*editedImage.Data(X, Y, 2) = fBlue;
			}
		}
	}
}

void Matrix::Three_Way_Shear(float s){
	float X;
	float Y;
	for (int y = 0; y < image.Height(); y++){
		unsigned char *h = editedImage_2.Data(0, y, 0);
		unsigned char *h1 = editedImage_2.Data(0, y, 1);
		unsigned char *h2 = editedImage_2.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(h + x) = 0;
			*(h1 + x) = 0;
			*(h2 + x) = 0;
		}
	}
	for (int y = 0; y < image.Height(); y++){
		for (int x = 0; x < image.Width(); x++){
			X = x + (-tan(s / 2) * y);
			Y = y;
			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage_2.Data(X, Y, 0) = *image.Data(x, y, 0);
				*editedImage_2.Data(X, Y, 1) = *image.Data(x, y, 1);
				*editedImage_2.Data(X, Y, 2) = *image.Data(x, y, 2);

			}
		}
	}
	
	for (int y = 0; y < image.Height(); y++){
		unsigned char *e = editedImage_3.Data(0, y, 0);
		unsigned char *e1 = editedImage_3.Data(0, y, 1);
		unsigned char *e2 = editedImage_3.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(e + x) = 0;
			*(e1 + x) = 0;
			*(e2 + x) = 0;
		}
	}


	for (int y = 0; y < image.Height(); y++){
		for (int x = 0; x < image.Width(); x++){
			X = x;
			Y = (sin(s) * x) + y;
			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage_3.Data(X, Y, 0) = *editedImage_2.Data(x, y, 0);
				*editedImage_3.Data(X, Y, 1) = *editedImage_2.Data(x, y, 1);
				*editedImage_3.Data(X, Y, 2) = *editedImage_2.Data(x, y, 2);
			}
		}
	}


	for (int y = 0; y < image.Height(); y++){
		unsigned char *p = editedImage.Data(0, y, 0);
		unsigned char *p1 = editedImage.Data(0, y, 1);
		unsigned char *p2 = editedImage.Data(0, y, 2);
		for (int x = 0; x < image.Width(); x++){
			*(p + x) = 0;
			*(p1 + x) = 0;
			*(p2 + x) = 0;
		}
	}

	for (int y = 0; y < image.Height(); y++){
		for (int x = 0; x < image.Width(); x++){
			X = x + (-tan(s / 2) * y);
			Y = y;

			int a = X;
			int b = Y;
			float dx = X - a;
			float dy = Y - b;

			float pRed = *editedImage_3.Data(x, y, 0) + (*editedImage_3.Data(x - 1, y, 0) - *editedImage_3.Data(x, y, 0)) * dx;
			float qRed = *editedImage_3.Data(x, y - 1, 0) + (*editedImage_3.Data(x - 1, y - 1, 0) - *editedImage_3.Data(x, y - 1, 0)) * dy;
			float fRed = pRed + (qRed - pRed) * dy;

			float pGreen = *editedImage_3.Data(x, y, 1) + (*editedImage_3.Data(x - 1, y, 1) - *editedImage_3.Data(x, y, 1)) * dx;
			float qGreen = *editedImage_3.Data(x, y - 1, 1) + (*editedImage_3.Data(x - 1, y - 1, 1) - *editedImage_3.Data(x, y - 1, 1)) * dy;
			float fGreen = pGreen + (qGreen - pGreen) * dy;

			float pBlue = *editedImage_3.Data(x, y, 2) + (*editedImage_3.Data(x - 1, y, 2) - *editedImage_3.Data(x, y, 2)) * dx;
			float qBlue = *editedImage_3.Data(x, y - 1, 2) + (*editedImage_3.Data(x - 1, y - 1, 2) - *editedImage_3.Data(x, y - 1, 2)) * dy;
			float fBlue = pBlue + (qBlue - pBlue) * dy;

			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = fRed;
				*editedImage.Data(X, Y, 1) = fGreen;
				*editedImage.Data(X, Y, 2) = fBlue;
			}
		}
	}
}




void Matrix::SaveImg(const char* filename){
	editedImage.SaveImage(filename);
}