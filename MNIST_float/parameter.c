#include <stdio.h>
#include <stdlib.h>
#include "parameter.h"
#include "./digit/digit.h"

/* Allocate memory for data, neuron
 * @param vector of iris, vector of neurons, parameters
 */
void allocate_memory(vector * v, neural * n, params p){
    
    dataAllocate(v, p);
    neuronAllocate(n, p);
}


void print_dataSet(vector v, int max){
	for(int number=0; number < max ;  ++number){
        // print pixels of first data in test dataset
        
        for(int i=0; i<784; ++i) {
            if(v.data[number].image[i] >= 0.1)
                printf("🔴"); //printf(CLR_1 "%1.1f" RESET, data.image[number][i]);
            else
                 printf("⬜️");//printf("%1.1f", data.image[number][i]);
            if ((i+1) % 28 == 0) putchar('\n');
        }
        

        // print first label in test dataset
       // printf("label: %d\n", test_label[0]);

        // save image of first data in test dataset as .pgm file
        //save_mnist_pgm(test_image, number);
        printf("[%d] =%d \n", number, v.data[number].label);
        // show all pixels and labels in test dataset
       // print_mnist_pixel(test_image, NUM_TEST);
        //print_mnist_label(test_label, NUM_TEST);
    }
}

/* Print the current state of neural network
 * @param vector of neurons, parameters
 */
void printNeuralNetwork(neural n, params parameters, int usage){
    for (int row = 0; row < parameters.row; ++row){
            for (int column = 0; column < parameters.column; ++column){
                if(n.grid[row][column]->label == 0)
                    usage == 1 ? printf( CLR_1 "%d " RESET, n.grid[row][column]->count) : printf( CLR_1 "%d " RESET, n.grid[row][column]->label);
                else if(n.grid[row][column]->label == 1)
                    usage == 1 ? printf( CLR_2 "%d " RESET, n.grid[row][column]->count) : printf( CLR_2 "%d " RESET, n.grid[row][column]->label);
                else if(n.grid[row][column]->label == 2)
                    usage == 1 ? printf( CLR_3 "%d " RESET, n.grid[row][column]->count) : printf( CLR_3 "%d " RESET, n.grid[row][column]->label);
                else if(n.grid[row][column]->label == 3)
                    usage == 1 ? printf( CLR_4 "%d " RESET, n.grid[row][column]->count) : printf( CLR_4 "%d " RESET, n.grid[row][column]->label);
                else if(n.grid[row][column]->label == 4)
                    usage == 1 ? printf( CLR_5 "%d " RESET, n.grid[row][column]->count) : printf( CLR_5 "%d " RESET, n.grid[row][column]->label);
                else if(n.grid[row][column]->label == 5)
                    usage == 1 ? printf( CLR_6 "%d " RESET, n.grid[row][column]->count) : printf( CLR_6 "%d " RESET, n.grid[row][column]->label);
                else if(n.grid[row][column]->label == 6)
                    usage == 1 ? printf( CLR_7 "%d " RESET, n.grid[row][column]->count) : printf( CLR_7 "%d " RESET, n.grid[row][column]->label);
                else if(n.grid[row][column]->label == 7)
                    usage == 1 ? printf( CLR_8 "%d " RESET, n.grid[row][column]->count) : printf( CLR_8 "%d " RESET, n.grid[row][column]->label);
                else if(n.grid[row][column]->label == 8)
                    usage == 1 ? printf( CLR_9 "%d " RESET, n.grid[row][column]->count) : printf( CLR_9 "%d " RESET, n.grid[row][column]->label);
                 else if(n.grid[row][column]->label == 9)
                    usage == 1 ? printf( CLR_10 "%d " RESET, n.grid[row][column]->count) : printf( CLR_10 "%d " RESET, n.grid[row][column]->label);
                else
                    printf(BLACK  "# " RESET) ;
            }
            printf("\n");
    }
        printf("\n");
}

/* Print the reprentation of data from neuron
 * @param vector of neurons, parameters
 */
void printNeuronAppreciation(neural n, params parameters, int data, float threshold){
    float max=0;
    float * image = calloc(parameters.data_img_size, sizeof(float));

    for(size_t neuron = 0; neuron < parameters.neurons_size; ++neuron){
        if(n.neurons[neuron].label == data){
            for(int i=0; i<784; ++i) {
               image[i] += n.neurons[neuron].image[i];
               if(image[i] > max)
                    max = image[i];
            }
        }
    }
    for(int i=0; i<784; ++i) {
        if(image[i] >= (max * threshold))
            printf("\033[48;5;%dm  " RESET,  (255 - (int)((image[i]/max) * 23)));
        else
            printf("  ");
        if ((i+1) % 28 == 0) putchar('\n');
    }

    free(image);
}



