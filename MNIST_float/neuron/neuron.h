#ifndef H_NEURON
#define H_NEURON

typedef struct neuron {
   float * image;  //[SIZE]
   int label;    
   int row, column;
   int count;

} neuron;

#endif