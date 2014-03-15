#include "stdafx.h"
#include "KMeansClustering.h"
#include <random>
#include <string>

KMeansClustering::KMeansClustering(Image img, int k) : Filter(img){
	image = img;
	editedImage = img;
	kValue = k;
}

void KMeansClustering::clusterRGB(){
	//init: choose k random pixel values as means
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, image.Width() - 1); // pick x coordinate
	std::uniform_int_distribution<> distr2(0, image.Height() - 1); // pick y coordinate

	cluster = new unsigned char*[kValue];
	for (int i = 0; i < kValue; i++){
		cluster[i] = new unsigned char[3];
	}
	int i = 0;
	while (i < kValue){
		int x = distr(eng);
		int y = distr2(eng);

		cluster[i][0] = *image.Data(x, y, 0);
		cluster[i][1] = *image.Data(x, y, 1);
		cluster[i][2] = *image.Data(x, y, 2);
		i++; //maybe there should be a check that this aren't the same values. so the clusters aren't  the same
	}

	//assign pixels to cluster
	//while (!stop){//average doesn't change anymore
		for (int y = 0; y < image.Height(); y++){
			for (int x = 0; x < image.Width(); x++){
				int lowestDifference = abs(cluster[0][0] - *image.Data(x, y, 0)) + abs(cluster[0][1] - *image.Data(x, y, 1)) + abs(cluster[0][2] - *image.Data(x, y, 2));
				int lowestDifferenceCluster = 0;
				for (int k = 0; k < kValue; k++){
					if (abs(cluster[k][0] - *image.Data(x, y, 0)) + abs(cluster[k][1] - *image.Data(x, y, 1)) + abs(cluster[k][2] - *image.Data(x, y, 2)) < lowestDifference){
						lowestDifferenceCluster = k;
					}
				}
				//assign each pixel(from image data) to the nearest mean  
				*editedImage.Data(x, y, 0) = cluster[lowestDifferenceCluster][0];
				*editedImage.Data(x, y, 1) = cluster[lowestDifferenceCluster][1];
				*editedImage.Data(x, y, 2) = cluster[lowestDifferenceCluster][2];
			}
		}
		std::string filename = "Cluster_ ";
		filename += image.GetFilename();
		editedImage.SaveImage( filename.c_str() );
		/*for (int j = 0; j < kValue; j++){
			mean of cluster j ← mean of all
			pixels with label j
		}*/
	//}


	//final: change all pixels colors to match color of the 
	//cluster mean
}