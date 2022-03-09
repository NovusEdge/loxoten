CC=gcc
CFLAGS=-pedantic -Wall -std=c17 -I

INC=include
BIN=bin
SRC=src

corruptor:
	if [ ! -d $(BIN) ]; then mkdir $(BIN); fi
	$(CC) $(CFLAGS)$(INC)/ $(SRC)/corruptor.c -o $(BIN)/corruptor


.PHONY: clean

clean:
	rm $(BIN)/*
