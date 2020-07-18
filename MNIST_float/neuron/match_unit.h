#ifndef H_MATCH_UNIT
#define H_MATCH_UNIT

typedef struct match_unit {
    int best_neuron;
    double distance;
    struct match_unit * next;
} match_unit;


match_unit add_node(match_unit * , int, double);

void del_node(match_unit * );
int random_node(match_unit * );
int size(match_unit * );

#endif

