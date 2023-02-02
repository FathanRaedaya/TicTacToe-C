
#include <stdio.h>

#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {

  // return 1(true) if game is won, 0(false) otherwise
  //
  // You may wish to define further functions to test different win conditions
  // Games can be won with horizontal, vertical or diagonal lines

  // Declare each variable to count each win possible
  int horiWin = 0;
  int vertWin = 0;
  int diagWin = 0;
  int revDiagWin = 0;

  // Run for every row of the board
  for (int i = 0; i < game->boardSize; i++) {

    // Run for every column of the board
    for (int j = 0; j < game->boardSize; j++) {
    
      // Reset win conditions for every new column
      horiWin = 0;
      vertWin = 0;
      diagWin = 0;
      revDiagWin = 0;

      for (int k = 0; k < game->boardSize; k++) {
        
        // Check for horizontal win
        if (game->board[i][j + k] == symbol) {
          
          horiWin++;
          
        }
        
        // Reset the win count if the symbols are not in a row
        if (game->board[i][j + k] != symbol) {
          
          horiWin = 0;
          
        }

        // Check for vertical win
        if (game->board[j + k][i] == symbol) {
          
          vertWin++;

        }

        // Reset vertical win condition if symbol is not found
        if (game->board[j + k][i] != symbol) {
          
          vertWin = 0;

        }

        // Check for diagonal win
        if (game->board[i + k][j + k] == symbol) {
          
          diagWin++;

        }

        // Reset diagonal win condition if symbol is not found
        if (game->board[i + k][j + k] != symbol) {
          
          diagWin = 0;

        }

        // Check for reverse diagonal win
        if (game->board[i + k][game->boardSize - j - k - 1] == symbol) {
          
          revDiagWin++;

        }

        // Reset reverse diagonal win condition if symbol is not found
        if (game->board[i + k][game->boardSize - j - k - 1] != symbol) {
          
          revDiagWin = 0;

        }

        // Check if any of the win conditions are met
        if (horiWin == game->winLength || vertWin == game->winLength || diagWin == game->winLength || revDiagWin == game->winLength) {

          return 1;

        }
      }
    }
  }
  

  return 0;  // continue

}

// Test for a draw
int drawGame( Game *game ) {

  int draw = 0;

  // Run for every row of the board
  for (int i = 0; i < game->boardSize; i++) {

    // Run for every column of the board
    for (int j = 0; j < game->boardSize; j++) {

      // Checks if the board is occupied
      if (game->board[i][j] != '.') {

        // If the board is occupied then, increment draw count
        draw++;
      }
    }
  }
  
  // If the the draw count is max turns then return 1, drawm
  if (draw == game->maxTurns) {
    return 1;
  }
  else {

    // This means it is not a draw
    return 0;
  }
}

