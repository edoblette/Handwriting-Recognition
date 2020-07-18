
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "parameter.h"
#include "./digit/digit.h"

//Func

int main(int argc, char *argv[]){

	if(argc <= 5){
		printf("Incorrect settings - usage ./main DATASIZE Xsize Ysize Appr1(apprentisage) Appr2(apprentisage) (-V erbose)\n");
		return 0;
 	}


	srand((unsigned int)time(NULL));

	params parameters = { .data_size = atoi(argv[1]),
						  .data_img_size = 784,
						  .len_info_img = 4, 
						  .len_info_label = 2,
						  .neurons_size = atoi(argv[2]) * atoi(argv[3]), //5 * sqrt(parameters.data_size), 
						  .row = atoi(argv[2]),
						  .column = atoi(argv[3]),
						  .usage = 0,
						  .train_images = "./data/train-images.idx3-ubyte",
						  .train_labels = "./data/train-labels.idx1-ubyte",
						  .test_images = "./data/t10k-images.idx3-ubyte",
						  .test_labels = "./data/t10k-labels.idx1-ubyte"
						};

	if(argc > 6){
		if(!strcmp(argv[6], "-V")){
			if(argc > 7)
				parameters.test = atoi(argv[7]);
	 		else
	 			parameters.test = 0;

	 		parameters.usage = 1;
		}
	}
	
	vector data;
	neural network;
	int * data_flow = malloc(parameters.data_size * sizeof(int));
	match_unit * bmu; // {{0}}; //only 60 

	allocate_memory(&data, &network, parameters);
	load_mnist(&data, parameters, parameters.train_images, parameters.train_labels);
	vectorNormalize(&data, parameters);
	print_dataSet(data, 10);
	vectorNeuralInit(&data, &network, parameters);
        
	bmu = learning(&data, &network, data_flow, parameters, atoi(argv[4]), 0.9, 3 );
	bmu = learning(&data, &network, data_flow, parameters, atoi(argv[5]), 0.09, 1);

	labeling(&data, &network, data_flow, bmu, parameters, FALSE);
	printf("NEURAL NETWORK\n");
	printNeuralNetwork(network, parameters, 0);

	test(&network, parameters);


	return 1;
}