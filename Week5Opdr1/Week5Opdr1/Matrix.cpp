#include "stdafx.h"
#include "Matrix.h"

#include <iostream>

Matrix::Matrix(Image image){
	Matrix::image = image;
	//Matrix::editedImage = image; //shallow copy le fail from me
	Matrix::editedImage = Image(image.Width(), image.Height(), image.GetChannels()); //le fix
	a0 = 0;
	a1 = 0;
	a2 = 0;
	b0 = 0;
	b1 = 0;
	b2 = 0;
}

/*void Matrix::Verschuif(int dx, int dy){
	for (int i = 0; i < image.Height() + dy; i++){
		for (int h = 0; h < image.Width() + dx; h++){
			*image.Data(h + dy, i + dx, 0) = *image.Data(h, i, 0);
			*image.Data(h + dy, i + dx, 1) = *image.Data(h, i, 1);
			*image.Data(h + dy, i + dx, 2) = *image.Data(h, i, 2);
		}
	}

	/*for (int h = image.Height(); h >= 0; h--){
	//for (int h = 0; h < image.Height(); h ++){
		for (int i = image.Width(); i >= 0; i--){
			*image.Data(i + dx, h + dy, 0) = *image.Data(i, h, 0);
			*image.Data(i + dx, h + dy, 1) = *image.Data(i, h, 1);
			*image.Data(i + dx, h + dy, 2) = *image.Data(i, h, 2);
		}
	}

	for (int h = 0; h < image.Height(); h++){
		for (int i = image.Width(); i >= 0; i--){
			//int x0 = 
			*editedImage.Data(i + dx, h + dy, 0) = *image.Data(i, h, 0);
			*editedImage.Data(i + dx, h + dy, 1) = *image.Data(i, h, 1);
			*editedImage.Data(i + dx, h + dy, 2) = *image.Data(i, h, 2);
		}
	}
}*/

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
		for (int x = image.Width()-1; x >= 0; x--){
			int X = (a0 * x) + (a1 * y) + a2;
			int Y = (b0 * x) + (b1 * y) + b2;
			//std::cout << X << ' ' << Y << '\n';
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
			//for (int x = 0; x < image.Width(); x++){
			int X = x + dx;
			int Y = y + dy;
			//std::cout << X << ' ' << Y << '\n';
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
		//for (int x = 0; x < image.Width(); x++){
			int X = (cos(f) * x) - (sin(f) * y);
			int Y = (sin(f) * x) + (cos(f) * y);
			//std::cout << X << ' ' << Y << '\n';
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
			int X = s * x;
			int Y = s * y;
			//std::cout << X << ' ' << Y << '\n';
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
			//std::cout << X << ' ' << Y << '\n';
			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = *image.Data(x, y, 0);
				*editedImage.Data(X, Y, 1) = *image.Data(x, y, 1);
				*editedImage.Data(X, Y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}

/*void Matrix::AA1(){
	for (int y = 1; y < image.Height() - 1; y++){
		for (int x = 1; x < image.Width() - 1; x++){
			int gemRed = *image.Data(x- 1, y - 1, 0) + *image.Data(x, y -1, 0) + *image.Data(x - 1, y, 0) + *image.Data(x, y, 0) / 4;
			int gemGreen = *image.Data(x - 1, y - 1, 1) + *image.Data(x, y - 1, 1) + *image.Data(x - 1, y, 1) + *image.Data(x, y, 1) / 4;
			int gemBlue = *image.Data(x- 1, y - 1, 2) + *image.Data(x, y - 1, 2) + *image.Data(x - 1, y, 2) + *image.Data(x, y, 2) / 4;
			*editedImage.Data(x, y, 0) = gemRed;
			*editedImage.Data(x, y, 1) = gemGreen;
			*editedImage.Data(x, y, 2) = gemBlue;
		}
	}
}/*

/*void Matrix::AA1(){
	for (int y = 1; y < image.Height() - 1; y++){
		for (int x = 1; x < image.Width() - 1; x++){
			int pRed = *image.Data(x + 1, y + 1, 0) + (*image.Data(x + 2, y +1, 0) - *image.Data(x + 1, y + 1, 0)) * 1;
			int qRed = *image.Data(x + 1, y + 2, 0) + (*image.Data(x + 2, y + 2, 0) - *image.Data(x + 1, y + 2, 0)) * 1;
			int pGreen = *image.Data(x + 1, y + 1, 1) + (*image.Data(x + 2, y + 1, 1) - *image.Data(x + 1, y + 1, 1)) * 1;
			int qGreen = *image.Data(x + 1, y + 2, 1) + (*image.Data(x + 2, y + 2, 1) - *image.Data(x + 1, y + 2, 1)) * 1;
			int pBlue = *image.Data(x + 1, y + 1, 2) + (*image.Data(x + 2, y + 1, 2) - *image.Data(x + 1, y + 1, 2)) *1;
			int qBlue = *image.Data(x + 1, y + 2, 2) + (*image.Data(x + 2, y + 2, 2) - *image.Data(x + 1, y + 2, 2)) * 1;
			*editedImage.Data(x, y, 0) = pRed + (qRed - pRed) * 1;
			//std::cout << pRed << '\n';
			*editedImage.Data(x, y, 1) = pGreen + (qGreen - pGreen) * 1;
			*editedImage.Data(x, y, 2) = pBlue + (qBlue - pBlue) * 1;
		}
	}
}*/

/*void Matrix::RotatieAA(float f){
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
			//for (int x = 0; x < image.Width(); x++){
			float X = (cos(f) * x) - (sin(f) * y);
			float Y = (sin(f) * x) + (cos(f) * y);
			//std::cout << X << ' ' << Y << '\n';

			float R1Red = ((x + 1 - X) / (x + 1 - x) * *image.Data(x, y, 0)) + ((X - x) / (x + 1 - x) * *image.Data(x + 1, y, 0));
			float R2Red = ((x + 1 - X) / (x + 1 - x) * *image.Data(x, y + 1, 0)) + ((X - x) / (x + 1 - x) * *image.Data(x + 1, y + 1, 0));
			float PRed = ((y + 1 - Y) / (y + 1 - y) * R1Red) + ((Y - y) / (y + 1 - y) * R2Red);

			float R1Green = ((x + 1 - X) / (x + 1 - x) * *image.Data(x, y, 1)) + ((X - x) / (x + 1 - x) * *image.Data(x + 1, y, 1));
			float R2Green = ((x + 1 - X) / (x + 1 - x) * *image.Data(x, y + 1, 1)) + ((X - x) / (x + 1 - x) * *image.Data(x + 1, y + 1, 1));
			float PGreen = ((y + 1 - Y) / (y + 1 - y) * R1Red) + ((Y - y) / (y + 1 - y) * R2Red);

			float R1Blue = ((x + 1 - X) / (x + 1 - x) * *image.Data(x, y, 2)) + ((X - x) / (x + 1 - x) * *image.Data(x + 1, y, 2));
			float R2Blue = ((x + 1 - X) / (x + 1 - x) * *image.Data(x, y + 1, 2)) + ((X - x) / (x + 1 - x) * *image.Data(x + 1, y + 1, 2));
			float PBlue = ((y + 1 - Y) / (y + 1 - y) * R1Red) + ((Y - y) / (y + 1 - y) * R2Red);

			if (X >= 0 && X < image.Width() && Y >= 0 && Y < image.Height()){
				*editedImage.Data(X, Y, 0) = PRed;
				*editedImage.Data(X, Y, 1) = PGreen;
				*editedImage.Data(X, Y, 2) = PBlue;
			}
		}
	}
}*/

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
		for (int x = image.Width() - 1; x >= 0; x--){
			//for (int x = 0; x < image.Width(); x++){
			float X = (cos(f) * x) - (sin(f) * y);
			float Y = (sin(f) * x) + (cos(f) * y);
			//std::cout << X << ' ' << Y << '\n';

			float pRed = *image.Data(x, y, 0) + (*image.Data(x + 1, y, 0) - *image.Data(x, y, 0));
			float qRed = *image.Data(x, y + 1, 0) + (*image.Data(x + 1, y + 1, 0) - *image.Data(x, y + 1, 0));
			float fRed = pRed + (qRed - pRed);

			float pGreen = *image.Data(x, y, 1) + (*image.Data(x + 1, y, 1) - *image.Data(x, y, 1));
			float qGreen = *image.Data(x, y + 1, 1) + (*image.Data(x + 1, y + 1, 1) - *image.Data(x, y + 1, 1));
			float fGreen = pGreen + (qGreen - pGreen);

			float pBlue = *image.Data(x, y, 2) + (*image.Data(x + 1, y, 2) - *image.Data(x, y, 2));
			float qBlue = *image.Data(x, y + 1, 2) + (*image.Data(x + 1, y + 1, 2) - *image.Data(x, y + 1, 2));
			float fBlue = pBlue + (qBlue - pBlue);

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
	/*int p = 14 + (17 - 14);
	int q = 13 + (15 - 13);

	int p2 = 14 + (17 - 14) * 2;
	int q2 = 13 + (15 - 13) * 2;
	std::cout << p + (q - p) << '\n';
	std::cout << p2 + (q2 - p2) * 2 << '\n';*/
}