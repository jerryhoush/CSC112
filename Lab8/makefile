CC = g++
CFLAGS = -g -pg -Wall

lab8: main.o database.o
	$(CC) $(CFLAGS) -o lab8 main.o database.o
main.o: main.cpp database.h
	$(CC) $(CFLAGS) -c main.cpp
database.o: database.cpp database.h
	$(CC) $(CFLAGS) -c database.cpp
clean:
	\rm -f *.o main

