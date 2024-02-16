#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void outputArray(GameBoard* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr->arena[i]);
    }
    printf("\n");
}

int main() {
    GameBoard * board = newBoard();

    outputArray(board, 32);
    printf("PLACING AT 0: %d\n", placeShip(board, 0));
    printf("PLACING AT 10: %d\n", placeShip(board, 10));
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
    printf("\n EMPTY: %d\n", countFreeCells(board));
    
    
    


    endGame(board);
    return 0;
}
