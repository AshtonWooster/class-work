#include <stdio.h>
#include "lab3.h"
#define BOARD_SIZE 32

/*
    This function creates a new empty game board with BOARD_SIZE cells.
    It will hide a float score, int hits, and int shots, behind the array and in that order.

    It will return the int array of ships where:
        -1 represents a destroyed ship
        0 represents an empty cell
        1 represents a ship
*/
int * newBoard() {
    // Create a new int array with room for 2 hidden ints and a hidden float
    int* board = (int*) malloc(sizeof(int) * (BOARD_SIZE + 2) + sizeof(float));

    // Initialize everything in the array to 0
    ((float*)board)[0] = 0;
    board++;
    for (int i = 0; i < BOARD_SIZE + 2; i++) {
        board[i] = 0;
    }
    board+=2;

    return board;
}

/*
    This function takes a game board, and a cell to shoot at. If the given cell is occupied
    by a ship (1), then the cell is changed to a -1 to indicate a hit. If the given cell is either empty (0), or
    destroyed (-1), then the cell is not changed and no hit occurs.

    It takes an [ int* ], the board to hit, and an [ int ], the index of the cell to shoot at
    It will return an int where:
        1 represents a hit
        0 represents a miss
*/
int takeShot(int *board, int cell) {
    // Increment shots taken
    board[-1]++;
    // If the shot missed or hit an already hit ship
    if (board[cell] <= 0) {
        updateScore(board);
        return 0;
    } 
    // If the shot hit a ship
    else {
        board[-2]++;
        board[cell] = -1;
        updateScore(board);
        return 1;
    }
}

/*
    This function takes a board, and returns the number of empty cells on it.

    It will take [ int* ], the board to count
    It will return an int, which will be the number of free cells on the board.
*/
int countFreeCells(int *board) {
    int count = 0;

    // If board[i] is 0, it is an empty cell
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == 0) {
            count++;
        }
    }

    return count;
}

/*
    This function takes a board, and returns the number of shots taken.
    
    It will take [ int* ], the board to get the shots taken from
    It will return an int, which is the number of shots taken
*/
int getShotsTaken(int *board) {
    return board[-1];
}

/*
    This function takes a board, and returns the number of successful hits.

    It will take [ int* ], the board to get the hits from
    It will return an int, which is the number of hits
*/
int getHits(int *board) {
    return board[-2];
}

/*
    This function takes a board, and returns the score.

    It will take [ int* ], the board to get the score from
    It will return a float, which is the score (hits/shots)
*/
float getScore(int *board) {
    // Cast the board as a float array to access the float score
    return ((float*)board)[-3];
}

/*
    This function takes a board, and updates the score based on the shots and hits (hits/shots).

    It will take an [ int* ], the board to update the score for
*/
void updateScore(int *board) {
    int hits = board[-2];
    int shots = board[-1];
    float newScore = (float) hits / (float) shots;
    
    ((float*)board)[-3] = newScore;
}

/*
    This function takes a board, and frees the memory allocated to it.

    It takes an [ int* ], which is the board to be freed
*/
void endGame(int *board) {
    board-=3;
    free(board);
    board = NULL;
}
