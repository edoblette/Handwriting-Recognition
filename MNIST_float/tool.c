#include <stdio.h>
#include <stdlib.h>

#include "tool.h"

/* Return random value between min and max
 * @param minimum value(double), maximum value(double)
 */
double RandNum(double min, double max){
   return (min) + (max - min) * ((double)rand() / (double)RAND_MAX);
}
