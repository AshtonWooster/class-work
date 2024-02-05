#include "lab2.h"
#include <stdio.h>
#include <stdlib.h>

void outputArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int * newArray = makeArray(10);
    printf("ALL 0: \n");
    outputArray(newArray, 10);


    for (int i = 0; i < 10; i++) {
        newArray[i] = i;
    }
    printf("\n 0-9\n");
    outputArray(newArray, 10);

    printf("\nIndex of 2: %d\n", indexOf(newArray, 10, 2));
    printf("Index of 11: %d\n\n", indexOf(newArray, 10, 11));

    int * sliced = NULL;
    int slicedSize = sliceArray(newArray, 10, 3, 6, &sliced);
    int slicedSize2 = sliceArray(newArray, 10, 4, -5, &sliced);

    printf("Size1: %d\n", slicedSize);
    printf("Size2: %d\n", slicedSize2);

    printf("\nSliced: \n");
    outputArray(sliced, slicedSize);

    printf("\nLocation of 3: %d\n", indexOf(sliced, slicedSize, 3));
    printf("\nLocation of 6: %d\n", indexOf(sliced, slicedSize, 6));
    printf("\nLocation of 2: %d\n", indexOf(sliced, slicedSize, 2));

    freeArray(&newArray);

    return 0;
}