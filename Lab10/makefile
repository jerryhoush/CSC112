# Programmer: Jerry Housh	Course: CSC112

# Assignment: lab10	  	Date: 04/08/2014

CC = g++
CFLAGS = -g -pg -Wall

lab10: driver.o pixel.o
	$(CC) $(CFLAGS) -o lab10 driver.cpp pixel.cpp pixel.h
driver.o: driver.cpp pixel.h
	$(CC) $(CFLAGS) -c driver.cpp
pixel.o: pixel.cpp pixel.h
	$(CC) $(CFLAGS) -c pixel.cpp
clean:
	\rm -f *.o main
