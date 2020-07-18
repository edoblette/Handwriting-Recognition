#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parameter.h"

void test( neural * n, params parameters){
	parameters.data_size = 10000;
		//parameter vars
	int data_size = parameters.data_size;
	int neurons_size = parameters.neurons_size;
	int image_size = parameters.data_img_size;

	vector v;
	dataAllocate(&v, parameters);
	load_mnist(&v, parameters, parameters.test_images, parameters.test_labels);

	match_unit bmu;
	int learning_score = 0;
	for(int i = 0; i < data_size; ++i){

		float lower_match_unit = euclidean_distance(v.data[i].image, n->neurons[0].image, image_size); // valeur minimum
		float result;

		for(int neuron = 0; neuron < neurons_size; ++neuron){ //start from 1 because alraeady tested for the minimum
			//euclidian distance
			result = euclidean_distance(v.data[i].image, n->neurons[neuron].image, image_size);

			// set new best match unit if lower than prevous minimum
			if(result <= lower_match_unit){
					lower_match_unit = result;
					bmu.best_neuron = neuron;
					bmu.distance = result;
			}
		}

		for(int y=0; y<784; ++y) {
			if((v.data[i].image[y] >= 0.1) && (n->neurons[bmu.best_neuron].image[y] >= 0.1 ) )
				 printf("🟠"); //printf(CLR_1 "%1.1f" RESET, data.image[number][i]);
            else if(v.data[i].image[y] >= 0.1)
                printf("🔴"); //printf(CLR_1 "%1.1f" RESET, data.image[number][i]);
            else if(n->neurons[bmu.best_neuron].image[y] >= 0.1 )
            	printf("🟢"); //printf(CLR_1 "%1.1f" RESET, data.image[number][i]);
            else
                 printf("⬜️");//printf("%1.1f", data.image[number][i]);

            if ((y+1) % 28 == 0) putchar('\n');
        }

		if(v.data[i].label == n->neurons[bmu.best_neuron].label)
			++learning_score;
		printf("test var %d %d => %d \t %d/%d\n", i , v.data[i].label, n->neurons[bmu.best_neuron].label, learning_score, i);
	}
	float pourcentage = 100 - (((float)learning_score/data_size) * 100);
	printf("Le taux d'erreur pour %d VEC de test est de %lf %%\n", data_size, pourcentage );
}