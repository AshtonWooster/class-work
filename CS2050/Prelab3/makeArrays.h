#ifndef _MAKE_ARRAYS_H
#define _MAKE_ARRAYS_H
#include <stdio.h>

int * createIntArray(FILE *, int *);
float getArrayMean(int*);
void freeIntArray(int**);
void outputArray(int*, int);

#endif 
