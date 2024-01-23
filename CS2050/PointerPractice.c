#include <stdio.h>

int main() {
    int *p, n=2;
    int x = 0;
    float *q;
    float y = 4.2;
    q = &y;
    p = (int *) q;

    // *p = 20;
    // p = &x;
    // *p = n;
    
    // printf("Value of x: %d\n", x);

    printf("Value of p: %d\n", *p);

    return 0;
}