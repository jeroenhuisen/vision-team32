#include "stdafx.h"
#include "Alg.h"

Alg::Alg(Image image){
	Alg::image = image;
	Alg::editedImage = Image(image.Width(), image.Height(), image.GetChannels());
}

void Alg::SaveImg(const char* filename){
	editedImage.SaveImage(filename);
}

void Alg::Blue(int maxBlue){
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
			*editedImage.Data(x, y, 0) = *image.Data(x, y, 0);
			*editedImage.Data(x, y, 1) = *image.Data(x, y, 1);
			if (*image.Data(x, y, 2) >= maxBlue){
				*editedImage.Data(x, y, 2) = *image.Data(x, y, 2) - 175;
			}
			else{
				*editedImage.Data(x, y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}

void Alg::Laplacian(){
	int temp_blue_1;
	int temp_blue_2;
	for (int y = 1; y < image.Height() - 1; y++){
		for (int x = 1; x < image.Width() - 1; x++){
			int temp_blue_1 = *image.Data(x + 1, y, 2) + *image.Data(x - 1, y, 2) - 2 * *image.Data(x, y, 2);
			int temp_blue_2 = *image.Data(x + 2, y, 2) + *image.Data(x, y, 2) - 2 * *image.Data(x + 1, y, 2);
			if ((temp_blue_1) < 0 && (temp_blue_2 > 0) || (temp_blue_1 > 0) && (temp_blue_2 < 0)){
				*editedImage.Data(x, y, 0) = 255;
				*editedImage.Data(x, y, 1) = 255;
				*editedImage.Data(x, y, 1) = 255;
				/**editedImage.Data(x + 1, y, 0) = 255;
				*editedImage.Data(x + 1, y, 1) = 0;
				*editedImage.Data(x + 1, y, 1) = 0;*/
			}
			else{
				*editedImage.Data(x, y, 0) = *image.Data(x, y, 0);
				*editedImage.Data(x, y, 1) = *image.Data(x, y, 1);
				*editedImage.Data(x, y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}