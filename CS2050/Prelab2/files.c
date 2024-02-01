#include "files.h"
#include <stdio.h>
#include <stdlib.h>

float* readFloatFileIntoArray(FILE* floatFile, int* length) {
    *length = 0;
    fscanf(floatFile, "%d", length);

    float * floatArray = (float*) malloc(sizeof(double) * (*length));

    if (!floatArray) {
        return NULL;
    }

    float nextFloat = 0;
    for (int i = 0; i < *length; i++) {
        fscanf(floatFile, "%f", &nextFloat);
        floatArray[i] = nextFloat;
    }

    return floatArray;

}

void outputArray(float* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void freeFloatArray(float** floatArray) {
    free(*floatArray);
    floatArray = NULL;
}
