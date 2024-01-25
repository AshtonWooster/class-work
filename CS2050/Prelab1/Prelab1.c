#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "CoinTossGame.h"

int main() {
    srand(time(NULL));

    int numTests = 10000;
    char player1[] = "THH";
    char player2[] = "HHT";
    int player1Wins = 0;
    int player2Wins = 0;
    int winner = 0;
    int numTosses = 0;

    for (int i = 0; i < numTests; i++) {
        if (!coinTossGame(player1, player2, &winner, &numTosses)) {
            if (winner == 1) player1Wins++;
            else player2Wins++;
        }
        else {
            printf("Error playing game.");
            break;
        }
    }

    float player1WinRate = (float) player1Wins / (float) numTests;
    float player2WinRate = (float) player2Wins / (float) numTests;

    printf("\nRESULTS\n--------------------\n\n");
    printf("Player 1:\n Wins: %d\n Win Rate: %.2f\n\n----------\n\n", player1Wins, player1WinRate);
    printf("Player 2 Wins: %d\n Win Rate: %.2f\n\n--------------------\n", player2Wins, player2WinRate);

    return 0;
}