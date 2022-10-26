CC = gcc
INC = inc
OBJ = obj
SRC = src
BIN = bin
LDFLAGS = -o
CFLAGS = -c -g -Wall

all: $(BIN)/app

$(BIN)/app: $(OBJ)/main.o $(OBJ)/menu.o $(OBJ)/task.o $(OBJ)/user.o $(OBJ)/assignment.o 
	$(CC) $(LDFLAGS) $(BIN)/app $(OBJ)/main.o $(OBJ)/menu.o $(OBJ)/task.o $(OBJ)/user.o $(OBJ)/assignment.o 

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c -I $(INC)/
	mv *.o $(OBJ)/

$(OBJ)/menu.o: $(SRC)/menu.c 
	$(CC) $(CFLAGS) $(SRC)/menu.c -I $(INC)/
	mv *.o $(OBJ)/

$(OBJ)/task.o: $(SRC)/task.c 
	$(CC) $(CFLAGS) $(SRC)/task.c -I $(INC)/
	mv *.o $(OBJ)/

$(OBJ)/user.o: $(SRC)/user.c 
	$(CC) $(CFLAGS) $(SRC)/user.c -I $(INC)/
	mv *.o $(OBJ)/

$(OBJ)/assignment.o: $(SRC)/assignment.c 
	$(CC) $(CFLAGS) $(SRC)/assignment.c -I $(INC)/
	mv *.o $(OBJ)/


clean:
	rm -f a.out *.o
	rm -f $(BIN)/*
	rm -f $(OBJ)/*.o
	@echo "Cleaning Done!"
