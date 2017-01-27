C = gcc
CFLAGS = -g -Wall -DDEBUG 
BUILDFLAGS = -Wall -shared -lm

SRC = ../src
OBJ = ../obj
BIN = ../bin
RELEASE = ../release


list: main.o buildOsx
	$(C) $(CFLAGS) -L$(RELEASE) -lList -o $(BIN)/list $(OBJ)/main.o

main.o: main.c
	$(C) $(CFLAGS) -c $< -o $(OBJ)/$@

buildOsx: list.c list.h
	$(C) -dynamiclib -o $(RELEASE)/libList.dylib $<


build: list.c list.h
	$(C) $(BUILDFLAGS) -o $(RELEASE)/libList.so $<


list.o: list.c list.h
	$(C) $(CFLAGS) -c $< -o $(OBJ)/$@




run: $(BIN)/list
	$(BIN)/list
