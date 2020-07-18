#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include "./../parameter.h"
#include "./../tool.h"

/* Normalize vector 
 * @param vector of iris
 */
void dataAllocate(vector * v, params p){
     // init vector data
    v->data = malloc(p.data_size * sizeof(digit));
    for(size_t i = 0 ; i < p.data_size; i++)
        v->data[i].image = malloc(p.data_img_size * sizeof(float));

    v->average = calloc(p.data_img_size, sizeof(float));
    v->size = p.data_size;
}

/* Create an average image from dataset
 * @param vector of data, parameters 
 */
void vectorNormalize(vector * v, params parameters){
    size_t image_size = parameters.data_img_size;
    float * average = calloc(image_size, sizeof(float));
 
    for(size_t data=0; data < v->size; ++data){
        float sum = 0;

        //increment sum for every row
        for(size_t i=0; i < image_size; ++i)
            sum += pow(v->data[data].image[i], 2);

        float norm = sqrt(sum);

        //increment average from every row
        for(size_t i=0; i < image_size; ++i)
            average[i] += (v->data[data].image[i]/ norm);
        
    }

    //set average from every row
    for(size_t i=0; i < image_size; ++i)
        v->average[i] = (average[i]/ image_size);   
    

    free(average);
}

/* Randomize data flow for a suffle data comparison
 * @param data_flow array 
 */
void dataRandomize(int * data_flow, int data_size){
    int random, swap_buffer;

    for(int i=0; i < data_size; ++i) 
        data_flow[i] = i;
    
    for(int i=0; i < data_size; ++i){
        random = (int) RandNum(0, data_size);
        swap_buffer = data_flow[i];
        data_flow[i] = data_flow[random];
        data_flow[random] = swap_buffer;

    }
}