#include <stdio.h>
#include <stdlib.h>
#include "makeArrays.h"

int main() {
    FILE* intFile;
    intFile = fopen("numbers.txt", "r");

    if (!intFile) {
        printf("ERROR OPENING FILE\n");
        return 1;
    }

    int* myArray;
    int length;
    myArray = createIntArray(intFile, &length);

    outputArray(myArray, length);

    printf("MEAN: %f \n", getArrayMean(myArray));

    freeIntArray(&myArray);

    fclose(intFile);

    return 0;
}
