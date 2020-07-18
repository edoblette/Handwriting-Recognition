#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "./../parameter.h"

void FlipLong(unsigned char * ptr){
    register unsigned char val;
    
    // on swap le 1 et le 4 octet
    val = *(ptr);
    *(ptr) = *(ptr+3);
    *(ptr+3) = val;
    
    // on swap le 2 et le 3 octet
    ptr += 1;
    val = *(ptr);
    *(ptr) = *(ptr+1);
    *(ptr+1) = val;
}


void read_mnist_char(char *file_path, int num_data, int len_info, int arr_n, unsigned char ** data_char, int info_arr[]){
    int i, fd;
    unsigned char *ptr;

    if ((fd = open(file_path, O_RDONLY)) == -1) {
        fprintf(stderr, "couldn't open image file");
        exit(-1);
    }
    
    read(fd, info_arr, len_info * sizeof(int));
    
    // read-in information about size of data
    for (i=0; i<len_info; i++) { 
        ptr = (unsigned char *)(info_arr + i);
        FlipLong(ptr);
        ptr = ptr + sizeof(int);
    }
    
    // read-in mnist numbers (pixels|labels)
    for (i=0; i<num_data; i++) {
        read(fd, data_char[i], arr_n * sizeof(unsigned char));   
    }

    close(fd);
}


void image_char2char(int num_data, unsigned char * * data_image_char, vector * v){
    int i, j;
    for (i=0; i<num_data; i++)
        for (j=0; j<SIZE; j++)
            v->data[i].image[j]  = (char)data_image_char[i][j];
}


void label_char2int(int num_data, unsigned char ** data_label_char, vector * v){
    int i;
    for (i=0; i<num_data; i++)
         v->data[i].label  = (int)data_label_char[i][0];
}


void load_mnist(vector * dataset, params p, char * image_src, char * label_src){

    int info_image[p.len_info_img];
    int info_label[p.len_info_label];

    // On alloue des tableau temporaire pour stoker les different etat de la database
    unsigned char * * image_char = malloc(p.data_size * sizeof(unsigned char *));
    for(size_t i = 0 ; i < p.data_size; i++)
        image_char[i] = malloc(p.data_img_size * sizeof(unsigned char));

    unsigned char * * label_char = malloc(p.data_size * sizeof(unsigned char *));
    for(size_t i = 0 ; i < p.data_size; i++)
        label_char[i] = malloc(sizeof(unsigned char));
    
    read_mnist_char(image_src, p.data_size, LEN_INFO_IMAGE, p.data_img_size, image_char, info_image);
    image_char2char(p.data_size, image_char, dataset);

    read_mnist_char(label_src, p.data_size, LEN_INFO_LABEL, 1, label_char, info_label);
    label_char2int(p.data_size, label_char, dataset);

    // On n'oublie pas de free
    for(size_t i=0; i < p.data_size; ++i){
        free(image_char[i]);
        free(label_char[i]);
    }

    free(image_char);
    free(label_char);

}
