
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"

/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {

  Game *game; // pointer for the game structure

  // Check if 3 arguments are given or not
  if (argc != 3) {
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return 1;
  }

  // Check if the arguments are valid
  if (initGame(atoi(argv[1]), atoi(argv[2])) == NULL) {
    return 1;
  }

  // Allocate memory and assign starting values to the structure
  game = initGame(atoi(argv[1]), atoi(argv[2]));

  // Play a full game
  playGame( game );

  // Free heap memory that was used
  free( game );

  return 0;
}

