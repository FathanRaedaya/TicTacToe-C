
# code details

EXE = ./bin/tictactoe
SRC = initGame.c main.c playGame.c endGame.c                # ** list source code here **
OBJ = initGame.o main.o playGame.o endGame.o                # ** list object code here **

# generic build details

CC     = gcc
CFLAGS = -std=c99 -Wall
CLIBS  = 
CLINK  = 

# compile to object code

%.o: %.c
	$(CC) -c $(CFLAGS) $(CLIBS) $< -o $@

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies
initGame.o: initGame.c initGame.h game.h
playGame.o: playGame.c playGame.h game.h endGame.h
main.o: main.c game.h initGame.h playGame.h
endGame.o: endGame.c endGame.h game.h
#
# ** put code dependencies here **
#
