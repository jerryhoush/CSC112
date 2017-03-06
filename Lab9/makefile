# Programmer: Jerry Housh	Course: CSC112

# Assignment: lab9	  	Date: 04/04/2014

CC = g++
CFLAGS = -g -pg -Wall

lab9: main.o database.o
	$(CC) $(CFLAGS) -o lab9 main.o database.o
main.o: main.cpp database.h
	$(CC) $(CFLAGS) -c main.cpp
database.o: database.cpp database.h
	$(CC) $(CFLAGS) -c database.cpp
clean:
	\rm -f *.o main

