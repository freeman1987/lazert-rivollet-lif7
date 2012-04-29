CC = gcc
FLAGS = -Wall -pedantic -ansi -ggdb -lm -lSDL

BIN = bin/
OBJ = bin/
SRC = src/

OUT = hexxagon

all: $(BIN)$(OUT)

$(BIN)$(OUT): $(BIN)main.o $(BIN)Plateau.o $(BIN)Case.o $(BIN)affiche.o
	$(CC) $+ -o $@

$(BIN)main.o: $(SRC)main.c $(SRC)Plateau.h $(SRC)Case.h $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)main.c -o $@
	
$(BIN)Plateau.o: $(SRC)Plateau.h $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)Plateau.c -o $@
	
$(BIN)Case.o: $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)Case.c -o $@

$(BIN)affiche.o: $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)affiche.c -o $@

clean:
	rm $(BIN)*.o $(BIN)$(OUT)
