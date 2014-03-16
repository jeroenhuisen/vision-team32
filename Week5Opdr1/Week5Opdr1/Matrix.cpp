#include "stdafx.h"
#include "Matrix.h"

Matrix::Matrix(Image image){
	Matrix::image = image;
	Matrix::editedImage = image;
	a0 = 0;
	b0 = 0;
	a1 = 0;
	b1 = 0;
}

void Matrix::Verschuif(int dx, int dy){
	/*for (int i = 0; i < image.Height() + dy; i++){
		for (int h = 0; h < image.Width() + dx; h++){
			*image.Data(h + dy, i + dx, 0) = *image.Data(h, i, 0);
			*image.Data(h + dy, i + dx, 1) = *image.Data(h, i, 1);
			*image.Data(h + dy, i + dx, 2) = *image.Data(h, i, 2);
		}
	}*/

	/*for (int h = image.Height(); h >= 0; h--){
	//for (int h = 0; h < image.Height(); h ++){
		for (int i = image.Width(); i >= 0; i--){
			*image.Data(i + dx, h + dy, 0) = *image.Data(i, h, 0);
			*image.Data(i + dx, h + dy, 1) = *image.Data(i, h, 1);
			*image.Data(i + dx, h + dy, 2) = *image.Data(i, h, 2);
		}
	}*/

	for (int h = 0; h < image.Height(); h++){
		for (int i = image.Width(); i >= 0; i--){
			//int x0 = 
			*editedImage.Data(i + dx, h + dy, 0) = *image.Data(i, h, 0);
			*editedImage.Data(i + dx, h + dy, 1) = *image.Data(i, h, 1);
			*editedImage.Data(i + dx, h + dy, 2) = *image.Data(i, h, 2);
		}
	}
}



void Matrix::SaveImg(const char* filename){
	editedImage.SaveImage(filename);
}