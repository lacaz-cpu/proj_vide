SRC = ./src/
INC = ./include/
OBJ = ./obj/
BIN = ./bin/
LIB = ./lib/
CC = gcc
CFLAGS = -Wall -std=c11
EXEC = carcassonne

.PHONY: all run clean

all: $(EXEC)

run: $(EXEC)
	$(BIN)$<

$(EXEC): moteur_jeu.o fonction_jeu.o affichage.o 
	$(CC) $(OBJ)*  -o $(BIN)$@ $(LIB)libraylib.a -lm
	
moteur_jeu.o: $(SRC)moteur_jeu.c
	$(CC) $(CFLAGS) $< -c -I $(INC) -o $(OBJ)$@

fonction_jeu.o : $(SRC)fonction_jeu.c 
	$(CC) $(CFLAGS) $< -c -I $(INC) -o $(OBJ)$@

affichage.o : $(SRC)affichage.c 
	$(CC) $(CFLAGS) $< -c -I $(INC) -o $(OBJ)$@
	
clean:
	rm $(BIN)* $(OBJ)*
