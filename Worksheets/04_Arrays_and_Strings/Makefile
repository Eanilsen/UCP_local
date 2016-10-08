CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = question1.o question2.o question3.o question4.o
TARGET = question4

exe: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

question1.o: question1.c question1.h
	$(CC) $(CFLAGS) -c question1.c

question2.o: question2.c question2.h
	$(CC) $(CFLAGS) -c question2.c

question3.o: question3.c question3.h
	$(CC) $(CFLAGS) -c question3.c

question4.o: question4.c question4.h
	$(CC) $(CFLAGS) -c question4.c

clean:
	rm $(OBJ) $(TARGET)
