#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

void outputArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int * board = newBoard();

    board[1] = 1;
    board[5] = 1;

    outputArray(board, 32);
    printf("SCORE: %f\n", getScore(board));
    printf("RESULT AT 0: %d\n", takeShot(board, 0));
    printf("RESULT AT 1: %d\n", takeShot(board, 1));
    printf("HITS: %d\n", getHits(board));
    printf("SCORE: %f\n", getScore(board));
    outputArray(board, 32);
    printf("SHOTS TAKEN: %d\n", getShotsTaken(board));
    printf("SHOOT AT 1: %d\n", takeShot(board, 1));
    printf("SHOTS TAKEN: %d\n", getShotsTaken(board));
    printf("HITS: %d\n", getHits(board));
    printf("SCORE: %f\n", getScore(board));
    
    
    


    endGame(board);
    return 0;
}
