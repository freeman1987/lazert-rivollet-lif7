BIN = bin/
OBJ = bin/
SRC = src/
LIB = lib/

CC = gcc
FLAGS = -Wall -pedantic -ansi -ggdb 
LDFLAGS = -lm -lSDL -lSDL_image $(FLAGS) $(LIB)libfmodex.so
LDFLAGS2 = -lm `sdl-config --libs` -lSDL -lSDL_image $(FLAGS) $(LIB)libfmodex.so

OUT = hexxagon

all: $(BIN)$(OUT)


$(BIN)$(OUT): $(OBJ)main.o $(OBJ)Plateau.o $(OBJ)Case.o $(OBJ)affiche.o $(OBJ)ordinateur.o $(OBJ)jeu.o $(OBJ)menuprincipal.o
	$(CC) $(LDFLAGS) $+ -o $@

$(OBJ)ordinateur.o: $(SRC)ordinateur.c $(SRC)ordinateur.h $(SRC)Plateau.h $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)ordinateur.c -o $@

$(OBJ)main.o: $(SRC)main.c $(SRC)main.h $(SRC)Plateau.h $(SRC)Case.h $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)main.c -o $@

$(OBJ)Plateau.o: $(SRC)Plateau.h $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)Plateau.c -o $@

$(OBJ)Case.o: $(SRC)Case.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)Case.c -o $@

$(OBJ)affiche.o: $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)affiche.c -o $@

$(OBJ)jeu.o: $(SRC)jeu.h $(SRC)Plateau.h $(SRC)Case.h $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)jeu.c -o $@

$(OBJ)menuprincipal.o: $(SRC)menuprincipal.h $(SRC)affiche.h $(SRC)parametres.h
	$(CC) -c $(FLAGS) $(SRC)menuprincipal.c -o $@

clean:
	rm $(BIN)*.o $(BIN)$(OUT)

