CC = gcc
FLAGS = -Wall -pedantic -ansi -ggdb

BIN = "bin/"
OBJ = "bin/"
SRC = "src/"

OUT = "hexxagon"

all: $(BIN)$(OUT)

$(BIN)$(OUT): $(SRC)main.o $(SRC)Plateau.o $(SRC)Case.o
	$(CC) $+ -o $@

$(SRC)main.o: $(SRC)main.h $(SRC)main.c Plateau.h Case.h
	$(CC)

$(SRC)Plateau.o: 


clean:
	rm $(BIN)*.o $(BIN)$(OUT)
