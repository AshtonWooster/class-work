#include <stdio.h>
#include <stdlib.h>
#include "makeArrays.h"

int * createIntArray(FILE * intFile, int * length) {
    *length = 0;
    fscanf(intFile, "%d", length);

    int * intArray = (int*) malloc(sizeof(int) * (*length + 1));

    if (!intArray) {
        return NULL;
    }

    int nextInt = 0;
    int total = 0;
    for (int i = 1; i < (*length+1); i++) {
        fscanf(intFile, "%d", &nextInt);
        intArray[i] = nextInt;
        total = total + nextInt;
    }

    ((float*) intArray)[0] = (float) total / (float) *length;

    intArray++;

    return intArray;
}

void outputArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

float getArrayMean(int* arr) {
    return ((float*) arr)[-1];
}
void freeIntArray(int** arr) {
    *arr = (*arr - 1);
    free(*arr);
    *arr = NULL;
}
