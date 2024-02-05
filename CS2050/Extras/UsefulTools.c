#include <stdio.h>
#include <stdlib.h>
#include "UsefulTools.h"

void* makeArray(int numElements, int size) {
    void* newArray = malloc(numElements * size + sizeof(int));
}

void freeArray(void** array) {

}