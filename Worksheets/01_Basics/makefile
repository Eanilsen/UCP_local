# Uses gcc to compile the source code
CC = gcc

# Compiler flags:
# -g	adds debugging information to the executable file
# -Wall	turns on most compiler warnings
CFLAGS = -g -Wall

help:
	cat README.md

all: question2.c question3.c
	$(CC) $(CFLAGS) question2.c -o question2
	$(CC) $(CFLAGS) question3.c -o question3

clean:
	rm question2 question3
