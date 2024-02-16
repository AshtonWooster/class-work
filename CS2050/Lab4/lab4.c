#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

#define BOARD_SIZE 32

/*
    This function takes a board, and updates the score based on the shots and hits (hits/shots).

    It will take an [ GameBoard* ], the board to update the score for
*/
void updateScore(GameBoard * board) {
    // Calculate the new score and update it
    int shots = board->shots;
    int hits = board->hits;
    float newScore = (float)hits / (float)shots;

    board->score = newScore;
}


/*
    This function creates a new empty game board with BOARD_SIZE cells

    It will return a struct containing an int array of ships where:
        -1 represents a destroyed ship
        0 represents an empty cell
        1 represents a ship
*/
GameBoard * newBoard() {
    GameBoard* newBoard = (GameBoard*)malloc(sizeof(GameBoard));

    if (!newBoard) {
        newBoard = NULL;
        return newBoard;
    }

    // Initialize all of the elements to 0
    for (int i = 0; i < BOARD_SIZE; i++) {
        newBoard->arena[i] = 0;
    }
    newBoard->shots = 0;
    newBoard->hits = 0;
    newBoard->score = 0;

    return newBoard;
}

/*
    This function takes a game board, and a cell to shoot at. If the given cell is occupied
    by a ship (1), then the cell is changed to a -1 to indicate a hit. If the given cell is either empty (0), or
    destroyed (-1), then the cell is not changed and no hit occurs.

    It takes an [ GameBoard* ], the board to hit, and an [ int ], the index of the cell to shoot at
    It will return an int where:
        1 represents a hit
        0 represents a miss
*/
int takeShot(GameBoard *board, int cell) {
    // Increment shots taken
    board->shots++;

    // If the shot missed or hit an already hit ship
    if (board->arena[cell] <= 0) {
        updateScore(board);
        return 0;
    } 
    // If the shot hit a ship
    else {
        board->hits++;
        board->arena[cell] = -1;
        updateScore(board);
        return 1;
    }
}

/*
    This function takes a board, and returns the number of empty cells on it.

    It will take [ GameBoard* ], the board to count
    It will return an int, which will be the number of free cells on the board.
*/
int countFreeCells(GameBoard *board) {
    int count = 0;

    // If board[i] is 0, it is an empty cell
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->arena[i] == 0) {
            count++;
        }
    }

    return count;
}

/*
    This function takes a board, and returns the number of shots taken.
    
    It will take [ GameBoard* ], the board to get the shots taken from
    It will return an int, which is the number of shots taken
*/
int getShotsTaken(GameBoard *board) {
    return board->shots;
}

/*
    This function takes a board, and returns the number of successful hits.

    It will take [ GameBoard* ], the board to get the hits from
    It will return an int, which is the number of hits
*/
int getHits(GameBoard *board) {
    return board->hits;
}

/*
    This function takes a board, and returns the score.

    It will take [ GameBoard* ], the board to get the score from
    It will return a float, which is the score (hits/shots)
*/
float getScore(GameBoard *board) {
    return board->score;
}

/*
    This function takes a board, and places a ship on it in the given cell. If the given cell was already
    occupied (1) or destroyed (-1), then the cell is not updated.

    It will take a [ GameBoard* ], the board to place the ship on and an [ int ], the cell to place it on
    It will return an int, which is a 0 if the ship was successfully placed, and a 1 if it was not
*/
int placeShip(GameBoard *board, int cell) {
    if (board->arena[cell] == 0) {
        board->arena[cell] = 1;
        return 0;
    }
    return 1;
}

/*
    This function takes a board, and frees the memory allocated to it.

    It takes an [ GameBoard* ], which is the board to be freed
*/
void endGame(GameBoard *board) {
    free(board);
    board = NULL;
}
