#!/usr/bin/env bash

# TODO: add a check for gcc and compile binaries

gcc -std=c17  -Wall -pedantic -Iinclude/ src/corruptor.c -o bin/corruptor
