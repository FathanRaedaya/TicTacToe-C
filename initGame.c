
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

  Game *game;

  // Check if the arguments are valid
  if (boardSize < 3 || boardSize > 8 || winLength < 3 || winLength > boardSize) {
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return NULL;
  }

  // Allocate the Game data structure
  game = malloc(sizeof(Game));

  // Intialise the Game data structure values
  game->boardSize = boardSize;
  game->winLength = winLength;
  game->maxTurns = boardSize * boardSize;
  game->turns = 0;

  // Run for every row of the board
  for (int i = 0; i < game->boardSize; i++) {

    // Run for every column of the board
    for (int j = 0; j < game->boardSize; j++) {

      // Set the board to empty with '.'
      game->board[i][j] = '.';

    }
  }

  return game;

}


