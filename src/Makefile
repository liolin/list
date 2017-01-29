C = gcc
CFLAGS = -g -Wall -DDEBUG 
BUILDFLAGS = -Wall -shared -lm

SRC = ../src
OBJ = ../obj
BIN = ../bin
RELEASE = ../release


list.out: main.o list.o
	$(C) $(CFLAGS) -o $(BIN)/list.out $(OBJ)/main.o $(OBJ)/list.o

main.o: main.c
	$(C) $(CFLAGS) -c $< -o $(OBJ)/$@

list.o: list.c list.h
	$(C) $(CFLAGS) -c $< -o $(OBJ)/$@

buildOsx: list.c list.h
	$(C) -dynamiclib -o $(RELEASE)/libList.dylib $<


build: list.c list.h
	$(C) $(BUILDFLAGS) -o $(RELEASE)/libList.so $<




run: $(BIN)/list
	$(BIN)/list
