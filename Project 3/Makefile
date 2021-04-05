EXEC = run
CC = g++
CFLAGS = -c -Wall

$(EXEC) :main.o util.o heap.o
	$(CC) -o $(EXEC) main.o util.o Graph.o

main.o :main.cpp
	$(CC) $(CFLAGS) main.cpp

util.o :util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

Graph.o :Graph.h Graph.cpp
	$(CC) $(CFLAGS) Graph.cpp

clean :
	rm *.o