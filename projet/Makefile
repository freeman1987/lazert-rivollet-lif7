CC = gcc
FLAGS = -Wall -pedantic -ansi -ggdb 
LDFLAGS = -lm -lSDL -lSDL_image $(FLAGS) bin/libfmodex.so

BIN = bin/
OBJ = bin/
SRC = src/

OUT = hexxagon

all: $(BIN)$(OUT)

$(BIN)$(OUT): $(BIN)main.o $(BIN)Plateau.o $(BIN)Case.o $(BIN)affiche.o $(BIN)ordinateur.o $(BIN)jeu.o $(BIN)menuprincipal.o
	$(CC) $(LDFLAGS) $+ -o $@

$(BIN)ordinateur.o: $(SRC)ordinateur.c $(SRC)ordinateur.h $(SRC)Plateau.h $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)ordinateur.c -o $@

$(BIN)main.o: $(SRC)main.c $(SRC)Plateau.h $(SRC)Case.h $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)main.c -o $@

$(BIN)Plateau.o: $(SRC)Plateau.h $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)Plateau.c -o $@

$(BIN)Case.o: $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)Case.c -o $@

$(BIN)affiche.o: $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)affiche.c -o $@
	
$(BIN)jeu.o: $(SRC)jeu.h $(SRC)Plateau.h $(SRC)Case.h $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)jeu.c -o $@
	
$(BIN)menuprincipal.o: $(SRC)menuprincipal.h $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)menuprincipal.c -o $@

clean:
	rm $(BIN)*.o $(BIN)$(OUT)
