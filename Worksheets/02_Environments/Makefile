CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = download.o download_stats.o
TARGET = download
ALLSTATS = -DALL_STATS=1

help:
	cat README.md

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

all_stats: download_all_stats download_stats.o
	$(CC) $(OBJ) -o $(TARGET)

download.o: download.c download_stats.h
	$(CC) $(CFLAGS) -c download.c

download_stats.o: download_stats.h
	$(CC) $(CFLAGS) -c download_stats.c

download_all_stats: download.c download_stats.h
	$(CC) $(CFLAGS) -c download.c $(ALLSTATS)

clean:
	rm $(OBJ) $(TARGET)
