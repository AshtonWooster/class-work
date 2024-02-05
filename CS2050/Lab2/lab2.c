#include "lab2.h"
#include <stdlib.h>

/*
    This function will allocate memory for a new int array of [ size ]

    It will take parameter [ size ], which will be the length of the array
    It will return a pointer to the new array, or NULL if malloc failed.
*/
int * makeArray(int size) {
    int * newArray = (int*) malloc(sizeof(int) * size);

    // If malloc failed, return null
    if (!newArray) {
        newArray = NULL;
        return newArray;
    }

    // Initialize each element to 0
    for (int i = 0; i < size; i++) {
        newArray[i] = 0;
    }

    return newArray;
}

/*
    This function will return the index of the given [ element ] found in an int array

    This function takes [ *array ], a pointer to an int array, [ size ], the size of the array,
    and [ element ], the number to be found in the array.
    It will return the index of the [ element ], or -1 if it does not exist
*/
int indexOf(int *array, int size, int element) {
    // Loop through each item in the array
    for (int i = 0; i < size; i++) {
        // If we have found the element, return the index
        if (array[i] == element) {
            return i;
        }
    }

    // If the element doesn't exist, return -1
    return -1;
}

/* 
    This function takes an int array, the size of the array, and two boundary elements. It will
    subsection the array around the two boundary elements, such that the start of the new array includes
    the begin element, and the end of the new array includes the end element (at newSize - 1).

    This function takes [ *array ], a pointer to an int array, [ size ], the size of the array, 
    [ begin ], the element to begin the subsection, [ end ], the element to end the subsection,
    and [ **result ], the pointer pointing to the start of the new subsection.
    This function will return the size of the new subsection, or -1 if either [ begin ] or [ end ] do not exist
*/
int sliceArray(int *array, int size, int begin, int end, int **result) {
    // Find the index for the first and last element
    int beginIndex = indexOf(array, size, begin);
    int endIndex = indexOf(array, size, end);

    // If either begin or end dont exist, return -1
    if (beginIndex == -1 || endIndex == -1) {
        return -1;
    }
    
    // Set the address of the result array to be where the first element in the subsection appears
    *result = &array[beginIndex];

    // The size of the subsection is the difference of the indicies + 1
    int newSize = endIndex - beginIndex + 1;
    return newSize;
}

/* 
    This function takes an int array and frees it.

    It takes [ **array ], a pointer to a pointer to an int array, which will be freed and set to NULL.
*/
void freeArray(int **array) {
    // Free the array and set the pointer to null
    free(*array);
    *array = NULL;
}
