#include "Lab1.h"
#include <stdio.h>

int main() {
    int a = 2;
    int b = 5;

    swap(&a, &b);
    printf("%d %d\n", a, b);

    int arr1[] = {1, 2, 3};
    int errorCode = swapMaxMin(arr1, 3);
    printf("%d, %d, %d ERROR: %d\n", arr1[0], arr1[1], arr1[2], errorCode);

    int arr2[] = {3, 3, 3};
    errorCode = swapMaxMin(arr2, 3);
    printf("%d, %d, %d ERROR: %d\n", arr2[0], arr2[1], arr2[2], errorCode);

    char word1[] = {'\0'};
    char result = 'a';
    errorCode = lastChar(word1, &result);
    printf("%c, %d\n", result, errorCode);

    char word2[] = {'H', 'I', ' ', 'T', 'H', 'E', 'R', 'E', '\0'};
    errorCode = lastChar(word2, &result);
    printf("%c, %d\n\n", result, errorCode);

    return 0;
}