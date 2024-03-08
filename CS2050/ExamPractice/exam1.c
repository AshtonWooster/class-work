#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} board;

int main() {
    board *b = malloc(sizeof(board));
    board a;
    b = &a;
    
    if (!b) {
        printf("NO!!!\n");
    }

    free(b);

    return 0;
}