CC = gcc

INC = inc
OBJ = obj
SRC = src
BIN = bin
LDFLAGS = -o
CFLAGS = -c -g -Wall
IFLAGS = -I $(INC)/

all: $(BIN)/app

$(BIN)/app: $(OBJ)/test1.o $(OBJ)/menu.o
	$(CC) $(LDFLAGS) $(BIN)/app $(OBJ)/test1.o $(OBJ)/menu.o

$(OBJ)/test1.o: $(SRC)/test1.c
	$(CC) $(CFLAGS) $(SRC)/test1.c $(IFLAGS)
	mv *.o $(OBJ)/

$(OBJ)/menu.o: $(SRC)/menu.c
	$(CC) $(CFLAGS) $(SRC)/menu.c $(IFLAGS)
	mv *.o $(OBJ)/


clean:
	rm -f a.out *.o
	rm -f $(BIN)/*
	rm -f $(OBJ)/*.o
	@echo "Cleaning Done!"
