#include <stdio.h>

int main() {
    int *p, n=2;
    p = &n;
    printf("%d\n", p[0]);

    return 0;
}