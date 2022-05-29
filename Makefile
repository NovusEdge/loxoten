CC=gcc
CFLAGS=-pedantic -Wall -std=c17 -I

INC=include
BIN=bin
SRC=src

loxoten:
	if [ ! -d $(BIN) ]; then mkdir $(BIN); fi
	$(CC) $(CFLAGS)$(INC)/ $(SRC)/loxoten.c -o $(BIN)/loxoten


.PHONY: clean

clean:
	rm $(BIN)/*
