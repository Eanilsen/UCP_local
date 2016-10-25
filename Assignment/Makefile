CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = sorting_assignment.o linked_list.o util.o filereader.o
TARGET = sorting_assignment

exe: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

sorting_assignment.o: sorting_assignment.c sorting_assignment.h
	$(CC) $(CFLAGS) -c sorting_assignment.c

linked_list.o: linked_list.c linked_list.h util.h
	$(CC) $(CFLAGS) -c linked_list.c

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

filereader.o: filereader.h filereader.c linked_list.h
	$(CC) $(CFLAGS) -c filereader.c

clean:
	rm -rf $(OBJ) $(TARGET)
