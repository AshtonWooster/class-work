#include "CoinTossGame.h"
#include <stdlib.h>
#include <string.h>

char getRandFlip() {
    return rand() % 2 ? 'H' : 'T';
}

int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses) {
    char lastThrows[] = {'N', getRandFlip(), getRandFlip()};
    *numTosses = 2;
    *winner = 0;
    do {
        lastThrows[0] = lastThrows[1];
        lastThrows[1] = lastThrows[2];
        lastThrows[2] = getRandFlip();

        *numTosses = *numTosses + 1;
        
        if (strncmp(player1, lastThrows, 3) == 0) {
            *winner = 1;
        }
        else if (strncmp(player2, lastThrows, 3) == 0) {
            *winner = 2;
        }
    } while(!*winner);

    return 0;
}
