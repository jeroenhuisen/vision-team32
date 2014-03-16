#include "stdafx.h"
#include "Matrix.h"

Matrix::Matrix(Image image){
	Matrix::image = image;
	Matrix::editedImage = image;
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

void Matrix::Transformatie(int a0, int a1, int a2, int b0, int b1, int b2){
	for (int y = 0; y < image.Height(); y++){
		for (int x = image.Width(); x >= 0; x--){
			int X = (a0 * x) + (a1 * y) + a2;
			int Y = (b0 * x) + (b1 * y) + b2;
			*image.Data(X, Y, 0) = *image.Data(x, y, 0);
			*image.Data(X, Y, 1) = *image.Data(x, y, 1);
			*image.Data(X, Y, 2) = *image.Data(x, y, 2);
		}
	}
}

void Matrix::SaveImg(const char* filename){
	editedImage.SaveImage(filename);
}