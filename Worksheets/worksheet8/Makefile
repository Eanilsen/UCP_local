CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = linked_list.o main.o
TARGET = main

exe: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -rf $(OBJ) $(TARGET)
