#ifndef H_PARAMS
#define H_PARAMS

#include "vector.h"
#include "./neuron/match_unit.h"

typedef struct params {
	size_t data_size; // 60000
	size_t data_img_size; //784
	size_t len_info_img;
	size_t len_info_label;
	size_t neurons_size;

	int row, column;
	int usage;
	int test;

	char * train_images;
	char * train_labels;

	char * test_images;
	char * test_labels;

} params;

//proto
void print_dataSet(vector data, int max);
void allocate_memory(vector * v, neural * n,  params p);
void printNeuralNetwork(neural , params , int );
void printNeuronAppreciation(neural n, params parameters, int data);

//proto digit
void FlipLong(unsigned char * ptr);
void read_mnist_char(char *file_path, int num_data, int len_info, int arr_n, unsigned char * * data_char, int *);
void image_char2char(int num_data, unsigned char * * data_image_char, vector *);
void label_char2int(int num_data, unsigned char * * data_label_char, vector * v);
void load_mnist(vector * data, params p, char * image_src, char * label_src);

//proto dataset
void dataAllocate(vector * v, params p);
void vectorNormalize(vector * v, params parameters);
void dataRandomize(int * , int);

//proto neuralset
void neuronAllocate(neural * n, params p );
void vectorNeuralInit(vector * v, neural * n, params parameters );

// proto learning
float euclidean_distance(unsigned char * , unsigned char * , int );
match_unit * learning(vector *, neural *, int * , params, int, float , int);
void labeling(vector *  , neural * , int * , match_unit *, params , int );
void neighborhood_improving(digit , neural * , params, int, int, int, float, int);


// set appropriate path for data

#define SIZE 784 // 28*28
#define NUM_TRAIN 60000

#define LEN_INFO_IMAGE 4
#define LEN_INFO_LABEL 2

#define TRUE 1
#define FALSE 0
#define CLR_1   "\x1B[41m"
#define CLR_2   "\x1B[42m"
#define CLR_3   "\x1B[43m"
#define CLR_4   "\x1B[44m"
#define CLR_5   "\x1B[45m"
#define CLR_6   "\x1B[46m"
#define CLR_7   "\x1B[101m"
#define CLR_8   "\x1B[102m"
#define CLR_9   "\x1B[103m"
#define CLR_10   "\x1B[104m"
#define BLACK 	"\x1B[40m"


#define RESET "\x1B[0m"
#endif