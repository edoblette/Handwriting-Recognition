#ifndef H_VECTOR
#define H_VECTOR

#include "./digit/digit.h"
#include "./neuron/neuron.h"
typedef struct vector {
	digit * data ; // 60 000
	float * average; // 784
	size_t size; //size of the vector
} vector;;


typedef struct neural {
	neuron * neurons; //[60]
	neuron * * *grid ;
} neural;

#endif