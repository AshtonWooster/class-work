#include <stdio.h>
#include <stdlib.h>
#include "files.h"

int main() {
    FILE* floatFile;
    floatFile = fopen("numbers.txt", "r");

    if (!floatFile) {
        printf("ERROR OPENING FILE\n");
        return 1;
    }

    float* myArray;
    int length;
    myArray = readFloatFileIntoArray(floatFile, &length);

    outputArray(myArray, length);

    freeFloatArray(&myArray);

    fclose(floatFile);

    return 0;
}
