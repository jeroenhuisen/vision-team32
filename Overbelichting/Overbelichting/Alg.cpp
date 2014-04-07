#include "stdafx.h"
#include "Alg.h"

#include <iostream>

using namespace std;

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
				/*cout << temp_blue_1 << '\n';
				cout << temp_blue_2 << '\n';
				cout << '\n';*/
				*editedImage.Data(x, y, 0) = 255;
				*editedImage.Data(x, y, 1) = 255;
				*editedImage.Data(x, y, 2) = 255;
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

void Alg::Gradiant(int threshold, int l_b_x, int l_b_y, int r_o_x, int l_o_y){
	int wit_tellen = 0;
	for (int y = l_b_y; y < l_o_y; y++){
		unsigned char *p = editedImage.Data(0, y, 0);
		unsigned char *p1 = editedImage.Data(0, y, 1);
		unsigned char *p2 = editedImage.Data(0, y, 2);
		for (int x = l_b_x; x < r_o_x; x++){
			*(p + x) = 0;
			*(p1 + x) = 0;
			*(p2 + x) = 0;
		}
	}

	for (int y = l_b_y; y < l_o_y; y++){
		for (int x = l_b_x; x < r_o_x; x++){
			int xGradient = *image.Data(x - 1, y + 1, 2) + *image.Data(x - 1, y, 2) * 2 + *image.Data(x - 1, y - 1, 2) - *image.Data(x + 1, y + 1, 2) - *image.Data(x + 1, y, 2) * 2 - *image.Data(x + 1, y - 1, 2);
			int yGradient = *image.Data(x - 1, y - 1, 2) + *image.Data(x, y - 1, 2) * 2 + *image.Data(x + 1, y - 1, 2) - *image.Data(x + 1, y + 1, 2) - *image.Data(x, y + 1, 2) * 2 - *image.Data(x - 1, y + 1, 2);

			int sum = abs(xGradient) + abs(yGradient);

			if (sum > 255){
				sum = 255;
			}

			else if (sum < 0){
				sum = 0;
			}

			if (sum >= threshold){
				for (int h = y - 12; h < y + 12; h++){
					for (int w = x - 12; w < x + 12; w++){
						if ((*image.Data(w, h, 2) > 200)){
							//wit_tellen++;
							*editedImage.Data(w, h, 0) = 255;
							*editedImage.Data(w, h, 1) = 0;
							*editedImage.Data(w, h, 2) = 0;
						}
						else{
							*editedImage.Data(w, h, 0) = *image.Data(w, h, 0);
							*editedImage.Data(w, h, 1) = *image.Data(w, h, 1);
							*editedImage.Data(w, h, 2) = *image.Data(w, h, 2);
						}
					}
				}
				//cout << wit_tellen << '\n';
			}

			else{
				*editedImage.Data(x, y, 0) = *image.Data(x, y, 0);
				*editedImage.Data(x, y, 1) = *image.Data(x, y, 1);
				*editedImage.Data(x, y, 2) = *image.Data(x, y, 2);
			}
		}
	}
}