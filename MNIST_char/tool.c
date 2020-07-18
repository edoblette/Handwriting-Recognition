#include <stdio.h>
#include <stdlib.h>

#include "tool.h"

/* Return random value between min and max
 * @param minimum value(double), maximum value(double)
 */
int RandNum(float min, float max){
   return (int)((min) + (max - min) * ((float)rand() / (float)RAND_MAX));
}
