#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tool.h"
#include "parameter.h"


/* Calculate Euclidean distance between each item of vecteur
 * @param vector of data Item, vector of neuron Item, size of vector
 */
float euclidean_distance(unsigned char * d_item, unsigned char * n_item, int size) {
    float sqrt_sum = 0;
    for (int i = 0; i < size; i++){
        	sqrt_sum += (d_item[i] - n_item[i]) * (d_item[i] - n_item[i]);
    }
    return sqrt(sqrt_sum);
}


match_unit * learning(vector * v , neural * n, int * data_flow, params parameters, int learning, float l_default, int learning_area){

	//parameter vars
	int data_size = parameters.data_size;
	int neurons_size = parameters.neurons_size;
	int image_size = parameters.data_img_size;

	// array of best match unit
	match_unit * bmu =  calloc(parameters.data_size, sizeof(match_unit));
	for(size_t i=0; i < parameters.data_size; ++i)
		bmu[i].best_neuron = -1;

	for(int step=0; step < learning; ++step){
		printf("s:%d\n", step);
		dataRandomize(data_flow, parameters.data_size);
		//for 150 ;
		for(int data = 0; data < data_size; ++data){ 
			//printf("elapsed %d / %d\n",data, data_size );
			//choose data from dataflow index
			int shuffle_data = data_flow[data];
			//set best match unit 

			float lower_match_unit = euclidean_distance(v->data[shuffle_data].image, n->neurons[0].image, image_size); // valeur minimum
			float result;

			for(int neuron = 0; neuron < neurons_size; ++neuron){ //start from 1 because alraeady tested for the minimum

				//printf("Learn s:%d d:%d n:%d\n", step, data, neuron );
				//euclidian distance
				result = euclidean_distance(v->data[shuffle_data].image, n->neurons[neuron].image, image_size);
				//printf("lower match_unit = %f\n", lower_match_unit );
				// set new best match unit if lower than prevous minimum
				if(result <= lower_match_unit){
					bmu[shuffle_data].best_neuron =  neuron;
					lower_match_unit = result;
				}
			}

			neighborhood_improving(v->data[shuffle_data], n, parameters, bmu[shuffle_data].best_neuron, step, learning, l_default, learning_area);
		}

		if(parameters.usage == 1)
			labeling(v , n, data_flow, bmu,  parameters, TRUE);
	}

	return bmu;
}

void labeling(vector * v , neural * n, int * data_flow,  match_unit * bmu, params parameters, int isDisplay){
		//parameter vars
		int data_size = parameters.data_size;
		int neurons_size = parameters.neurons_size;

		dataRandomize(data_flow, parameters.data_size);

		// check bmu accuracy
		for(int data = 0; data < data_size; ++data){

			int shuffle_data = data_flow[data];
			int best_neuron = bmu[shuffle_data].best_neuron;
			//printf("best[%d]= %d\n", data, best_neuron);
			n->neurons[best_neuron].label = v->data[shuffle_data].label;
			n->neurons[best_neuron].count++;	
		}

		if(parameters.usage == 1){
			printNeuronAppreciation(*n, parameters, parameters.test);
			//printf("Verbose labbeling - neuron weight print out\n");
			printNeuralNetwork(*n, parameters, 0);
		}

		if(isDisplay){
			for(int neuron = 0; neuron < neurons_size; ++neuron){
				//printf("neuron %d = %d\n", neuron,  n->neurons[neuron].id);
				n->neurons[neuron].label = -1;
				n->neurons[neuron].count = 0;
			}
		}
}


void neighborhood_improving(digit data , neural * n, params parameters, int bmu, int step, int learning, float l_default, int learning_area){
	//parameter var
	int image_size = parameters.data_img_size;

	float learning_rate = l_default * exp(-(float)step/learning);
	//printf("LR %f\n", learning_rate);
	//distance var
	int bmu_X =  n->neurons[bmu].row;
	int bmu_Y =  n->neurons[bmu].column;
	int l_a_start = -(learning_area);
	int l_a_end = (learning_area << 1);

		//printf("before [%d] : %lf %lf %lf %lf\n", bmu, n->neurons[bmu].image[0],  n->neurons[bmu].image[1],  n->neurons[bmu].image[2],  n->neurons[bmu].image[3]);
    for (int row = l_a_start ; row < l_a_end; ++row){
        for (int column = l_a_start; column < l_a_end; ++column){
            if (((bmu_X + row) >= 0) && ((bmu_X + row) < parameters.row) && ((bmu_Y + column) >= 0) && ((bmu_Y + column) < parameters.column)){
            	int neighbor_X = (bmu_X + row);
            	int neighbor_Y = (bmu_Y + column);
            	neuron * neighbor = n->grid[neighbor_X][neighbor_Y];
            	for (int i = 0; i < image_size; i++)
            		//Le distance gaussienne ne marche pas 
            		//neighbor->image[i] = neighbor->image[i] + learning_rate * distance(data.image[i], neighbor->image[i], learning_rate ) * (data.image[i] - neighbor->image[i]);
    				neighbor->image[i] += learning_rate * (data.image[i] - neighbor->image[i]);

            }
        }
    }

}

