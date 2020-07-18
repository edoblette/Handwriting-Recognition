#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "match_unit.h"
#include "./../tool.h"

match_unit add_node(match_unit * front, int best_neuron, double distance){
	 match_unit * next = malloc(sizeof( match_unit));
	 next->best_neuron = best_neuron;
	 next->distance = distance;
	 next->next = NULL;
	 front->next = next;

	 return * next;
}

void del_node(match_unit * front){
	if(front->next != NULL){
		del_node(front->next);
		free(front->next);
	}
	
}

int random_node(match_unit * bmu_array){
 	int taille = size(bmu_array);
 
	int random = rand() % (taille  + 1); 


	for(int i=0; i < random; ++i)
		bmu_array = bmu_array->next;
	

	return bmu_array->best_neuron;
}

int size(match_unit * front){
	int res = 0;
	if(front->next != NULL){
		res = size(front->next) + 1;
	}
	return res;
}