#ifndef H_MATCH_UNIT
#define H_MATCH_UNIT

typedef struct match_unit {
    int best_neuron;
    unsigned char distance;
    struct match_unit * next;
} match_unit;


match_unit add_node(match_unit * , int, unsigned char);

void del_node(match_unit * );
int random_node(match_unit * );
int size(match_unit * );

#endif

