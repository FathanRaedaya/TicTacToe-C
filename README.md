# Configurable Tic Tac Toe Game

A flexible Tic Tac Toe implementation in C with customizable board sizes and dynamic win conditions.

## Features

This implementation provides a comprehensive Tic Tac Toe game with flexible board configurations, allowing players to:
- Customize board sizes
- Set dynamic win length requirements

The game supports varied board dimensions and win conditions, making each game unique.

## System Requirements

To compile and run the game, ensure you have the following tools installed:
- A standard C compiler (e.g., GCC)
- The Make utility
- MinGW (for Windows users)

## Compilation

Use the provided `Makefile` to compile the game. It includes targets for building the executable and cleaning up compiled objects.

```bash
make        # Compile the game
make clean  # Remove compiled objects
```

## Executable Usage

Run the game by specifying the board size and win length as command-line arguments. This allows for dynamic game configuration before each match.

```bash
./bin/tictactoe [board_size] [win_length]
```

### Example Configurations

Demonstrating the flexibility of this Tic Tac Toe implementation:

1. **Traditional 3x3 Tic Tac Toe:**
    ```bash
    ./bin/tictactoe 3 3
    ```

2. **Large 5x5 board with 4-in-a-row win:**
    ```bash
    ./bin/tictactoe 5 4
    ```

## Game Constraints

To maintain balance and playability, the following constraints are applied:
- **Board size:** Minimum 3x3, maximum 8x8
- **Win length:** At least 3 and no greater than the board size

## Game Rules

Players alternate turns marking the game board. The objective is to achieve the predetermined number of consecutive marks (horizontal, vertical, or diagonal).

## Project Structure

The project follows a standard C project layout:

```
TicTacToe-C/
├── bin/           # Compiled executable
├── *.c            # Source files
├── *.h            # Header files
└── Makefile       # Build configuration
```

## Dependencies

The game relies on standard C libraries:
- `stdio.h` for input/output operations
- `stdlib.h` for memory allocation and other utility functions


