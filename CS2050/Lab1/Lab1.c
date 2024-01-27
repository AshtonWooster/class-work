#include "Lab1.h"
#include <stdio.h>

// This function will take two pointers to int, and swap the values being pointed to. 
void swap(int *a, int *b) {
    // Store the value of a into a placeholder variable "c"
    int c = *a;
    // Swap the values of b and a using the placeholder
    *a = *b;
    *b = c;
}

/*  
    This function will take an int array, as well as the size of the array.
    It will swap the places of the minimum and maximum elements in the array.

    Returns a 1 when all the values are the same in the array
    Returns a 0 when the swap was successfully completed
*/
int swapMaxMin(int array[], int size) {
    int currentMax = 0;
    int currentMin = 0;
    for (int i = 0; i < size; i++) {
        // If larger than max, swap currentMax for i. If less than min, swap currentMin for i
        if (array[i] > currentMax) {
            currentMax = i;
        }
        if (array[i] < currentMin) {
            currentMin = i;
        }
    }

    // If max == min then the elements in the array are the same
    if (array[currentMax] == array[currentMin]) {
        return 1;
    }
    else {
        // Pass two int pointers that have the address of the max and min to swap
        swap(&array[currentMax], &array[currentMin]);
    }

    return 0;
}

/*
    This function will take a NULL-terminated string, and return the character at the end of the string by reference.

    Returns a 1 when the string is empty
    Returns a 0 when it has successfully returned the last character of the string
*/ 
int lastChar(char str[], char *result) {
    int i = 0;
    char currentChar = str[0];

    // If the string is empty, return 1
    if (currentChar == '\0') {
        return 1;
    }
    // Increment i and currentChar until the next character is a null terminator
    while (str[++i] != '\0') {
        currentChar = str[i];
    }
    // Set the value of result to the last character in the string
    *result = currentChar;

    return 0;
}
