CC = gcc
FLAGS = -Wall -pedantic -ansi -ggdb -lm -lSDL

BIN = bin/
OBJ = bin/
SRC = src/

OUT = hexxagon

all: $(BIN)$(OUT)

$(BIN)$(OUT): $(SRC)main.o $(SRC)Plateau.o $(SRC)Case.o $(SRC)affiche.o
	$(CC) $+ -o $@

$(SRC)main.o: $(SRC)main.c $(SRC)Plateau.h $(SRC)Case.h $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)main.c -o $@
	
$(SRC)Plateau.o: $(SRC)Plateau.h $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)Plateau.c -o $@
	
$(SRC)Case.o: $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)Case.c -o $@

$(SRC)affiche.o: $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)affiche.c -o $@

clean:
	rm $(BIN)*.o $(BIN)$(OUT)
