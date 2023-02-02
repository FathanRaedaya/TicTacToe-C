
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "game.h"
#include "playGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) {

  char symbols[2] = { 'X','O' };
  // player 'X' plays first
  int player = 0;

  // Starting board
  printf("New game starting\n");
  showGame( game );

  // Execute the for loop until max turns
  for (game->turns = 0; game->turns < game->maxTurns; game->turns++) {

    // Declare functions
    int winGame( Game *game, char symbol );
    int drawGame( Game *game );
    
    // Request a move from the next player and check it is valid (an unused square within the board)
    printf("Player %c: Enter your move as row column values:\n",symbols[player]); 


    // If makeMove returns 0, the move was invalid
    if (makeMove( game, symbols[player] ) == 0) {
      
      printf("Move rejected. Please try again\n"); 

      // Decrements i so turn is not counted
      game->turns--;

      // Continue the for loop after the decrementation
      continue;
    }

    // After each completed move display the board 
    showGame(game);

    // If winGame function returns True, then a players has won
    if (winGame(game, symbols[player])) {

      // A player won - game is over
      printf("Player %c has won\n", symbols[player]);

      return;

    }

    // Check for draw
    if (drawGame(game)) {

      // Game ends in a draw and is over 
      printf("Match is drawn\n"); 

      return;

    }

    // Switch between Player in index 0 and 1
    player = (player + 1) % 2;
    
  }
  
  return;
  
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {

  printf("\n");
  printf("      ");
  for (int i = 0; i < game->boardSize; i++) {
    printf("%d  ", i);
  }

  printf("\n");
  printf("\n");

  for (int i = 0; i < game->boardSize; i++) {

    printf(" %d    ", i);

    for (int j = 0; j < game->boardSize; j++) {
      printf("%c  ", game->board[i][j]);
    }

    printf("\n");

  }

  printf("\n");

  return;

}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove( Game *game, char symbol ) {

  // Declare buffer size
  char userInput[50];

  // Declare row, column and integer count
  int row, col;

  // Declare count for integers found in the input
  int intCount = 0;
  
  // Check if user has inputted something
  if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
    
    // Scan for 2 integers
    sscanf(userInput, "%d %d", &row, &col);
    
    // Run for every character in the user input
    for (int i = 0; i < strlen(userInput); i++) {

      // Check for any non-whitespace or non-digit characters
      if (!isspace(userInput[i]) && !isdigit(userInput[i])) {

        return 0;

      }

      // If the character is a digit, increment the integer count
      if (isdigit(userInput[i])) {

        intCount++;

      }

    }

    // Check if the user inputted anything but 2 integers, if so, return 0 so invalid move
    if (intCount != 2) {

      // Move is invalid
      return 0;

    }
    
    // Check if the user input are valid integers
    if (row >= game->boardSize || col >= game->boardSize || row < 0 || col < 0) {

      // Move is invalid
      return 0;

    }

    // Check if the location of the board is empty
    if (game->board[row][col] == '.') {
        
      // Set the location of the board to the symbol
      game->board[row][col] = symbol;

      // Move is valid
      return 1;

    }
    
  }

  // Move is invalid
  return 0;

}
