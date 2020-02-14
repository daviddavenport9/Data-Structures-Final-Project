CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: ItemType.h Sorting.h main.cpp ItemType.cpp Sorting.cpp
	$(CC) $(CFLAGS) -o main main.cpp ItemType.cpp Sorting.cpp
clean:
	rm -rf main
	rm -rf *.o
