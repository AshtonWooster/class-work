#include <stdio.h>

int numGreater(int nums[], int size, int query) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (nums[i] >= query) {
            count++;
        }
    }

    return count;
}

int main() {
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    int size = 10;
    int query = 5;

    printf("Number of elements greater than or equal to %d: %d\n", query, numGreater(nums, size, query));

    return 0;
}