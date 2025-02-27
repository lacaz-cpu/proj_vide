SRC = ./src/
INC = ./include/
OBJ = ./obj/
BIN = ./bin/

CC = gcc
CFLAGS = -Wall -std=c11
EXEC = carcassonne

.PHONY: all run clean

all: $(EXEC)

run: $(EXEC)
	$(BIN)$<

$(EXEC): moteur_jeu.o fonction_jeu.o
	$(CC) $(OBJ)*  -o $(BIN)$@
	
moteur_jeu.o: $(SRC)moteur_jeu.c
	$(CC) $(CFLAGS) $< -c -I $(INC) -o $(OBJ)$@

fonction_jeu.o : $(SRC)fonction_jeu.c 
	$(CC) $(CFLAGS) $< -c -I $(INC) -o $(OBJ)$@
	
clean:
	rm $(BIN)* $(OBJ)*
