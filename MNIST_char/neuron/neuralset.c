#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./../parameter.h"
#include "./../tool.h"

void neuronAllocate(neural * n, params p){
 // init vector neurons
    n->neurons = malloc(p.neurons_size * sizeof(neuron));
    for(size_t neuron = 0 ; neuron < p.neurons_size; neuron++)
        n->neurons[neuron].image = malloc(p.data_img_size * sizeof(unsigned char));    
    

    n->grid = malloc(p.row * sizeof(neuron * * ));
    for (int row = 0; row < p.row; row++){
        n->grid[row] = malloc(p.column * sizeof(neuron *));
    }
}

/* Init neuron with normalized data input 
 * @param vector of iris and vector of neurons
 */
void vectorNeuralInit(vector * v, neural * n, params parameters ){
	int random;
	int row = 0, column = 0 ;
	for(size_t data=0; data < parameters.neurons_size; ++data, ++column ){
		for(size_t i=0; i < parameters.data_img_size; ++i){
			//init every neuron with (+\-) random value
			random = RandNum(5.0, 25.0);
			n->neurons[data].image[i] = v->average[i] + random;
        
		}

		//fill the grid with pointer of neurons
		if(column >= parameters.column){
			++row ;
			column = 0;
		}
		n->grid[row][column] = &n->neurons[data];
		n->neurons[data].row = row;
		n->neurons[data].column = column;
		n->neurons[data].label = -1;
		n->neurons[data].count = 0;
		    
	}


   
	/*
  	digit nbr_guess;
    unsigned char max=0;
    nbr_guess.image = calloc(parameters.data_img_size, sizeof(double));

    for(int i=0; i<784; ++i) {
        nbr_guess.image[i] += v->average[i];
        if(nbr_guess.image[i] > max)
            max = nbr_guess.image[i];
    }
 

    for(int i=0; i<784; ++i) {
        if(nbr_guess.image[i] >= (max * 0.2))
            printf("\033[48;5;%dm  " RESET,  (255 - (int)((nbr_guess.image[i]/max) * 23)));
        else
            printf("  ");
        if ((i+1) % 28 == 0) putchar('\n');
    }
    */
}
