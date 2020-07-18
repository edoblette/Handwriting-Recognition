#ifndef H_NEURON
#define H_NEURON

typedef struct neuron {
   unsigned char * image;  //[SIZE]
   int label;    
   int row, column;
   int count;

} neuron;

#endif