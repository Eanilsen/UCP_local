CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = librarymanager.o menusystem.o service.o catalogue.o book.o borrowerlist.o borrower.o util.o
EXEC = librarymanager

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

librarymanger.o : librarymanger.c menusystem.h catalogue.h book.h borrowerlist.h borrower.h
	$(CC) $(CFLAGS) -c librarymanger.c

menusystem.o : menusystem.c menusystem.h catalogue.h book.h borrowerlist.h borrower.h util.h
	$(CC) $(CFLAGS) -c menusystem.c

service.o : service.c service.h book.h borrower.h boolean.h
	$(CC) $(CFLAGS) -c service.c

catalogue.o : catalogue.c catalogue.h book.h borrower.h boolean.h util.h
	$(CC) $(CFLAGS) -c catalogue.c

book.o : book.c book.h boolean.h
	$(CC) $(CFLAGS) -c book.c

borrowerlist.o : borrowerlist.c borrowerlist.h borrower.h book.h boolean.h
	$(CC) $(CFLAGS) -c borrowerlist.c

borrower.o : borrower.c borrower.h book.h boolean.h
	$(CC) $(CFLAGS) -c borrower.c

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

clean :
	rm -f $(EXEC) $(OBJ)
